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

        vector<vector<int>> Graph::getAdjMat(){
            return this->adjMat;
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
            if (g1.getV() != g2.getV()) {
                throw std::runtime_error("Matrices do not have the same number of rows.");
            }
            for (size_t i = 0; i < g1.getV(); ++i) {
                if (g1.getAdjMat()[i].size() != g2.getAdjMat()[i].size()) {
                    throw std::runtime_error("Matrices do not have the same number of columns.");
                }
            }
            int v = g1.getV();
            vector<vector<int>> adj(v);
            for(size_t i = 0; i < v; i++){
                for(size_t j = 0; j < v; j++){
                    adj[i][j] = g1.getAdjMat()[i][j] + g2.getAdjMat()[i][j];
                }
            }
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
            int v = g1.getV();
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
            int v = g.getV();
            vector<vector<int>> adj(v);
            for(size_t i = 0; i < v; i++){
                for(size_t j = 0; j < v; j++){
                    g.getAdjMat()[i][j]++;
                }
            }
        }

        void operator--(Graph& g){
            int v = g.getV();
            vector<vector<int>> adj(v);
            for(size_t i = 0; i < v; i++){
                for(size_t j = 0; j < v; j++){
                    g.getAdjMat()[i][j]--;
                }
            }
        }

        void operator+(Graph& g){
            int v = g.getV();
            vector<vector<int>> adj(v);
            for(size_t i = 0; i < v; i++){
                for(size_t j = 0; j < v; j++){
                    g.getAdjMat()[i][j] *= 1;
                }
            }
        }

        void operator-(Graph& g){
            int v = g.getV();
            vector<vector<int>> adj(v);
            for(size_t i = 0; i < v; i++){
                for(size_t j = 0; j < v; j++){
                    g.getAdjMat()[i][j] *= -1;
                }
            }
        }

        void operator*=(Graph g,int num){
            int v = g.getV();
            for(size_t i = 0; i < v; i++){
                for(size_t j = 0; j < v; j++){
                    g.getAdjMat()[i][j] *= num;
                }
            }
        }

        Graph operator*(Graph g1,Graph g2){
            int v = g1.getV();
            vector<vector<int>> adj;
            for(size_t i = 0; i < v; i++){
                for(size_t j = 0; j < v; j++){
                    adj[i][j] = g1.getAdjMat()[i][j] * g2.getAdjMat()[i][j];
                }
            }
            Graph g3;
            g3.loadGraph(adj);
            return g3;
        }

        ostream& operator<<(std::ostream& os, Graph& g) {
            for (const auto& row : g.getAdjMat()) {
                os << "[";
                for (const auto& elem : row) {
                    os << elem << " ";
                }
                os << "]\n";
            }
            return os;
        }

        void operator/=(Graph& g, int num){
            if (num == 0) {
                throw std::invalid_argument("Division by zero.");
            }
            size_t v = g.getV();
            for(size_t i = 0; i < v; i++){
                for(size_t j = 0; j < v; j++){
                    g.getAdjMat()[i][j] /= num;
                } 
            }
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

        bool operator!=(Graph g1,Graph g2){
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

        }

        bool operator>=(Graph g1,Graph g2){
            
        }

        bool operator<(Graph g1,Graph g2){
            
        }

        bool operator>(Graph g1,Graph g2){
            
        }
        
    };
