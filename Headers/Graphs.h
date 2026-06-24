/**
 * @file Graphs.h
 * @brief Declarations for graph, vertex, edge, and edge node classes.
 *
 * Implements an adjacency list graph supporting adding/deleting vertices and edges,
 * DFS/BFS traversals, Kruskal's, Prim's, and Dijkstra's algorithms.
 */

#ifndef _GRAPHS_H
#define _GRAPHS_H

/**
 * @class Edge
 * @brief Represents an edge in a graph with source, destination, and weight.
 */
class Edge {
    public:
        int source;         ///< Index of the source vertex
        int destination;    ///< Index of the destination vertex
        int weight;         ///< Weight of the edge
};

/**
 * @class Vertex
 * @brief Represents a vertex containing an integer value.
 */
class Vertex {
    public:
        int data;           ///< Data stored in the vertex
};

/**
 * @class EdgeNode
 * @brief Node in the adjacency list representing a connected edge.
 */
class EdgeNode {
    public:
        int destination;         ///< Index of the destination vertex
        int weight;              ///< Weight of the edge
        EdgeNode* nextPtr;       ///< Pointer to the next edge node in the list
        
        /**
         * @brief Constructor for EdgeNode.
         * @param vert The destination vertex index.
         * @param w The weight of the edge.
         */
        EdgeNode(int vert, int w) : destination(vert), weight(w), nextPtr(nullptr) {}
};

/**
 * @class Graph
 * @brief A class representing a graph using an adjacency list.
 */
class Graph {
    private:
        int numVertices;             ///< Number of vertices in the graph
        Vertex* vertexList;          ///< Array of vertices
        EdgeNode** adjacencyList;    ///< Array of adjacency list pointers
        
        /**
         * @brief Helper to delete an edge node from the adjacency list.
         * @param source The source vertex index.
         * @param destination The destination vertex index.
         */
        void deleteEdgeNode(int source, int destination);
        
        /**
         * @brief Helper function for Depth First Search recursion.
         * @param u The current vertex index.
         * @param visited Array tracking visited vertices.
         * @param vertices Array to store DFS path order.
         * @param idx Index counter in the traversal path array.
         */
        void dfsHelper(int u, bool* visited, int* vertices, int& idx);

    public:
        /**
         * @brief Default constructor initializing an empty graph.
         */
        Graph();

        /**
         * @brief Constructor initializing a graph with a fixed number of vertices.
         * @param numVertices The number of vertices.
         */
        Graph(int numVertices);

        /**
         * @brief Destructor that deallocates all vertices and edge lists.
         */
        ~Graph();

        /**
         * @brief Overloaded subscript operator to access a vertex by index.
         * @param idx The index of the vertex.
         * @return Vertex& Reference to the requested vertex.
         */
        Vertex& operator[](int idx);

        /**
         * @brief Adds a new vertex with the given value to the graph.
         * @param val The value of the new vertex.
         * @return int The index of the added vertex, or -1 if full.
         */
        int addVertex(int val);

        /**
         * @brief Deletes a vertex and all its connected edges from the graph.
         * @param source The index of the vertex to delete.
         */
        void deleteVertex(int source);

        /**
         * @brief Adds an edge connecting two vertices.
         * @param source The source vertex index.
         * @param destination The destination vertex index.
         * @param weight The weight of the edge.
         * @param bidirectional True if undirected (adds edges in both directions).
         * @return true if added successfully, false otherwise.
         */
        bool addEdge(int source, int destination, int weight, bool bidirectional);

        /**
         * @brief Deletes an edge connecting two vertices.
         * @param source The source vertex index.
         * @param destination The destination vertex index.
         * @param bidirectional True if undirected (deletes edges in both directions).
         */
        void deleteEdge(int source, int destination, bool bidirectional);

        /**
         * @brief Checks if there is an edge connecting two vertices.
         * @param source The source vertex index.
         * @param destination The destination vertex index.
         * @return true if adjacent, false otherwise.
         */
        bool isAdjacent(int source, int destination);

        /**
         * @brief Displays the adjacency list of the graph to console.
         */
        void displayGraph();

        /**
         * @brief Computes and prints the Minimum Spanning Tree using Kruskal's algorithm.
         */
        void kruskal();

        /**
         * @brief Computes and prints the Minimum Spanning Tree using Prim's algorithm.
         */
        void prim();

        /**
         * @brief Computes and prints the shortest path between two vertices using Dijkstra's algorithm.
         * @param source The starting vertex index.
         * @param destination The ending vertex index.
         */
        void dijkstra(int source, int destination);

        /**
         * @brief Performs a Depth First Search starting from a given vertex.
         * @param source The starting vertex index.
         */
        void depthFirstSearch(int source);

        /**
         * @brief Performs a Breadth First Search starting from a given vertex.
         * @param source The starting vertex index.
         */
        void breadthFirstSearch(int source);

        /**
         * @brief Checks if the graph is directed.
         * @return true if directed, false if undirected.
         */
        bool isDirected();

        /**
         * @brief Checks if the graph contains weighted edges.
         * @return true if weighted, false otherwise.
         */
        bool isWeighted();

        /**
         * @brief Checks if the graph contains negative weight edges.
         * @return true if any edge weight is negative, false otherwise.
         */
        bool hasNegativeWeights();
};

/**
 * @brief Interactive menu function for testing Graph operations.
 * @return int Status code.
 */
int createGraph();

#endif
