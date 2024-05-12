/*
 * Author: Hadar Froimowich.
 * ID: 213118458
 * Email: hadarfro12@gmail.com
 */
#include "Graph.hpp"
#include <iostream>
#include <vector>

using namespace std; 
using namespace ariel;

namespace Algorithms{
    int isConnected(ariel::Graph g);
    int shortestPath(ariel::Graph g,size_t start,size_t end);
    int isContainsCycle(ariel::Graph g);
    int isBipartite(ariel::Graph g);
    int negativeCycle(ariel::Graph g);
    bool hasCycleDFS( vector<vector<int>> graph, size_t u, size_t parent, vector<bool>& visited);
};
