
***
### ex1_2024

ID:213118458

`Introduction`

Welcome to my assignment!
 Graphs are fundamental data structures used to model relationships between objects, making them essential in various domains such as computer science, social networks, transportation networks, and more. In this task I provide implementations of common graph algorithms, facilitating tasks such as finding shortest paths, detecting cycles, checking connectivity, and more.

***

###     Algorithms
The Algorithms module houses a collection of algorithms that operate on graphs. These algorithms leverage the functionality provided by the graph class to perform various graph-related tasks efficiently. From finding shortest paths using Dijkstra's algorithm to detecting cycles with depth-first search (DFS), our Algorithms module offers a comprehensive set of graph algorithms.
graph Class

***

### isConnected

The `isConnected` function determines whether a given graph is connected or not. It employs Breadth-First Search (BFS) algorithm starting from vertex 0. The algorithm marks visited vertices and explores all reachable vertices from the starting vertex. If all vertices are visited during the traversal, the graph is considered connected. If any vertex remains unvisited, it indicates that there are unreachable vertices, and the graph is not connected.

### shortestPath

The `shortestPath` function is a fundamental algorithm used to determine the shortest path between two vertices in a graph. It employs Dijkstra's algorithm, a well-known and widely used method for solving the single-source shortest path problem in graphs with non-negative edge weights.

### hasCycleDFS

The `hasCycleDFS` function is a fundamental component of cycle detection algorithms, employed to determine whether a graph contains a cycle. Leveraging Depth-First Search (DFS) traversal, this function efficiently explores the graph to detect the presence of cycles.


### isContainsCycle

The ``isContainsCycle` function is responsible for determining whether a given graph contains any cycles. It utilizes Depth-First Search (DFS) traversal in conjunction with the hasCycleDFS helper function to efficiently explore the graph and detect cycles.

#### isBipartite

The `isBipartite` function determines whether a given graph is bipartite or not. A bipartite graph is one whose vertices can be divided into two disjoint sets such that no two vertices within the same set are adjacent. This function employs Breadth-First Search (BFS) traversal to color the vertices of the graph in such a way that adjacent vertices receive different colors if the graph is bipart

#### negativeCycle

The `negativeCycle` function serves to identify the presence of negative cycles within a graph. Employing the Bellman-Ford algorithm, it iteratively relaxes the edges in the graph to determine whether there exists a negative cycle. If such a cycle is detected, indicating a situation where the sum of edge weights in a cycle is negative, the function promptly signals the presence of a negative cycle within the graph.

 ***

### Graph
The graph class serves as the backbone of our library, providing a flexible and efficient representation of graphs. It encapsulates functionality for loading graphs from adjacency matrices, performing traversals such as DFS, printing paths, and accessing graph properties like the number of vertices and the adjacency matrix.



 ***

### constructor and Destructor

`graph` Default constructor to initialize an empty graph.
`~graph` Destructor to deallocate memory.

### Graph Operations

`loadGraph` Loads a graph from a given adjacency matrix.
`printGraph` Prints the number of vertices and edges in the graph.

### Traversal

`DFS` Performs Depth-First Search (DFS) starting from a given vertex.
`printPath` Prints the path from a vertex to its parent.

### Accessors

`getV()` Returns the number of vertices in the graph.
`getAdjMat` Returns the adjacency matrix of the graph.


## Operators

### Addition and Subtraction

- **Addition**: `operator+` combines two graphs by adding their corresponding adjacency matrix elements.
- **Subtraction**: `operator-` subtracts one graph from another by subtracting their corresponding adjacency matrix elements.

### Increment and Decrement

- **Increment**: `operator++` increments the adjacency matrix of the graph element-wise.
- **Decrement**: `operator--` decrements the adjacency matrix of the graph element-wise.

### Unary Plus and Minus

- **Unary Plus**: `operator+` applies the unary plus operation to the adjacency matrix of the graph.
- **Unary Minus**: `operator-` applies the unary minus operation to the adjacency matrix of the graph.

### Scalar Multiplication and Division

- **Multiplication Assignment**: `operator*=` multiplies the adjacency matrix of the graph by a scalar value.
- **Division Assignment**: `operator/=` divides the adjacency matrix of the graph by a scalar value.

### Multiplication of Graphs

- **Multiplication**: `operator*` multiplies two graphs by performing matrix multiplication on their adjacency matrices.

### Output Stream Operator

- **Output Stream Operator**: `operator<<` overloads the output stream operator to allow printing the graph's adjacency matrix.

### Comparison Operators

- **Equal**: `operator==` compares two graphs to determine if they have equal adjacency matrices.
- **Not Equal**: `operator!=` compares two graphs to determine if they have different adjacency matrices.
- **Greater Than**: `operator>` compares two graphs based on their adjacency matrices' lexicographical order.
- **Greater Than or Equal To**: `operator>=` compares two graphs based on their adjacency matrices' lexicographical order.
- **Less Than**: `operator<` compares two graphs based on their adjacency matrices' lexicographical order.
- **Less Than or Equal To**: `operator<=` compares two graphs based on their adjacency matrices' lexicographical order.

These operators allow for efficient graph manipulation and comparison. For detailed usage instructions, refer to the documentation or code comments.

