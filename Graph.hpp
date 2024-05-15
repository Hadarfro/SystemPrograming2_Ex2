/*
 * Author: Hadar Froimowich.
 * ID: 213118458
 * Email: hadarfro12@gmail.com
 */
#include <iostream>
#include <vector>
#ifndef GRAPH_HPP
#define GRAPH_HPP

using namespace std; 
//enum class State { UNDISCOVERED, DISCOVERED, PROCESSED };
namespace ariel{
    class Graph{
        private:
            int V; // Number of vertices
            vector<vector<int>> adjMat; // Adjacency matrix that represent the edges of the graph

        public:
            
            Graph();
            ~Graph();
            int printPath(vector<int>& parent, unsigned int u);
            void loadGraph(vector<vector<int>> g);
            void printGraph();
            void DFS(unsigned int v, bool visited[]);
            int getV();
            vector<vector<int>> getAdjMat();
            friend Graph operator+(Graph g1,Graph g2);
            friend void operator++(Graph& g);
            friend Graph operator-(Graph g1,Graph g2);
            friend void operator--(Graph& g);
            friend void operator+(Graph& g);
            friend void operator-(Graph& g);
            friend void operator*=(Graph g,int num);
            friend Graph operator*(Graph g1,Graph g2);
            friend ostream& operator<<(std::ostream& os, Graph& g);
            friend void operator/=(Graph& g,int num);
            friend bool operator==(Graph& g1,Graph& g2);
            friend bool operator!=(Graph g1,Graph g2);
            friend bool operator>(Graph g1,Graph g2);
            friend bool operator>=(Graph g1,Graph g2);
            friend bool operator<=(Graph g1,Graph g2);
            friend bool operator<(Graph g1,Graph g2);
            
    };
};
#endif // GRAPH_HPP