#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;
using namespace doctest;

TEST_CASE("Test graph addition with larger graphs")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    g1.loadGraph(graph1);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}};
    g2.loadGraph(graph2);
    ariel::Graph g3 = g1 + g2;
    CHECK(g3.printGraph() == "[10, 10, 10][10, 10, 10][10, 10, 10]");
}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph2);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}};
    CHECK(g4.printGraph() == "[1, 0, 2][1, 3, 1][1, 0, 2]");

    ariel::Graph g5;
    vector<vector<int>> graph1 = {
        {2, 3, 4},
        {5, 6, 7},
        {8, 9, 10}};
    g5.loadGraph(graph1);
    g5 *= 2;
    CHECK(g5.printGraph() == "[4, 6, 8][10, 12, 14][16, 18, 20]");
}

TEST_CASE("Invalid operations"){
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    CHECK_THROWS(g2.loadGraph(weightedGraph));
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
    ariel::Graph graph1;
    vector<vector<int>> graph7 = {
        {1, 2, -1},
        {-2, -4, 2},
        {1, 2, -1}};
    graph1.loadGraph(graph7);
    ariel::Graph g8;
    vector<vector<int>> graph8 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    g8.loadGraph(graph8);
    Graph graph5 = g8 * graph1;
    CHECK(graph5.printGraph() == "[0, 0, 0][0, 0, 0][0, 0, 0]");
}

TEST_CASE("Test equality and inequality operators") {
    ariel::Graph g1, g2, g3;
    vector<vector<int>> graph1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<vector<int>> graph2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<vector<int>> graph3 = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);
    g3.loadGraph(graph3);

    CHECK(g1 == g2);
    CHECK(g1 != g3);
}

TEST_CASE("Test comparison operators") {
    ariel::Graph g1, g2;
    vector<vector<int>> graph1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<vector<int>> graph2 = {
        {2, 3, 4},
        {5, 6, 7},
        {8, 9, 10}
    };
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    CHECK(g1 < g2);
    CHECK(g2 > g1);
    CHECK(g1 <= g2);
    CHECK(g2 >= g1);
}

TEST_CASE("Test chained operations") {
    ariel::Graph g1, g2, g3;
    vector<vector<int>> graph1 = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    vector<vector<int>> graph2 = {
        {2, 2, 2},
        {2, 2, 2},
        {2, 2, 2}
    };
    vector<vector<int>> graph3 = {
        {3, 3, 3},
        {3, 3, 3},
        {3, 3, 3}
    };
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);
    g3.loadGraph(graph3);

    // Graph result = (g1 + g2);// * g3
    // vector<vector<int>> expectedResult = {
    //     {9, 9, 9},
    //     {9, 9, 9},
    //     {9, 9, 9}
    // };
    // CHECK(result.printGraph() == "[9, 9, 9]\n[9, 9, 9]\n[9, 9, 9]\n");
}


TEST_CASE("Test increment and decrement operators edge cases") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    g1.loadGraph(graph);

    ++g1;
    vector<vector<int>> expectedIncrementedGraph = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    CHECK(g1.printGraph() == "[1, 1, 1]\n[1, 1, 1]\n[1, 1, 1]\n");

    --g1;
    CHECK(g1.printGraph() == "[0, 0, 0][0, 0, 0][0, 0,0 ]");
}