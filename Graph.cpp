/*
 * Author: Hadar Froimowich.
 * ID: 213118458
 * Email: hadarfro12@gmail.com
 */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include "Graph.hpp"

using namespace std;

    namespace ariel{
        Graph::Graph(){//defult constractor
            this->V = 0;

        }

        Graph::Graph(const std::vector<std::vector<int>>& adjMatrix)
    : V(adjMatrix.size()), adjMat(adjMatrix) {

    }

        // Destructor to deallocate memory
        Graph::~Graph() {
            this->adjMat.clear();
        }

        // Depth-First Search (DFS)
        void Graph::DFS(unsigned int v, bool visited[]) {
            visited[v] = true;
            for (unsigned int i = 0; i < V; ++i) {
                if (this->adjMat[v][i] && !visited[i]) {
                    DFS(i, visited);
                }
            }
        }

        int Graph::printPath(vector<int>& parent, unsigned int u) {
            vector<int> path;
            unsigned int v = u;
            int t = (int)u;

            // Construct the cycle path
            do {
                path.push_back((int)v);
                t = parent[v];
                v = (unsigned int)t;
            } while (v != u && t != u);

            // Print the cycle
            cout << "Cycle: ";
            for (unsigned int i = path.size() - 1; i >= 0; --i) {
                cout << path[i] << " ";
            }
            cout << std::endl;
            return 1;
        }

        int Graph::getV(){
            return this->V;
        }

        const vector<vector<int>>& Graph::getAdjMat() const {
            return adjMat;  // Const reference for read-only access
        }

        vector<vector<int>>& Graph::getAdjMat(){
            return adjMat;  // Non-const reference for modification
        }

        void Graph::loadGraph(vector<vector<int>> g) {
            // Reinitialize the current graph object with the new graph data
            if(g.size() != g[0].size()||g.size() == 0){
                throw std::invalid_argument("Invalid graph: The graph is not a square matrix or is empty.");
            }
            this->V = g.size();
            this->adjMat = g;
        }

        void Graph::printGraph(){//print the number of vertex and edges
            // Print the neighbor matrix
            int count = 0;
            for (unsigned int i = 0; i < this->V; ++i) {
                for (unsigned int j = 0; j < this->V; ++j) {
                    if(this->adjMat[i][j] != 0){
                        count++;
                    }
                }
            }
            cout << "Graph with " << this->V << " vertices and " << count << " edges" << endl;
        }

        Graph operator+(Graph g1,Graph g2){
            // Check if the number of rows (vertices) is the same
            if (g1.getV() != g2.getV()) {
                throw std::runtime_error("Matrices do not have the same number of rows.");
            }

            // Get adjacency matrices for both graphs
            const auto& adjMat1 = g1.getAdjMat();
            const auto& adjMat2 = g2.getAdjMat();

            // Check if the number of columns is the same for each row
            for (size_t i = 0; i < adjMat1.size(); ++i) {
                if (adjMat1[i].size() != adjMat2[i].size()) {
                    throw std::runtime_error("Matrices do not have the same number of columns.");
                }
            }

            // Initialize the result adjacency matrix with the correct size
            size_t v = (size_t)g1.getV();
            vector<vector<int>> adj(v,vector<int>(v, 0));

            // Perform the addition of the adjacency matrices
            for (size_t i = 0; i < v; ++i) {
                for (size_t j = 0; j < v; ++j) {
                    adj[i][j] = adjMat1[i][j] + adjMat2[i][j];
                }
            }

            // Create the resulting graph and load the computed adjacency matrix
            Graph g3;
            g3.loadGraph(adj);
            return g3;
        }

        Graph operator-(Graph g1,Graph g2){
            if (g1.getV() != g2.getV()) {
                throw std::runtime_error("Matrices do not have the same number of rows.");
            }
            for (size_t i = 0; i < g1.getV(); ++i) {
                if (g1.getAdjMat()[i].size() != g2.getAdjMat()[i].size()) {
                    throw std::runtime_error("Matrices do not have the same number of columns.");
                }
            }
            size_t v = (size_t)g1.getV();
            vector<vector<int>> adj(v);
            for(size_t i = 0; i < v; i++){
                for(size_t j = 0; j < v; j++){
                    adj[i][j] = g1.getAdjMat()[i][j] - g2.getAdjMat()[i][j];
                }
            }
            Graph g3;
            g3.loadGraph(adj);
            return g3;
        }

        void operator++(Graph& g){
            size_t v = (size_t)g.getV();
            vector<vector<int>> adj(v);
            for(size_t i = 0; i < v; i++){
                for(size_t j = 0; j < v; j++){
                    g.getAdjMat()[i][j]++;
                }
            }
        }

        void operator--(Graph& g){
            size_t v = (size_t)g.getV();
            vector<vector<int>> adj(v);
            for(size_t i = 0; i < v; i++){
                for(size_t j = 0; j < v; j++){
                    g.getAdjMat()[i][j]--;
                }
            }
        }

        void operator+(Graph& g){
            size_t v = (size_t)g.getV();
            vector<vector<int>> adj(v);
            for(size_t i = 0; i < v; i++){
                for(size_t j = 0; j < v; j++){
                    g.getAdjMat()[i][j] *= 1;
                }
            }
        }

        void operator-(Graph& g){
            size_t v = (size_t)g.getV();
            vector<vector<int>> adj(v);
            for(size_t i = 0; i < v; i++){
                for(size_t j = 0; j < v; j++){
                    g.getAdjMat()[i][j] *= -1;
                }
            }
        }

        void operator*=(Graph& g,int num){
            auto& adjMat = g.getAdjMat();  // Get a reference to the adjacency matrix
            int v = g.getV();
            for (size_t i = 0; i < v; ++i) {
                for (size_t j = 0; j < v; ++j) {
                    adjMat[i][j] *= num;
                }
            }
            g.getAdjMat() = adjMat;
        }


        Graph operator*(Graph g1,Graph g2){
            if (g1.getV() != g2.getV()) {
                throw std::runtime_error("Matrices do not have the same number of rows.");
            }
            for (size_t i = 0; i < g1.getV(); ++i) {
                if (g1.getAdjMat()[i].size() != g2.getAdjMat()[i].size()) {
                    throw std::runtime_error("Matrices do not have the same number of columns.");
                }
            }
            size_t v = static_cast<size_t>(g1.getV());
            vector<vector<int>> result(v,vector<int>(v, 0));  // Initialize result matrix

            for (size_t i = 0; i < v; ++i){
                for (size_t j = 0; j < v; ++j){
                    for (size_t k = 0; k < v; ++k){
                        result[i][j] += g1.getAdjMat()[i][k] * g2.getAdjMat()[k][j];
                    }
                }
            }
            return Graph(result);
        }

        string operator<<(std::ostream& os, Graph& g) {
            string ans;
            for (const auto& row : g.getAdjMat()) {
                ans += "[";
                for (const auto& elem : row) {
                    ans += elem;
                    ans += " ";
                }
                ans += "]\n";
            }
            return ans;
        }

        void operator/=(Graph& g, int num){//fix!!!!!!!!!!!!!
            if (num == 0) {
                throw std::invalid_argument("Division by zero.");
            }
            size_t v = (size_t)g.getV();
            // Get a reference to the adjacency matrix
            vector<vector<int>>& adjMat = g.getAdjMat();

            for (size_t i = 0; i < v; ++i) {
                for (size_t j = 0; j < v; ++j) {
                    adjMat[i][j] /= num;
                }
            }
            g.getAdjMat() = adjMat;
        }

        bool operator==(Graph& g1,Graph& g2){
            if(g1.getV()==g2.getV()){
                for(size_t i = 0; i<g1.getV();i++){
                   for(size_t j = 0; j < g1.getV();j++){
                        if(g1.getAdjMat()[i][j] != g2.getAdjMat()[i][j]){
                            return false;
                        }
                    } 
                }
            }
            else{
                return false;
            }
            return true;
        }

        bool operator!=(Graph& g1,Graph& g2){
            if(g1.getV()==g2.getV()){
                for(size_t i = 0; i<g1.getV();i++){
                   for(size_t j = 0; j < g1.getV();j++){
                        if(g1.getAdjMat()[i][j] != g2.getAdjMat()[i][j]){
                            return true;
                        }
                    } 
                }
            }
            else{
                return true;
            }
            return false;
        }

        bool operator<=(Graph g1,Graph g2){
            return true;
        }

        bool operator>=(Graph g1,Graph g2){
            return true;
        }

        bool operator<(const Graph& g1,const Graph& g2){
            size_t v = (size_t)max(g1.getV(),g2.getV());
            for (size_t i = 0; i < v; ++i) {
                for (size_t j = 0; j < v; ++j) {
                    if(g1.adjMat()[i][j]==0 && g2.adjMat()[i][j]!=0){
                        return false;
                    }
                }
            }
            return true;
        }

        bool operator>(Graph g1,Graph g2){
            return true;
        }
        
    };
