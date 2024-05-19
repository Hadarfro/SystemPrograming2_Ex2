/*
 * Demo program for Exercise 3.
 * Author: Benjamin Saldman.
 */

#include "Graph.hpp"
#include "Algorithms.hpp"
using namespace ariel;
using namespace Algorithms;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{
    // Initializing a simple 3x3 connected graph
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);
    cout << g1;
    cout << endl; // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]

    // Initializing a 3x3 weighted connected graph
    Graph g2;
    vector<vector<int>> weightedGraph1 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph1);
    cout << g2;
    cout << endl; // Should print the matrix of the graph: [0, 1, 1], [1, 0, 2], [1, 2, 0]

    // Adding two graphs
    Graph g3 = g1 + g2;
    cout << g3;
    cout << endl; // Should print the matrix of the graph: [0, 2, 1], [2, 0, 3], [1, 3, 0]

    // Scalar multiplication
    g1 *= -2;
    cout << g1;
    cout << endl; // Should print the matrix of the graph: [0, -2, 0], [-2, 0, -2], [0, -2, 0]

    g1 /= -2;
    cout << g1;
    cout << endl; // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]

    // Multiplying two graphs element-wise
    Graph g4 = g1 * g2;
    cout << g4;
    cout << endl; // Should print the multiplication of the matrices: [0, 1, 0], [1, 0, 2], [0, 2, 0]

    // Comparison
    bool flag = g1 < g2;
    cout << boolalpha << flag << endl; // true

    // Initializing a more complex 5x5 connected graph
    Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    cout << g5;
    cout << endl; // Should print the 5x5 graph matrix

 vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    ariel::Graph graph5;
    graph5.loadGraph(graph3); // Load the graph to the object.
    try
    {
        Graph g6 = graph5 * g1; // Multiply the two graphs together.
    }
    catch (const std::runtime_error &e)
    {
        cout << e.what() << endl; // Should print "The number of columns in the first matrix must be equal to the number of rows in the second matrix."
    }

    // Additional complex graph for operations
    vector<vector<int>> graph4 = {
        {0, 3, 1, 0, 2},
        {3, 0, 4, 1, 0},
        {1, 4, 0, 5, 1},
        {0, 1, 5, 0, 3},
        {2, 0, 1, 3, 0}};
    Graph g7;
    g7.loadGraph(graph4);
    cout << g7;
    cout << endl; // Should print the complex 5x5 graph matrix

    // Adding complex graphs
    Graph g8 = g5 + g7;
    cout << g8; 
    cout << endl; // Should print the addition of the two 5x5 graph matrices

    // Scalar multiplication of complex graph
    g7 *= 3;
    cout << g7;
    cout << endl; // Should print the complex graph matrix scaled by 3

    return 0;
}
