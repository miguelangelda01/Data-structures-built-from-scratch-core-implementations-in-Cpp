/**
 * @file Graphs.cpp
 * @brief Implementation of Vertex, Edge, EdgeNode, and Graph classes.
 */

#include <iostream>
#include "../Headers/Config.h"
#include "../Headers/Menus.h"
#include "../Headers/Graphs.h"

using namespace std;

/**
 * @brief Helper to delete an edge node from the adjacency list.
 * @param source The source vertex index.
 * @param destination The destination vertex index.
 */
void Graph::deleteEdgeNode(int source, int destination){
    EdgeNode* current = adjacencyList[source];
    EdgeNode* previous = nullptr;

    while(current != nullptr && current->destination != destination){
        previous = current;
        current = current->nextPtr;
    }
    if(current != nullptr){
        if(previous == nullptr){
            adjacencyList[source] = current->nextPtr;
        }else{
            previous->nextPtr = current->nextPtr;
        }
        delete current;
    }
}

/**
 * @brief Default constructor for Graph.
 */
Graph::Graph(): numVertices(0), vertexList(nullptr), adjacencyList(nullptr){}

/**
 * @brief Constructor with number of vertices.
 * @param numVertices Total vertices.
 */
Graph::Graph(int numVertices) : numVertices(numVertices) {
    vertexList = new Vertex[numVertices];
    adjacencyList = new EdgeNode*[numVertices];
    for (int i = 0; i < numVertices; i++) {
        vertexList[i].data = 0;
        adjacencyList[i] = nullptr;
    }
}

/**
 * @brief Destructor.
 */
Graph::~Graph(){
    for(int i = 0; i < numVertices; i++){
        EdgeNode* current = adjacencyList[i];
        while(current != nullptr){
            EdgeNode* temp = current;
            current = current->nextPtr;
            delete temp;
        }
    }
    delete[] adjacencyList;
    delete[] vertexList;
}

/**
 * @brief Index operator to access vertex.
 * @param idx Index of vertex.
 * @return Vertex& The vertex object.
 */
Vertex& Graph::operator[](int idx){
    if(idx < 0 || idx >= numVertices){
        cout << "\n\nError: this vertex does not exist\n\n";
        system("pause");
    }
    return vertexList[idx];
}

/**
 * @brief Adds a vertex to the graph.
 * @param val The data value of the vertex.
 * @return int The index of the added vertex.
 */
int Graph::addVertex(int val){
    int newSize = numVertices + 1;

    Vertex* newVertexList = new Vertex[newSize];
    EdgeNode** newAdjacencyList = new EdgeNode*[newSize];

    for(int i = 0; i < numVertices; i++){
        newVertexList[i] = vertexList[i];
        newAdjacencyList[i] = adjacencyList[i];
    }

    newVertexList[numVertices].data = val;
    newAdjacencyList[numVertices] = nullptr;

    delete[] vertexList;
    delete[] adjacencyList;

    vertexList = newVertexList;
    adjacencyList = newAdjacencyList;

    int idx = numVertices;
    numVertices++;

    return idx;
}

/**
 * @brief Deletes a vertex by index.
 * @param source Vertex index to delete.
 */
void Graph::deleteVertex(int source){
    if(numVertices == 0 || source < 0 || source >= numVertices){
        cout << "\nNo vertices left to delete\n";
        system("pause");
        return;
    }

    int newSize = numVertices - 1;

    for(int i = 0; i < numVertices; i++){
        deleteEdge(source, i, true);
    }

    if (newSize == 0) {
        delete[] vertexList;
        delete[] adjacencyList;
        vertexList = nullptr;
        adjacencyList = nullptr;
        numVertices = 0;
        return;
    }

    Vertex* newVertexList = new Vertex[newSize];
    EdgeNode** newAdjacencyList = new EdgeNode*[newSize];

    int j = 0;
    for(int i = 0; i < numVertices; i++){
        if(i != source){
            newVertexList[j] = vertexList[i];
            newAdjacencyList[j] = adjacencyList[i];
            j++;
        }
    }

    for(int i = 0; i < newSize; i++){
        EdgeNode* current = newAdjacencyList[i];
        while(current != nullptr){
            if(current->destination > source){
                current->destination--;
            }
            current = current->nextPtr;
        }
    }

    delete[] vertexList;
    delete[] adjacencyList;

    vertexList = newVertexList;
    adjacencyList = newAdjacencyList;
    numVertices = newSize;
    cout << "\nVertex " << source << " deleted successfully.\n";
}

/**
 * @brief Connects two vertices with an edge.
 * @param source Origin vertex index.
 * @param destination Target vertex index.
 * @param weight Edge weight.
 * @param bidirectional True if undirected.
 * @return true if added, false otherwise.
 */
bool Graph::addEdge(int source, int destination, int weight, bool bidirectional){
    if(source < 0 || source >= numVertices || destination < 0 || destination >= numVertices){
        cout << "\nError: vertex not found.\n\n";
        return false;
    }

    EdgeNode* current = adjacencyList[source];
    while(current != nullptr){
        if(current->destination == destination){
            cout << "\n\nError: this connection already exists\n\n";
            return false;
        }
        current = current->nextPtr;
    }

    if(bidirectional){
        current = adjacencyList[destination];
        while(current != nullptr){
            if(current->destination == source){
                cout << "\n\nError: this connection already exists\n\n";
                return false;
            }
            current = current->nextPtr;
        }
    }
    
    EdgeNode* newEdge = new EdgeNode(destination, weight);
    newEdge->nextPtr = adjacencyList[source];
    adjacencyList[source] = newEdge;

    if(bidirectional && source != destination){
        EdgeNode* newMirrorEdge = new EdgeNode(source, weight);
        newMirrorEdge->nextPtr = adjacencyList[destination];
        adjacencyList[destination] = newMirrorEdge;
    }
    return true;
}

/**
 * @brief Deletes an edge connecting two vertices.
 * @param source Origin vertex index.
 * @param destination Target vertex index.
 * @param bidirectional True if undirected.
 */
void Graph::deleteEdge(int source, int destination, bool bidirectional){
    if(source < 0 || source >= numVertices || destination < 0 || destination >= numVertices){
        cout << "\nError: vertex not found.\n\n";
        system("pause");
        return;
    }

    deleteEdgeNode(source, destination);
    if(bidirectional){
        deleteEdgeNode(destination, source);
    }
}

/**
 * @brief Checks adjacency between two vertices.
 * @param source Origin vertex index.
 * @param destination Target vertex index.
 * @return true if adjacent, false otherwise.
 */
bool Graph::isAdjacent(int source, int destination) {
    if (source < 0 || source >= numVertices || destination < 0 || destination >= numVertices){
        cout << "\nError: vertex not found.\n\n";
        return false;
    }

    EdgeNode* current = adjacencyList[source];
    while (current != nullptr) {
        if (current->destination == destination){
            return true;
        }
        current = current->nextPtr;
    }
    return false;
}

/**
 * @brief Displays the adjacency list of the graph.
 */
void Graph::displayGraph(){
    if(numVertices == 0){
        cout << "\nError: no vertices to display\n";
        return;
    }
    for(int i = 0; i < numVertices; i++){
        cout << "[Idx: " << i << "| val: " << vertexList[i].data << "]";
        EdgeNode* current = adjacencyList[i];

        if(current == nullptr){
            cout << " -> /";
        }
        while(current != nullptr){
            cout << " -> [Idx: " << current->destination << "| Val: " << vertexList[current->destination].data;
            if(current->weight != 0){
                cout << "| W:" << current->weight << "]";
            }else{
                cout << "]";
            }
            current = current->nextPtr;
        }
        cout << "\n";
    }
}

/**
 * @brief Computes Minimum Spanning Tree using Kruskal's algorithm.
 */
void Graph::kruskal(){
    if(numVertices == 0){
        cout << "\nNo vertices available to apply Kruskal's algorithm";
        system("pause");
        return;
    }

    int totalEdges = 0;
    for(int i = 0; i < numVertices; i++){
        EdgeNode* current = adjacencyList[i];
        while(current != nullptr){
            if(i < current->destination){
                totalEdges++;
            }
            current = current->nextPtr;
        }
    }

    if(totalEdges == 0){
        cout << "\nNo edges exist in the graph";
        system("pause");
        return;
    }

    Edge* edgeList = new Edge[totalEdges];
    int edgeIdx = 0;
    for(int i = 0; i < numVertices; i++){
        EdgeNode* current = adjacencyList[i];
        while(current != nullptr){
            if(i < current->destination){
                edgeList[edgeIdx].source = i;
                edgeList[edgeIdx].destination = current->destination;
                edgeList[edgeIdx].weight = current->weight;
                edgeIdx++;
            }
            current = current->nextPtr;
        }
    }

    for(int i = 0; i < totalEdges - 1; i++){
        for(int j = 0; j < totalEdges - i - 1; j++){
            if(edgeList[j].weight > edgeList[j + 1].weight){
                Edge temp = edgeList[j];
                edgeList[j] = edgeList[j + 1];
                edgeList[j + 1] = temp;
            }
        }
    }

    int *parent = new int[numVertices];
    for(int i = 0; i < numVertices; i++){
        parent[i] = i;
    }

    Graph* minSpanningTree = new Graph(numVertices);

    for(int i = 0; i < numVertices; i++){
        minSpanningTree->vertexList[i] = vertexList[i];
    }

    int kruskalEdges = 0;
    for(int i = 0; i < totalEdges; i++){
        int u = edgeList[i].source;
        int v = edgeList[i].destination;
        int w = edgeList[i].weight;

        int rootU = u;
        while(rootU != parent[rootU]){
            rootU = parent[rootU];
        }

        int rootV = v;
        while(rootV != parent[rootV]){
            rootV = parent[rootV];
        }

        if(rootU != rootV){
            minSpanningTree->addEdge(u, v, w, true);
            parent[rootU] = rootV;
            kruskalEdges++;

            if(kruskalEdges == numVertices - 1){
                i = totalEdges;
            }
        }
    }
    delete[] edgeList;
    delete[] parent;

    minSpanningTree->displayGraph();

    delete minSpanningTree;
}

/**
 * @brief Computes Minimum Spanning Tree using Prim's algorithm.
 */
void Graph::prim(){
    if(numVertices == 0){
        cout << "\nNo vertices available to apply Prim's algorithm";
        system("pause");
        return;
    }

    const int INFINITY_VAL = 99999999;

    int* minCost = new int[numVertices];
    int* neighbor = new int[numVertices];
    bool* visited = new bool[numVertices];

    for(int i = 0; i < numVertices; i++){
        minCost[i] = INFINITY_VAL;
        neighbor[i] = -1;
        visited[i] = false;
    }

    minCost[0] = 0;
    Graph* minSpanningTree = new Graph(numVertices);
    for(int i = 0; i < numVertices; i++){
        minSpanningTree->vertexList[i] = vertexList[i];
    }

    for(int i = 0; i < numVertices; i++){
        int lowestCost = INFINITY_VAL;
        int k = -1;

        for(int j = 0; j < numVertices; j++){
            if(!visited[j] && minCost[j] < lowestCost){
                lowestCost = minCost[j];
                k = j;
            }
        }

        if(k == -1){
            i = numVertices;
        }

        visited[k] = true;

        if(neighbor[k] != -1){
            minSpanningTree->addEdge(k, neighbor[k], lowestCost, true);
        }

        EdgeNode* current = adjacencyList[k];
        while(current != nullptr){
            int j = current->destination;
            int weightVal = current->weight;

            if(!visited[j] && weightVal < minCost[j]){
                minCost[j] = weightVal;
                neighbor[j] = k;
            }
            current = current->nextPtr;
        }
    }
    minSpanningTree->displayGraph();

    delete[] minCost;
    delete[] neighbor;
    delete[] visited;
    delete minSpanningTree;
}

/**
 * @brief Computes shortest paths using Dijkstra's algorithm.
 * @param source Origin vertex index.
 * @param destination Target vertex index.
 */
void Graph::dijkstra(int source, int destination){
    if(numVertices == 0 || source < 0 || source >= numVertices || destination < 0 || destination >= numVertices){
        cout << "\nNo vertices available to apply Dijkstra's algorithm";
        return;
    }

    const int INFINITY_VAL = 99999999;

    int* cost = new int[numVertices];
    int* predecessor = new int[numVertices];
    bool* visited = new bool[numVertices];

    for(int i = 0; i < numVertices; i++){
        cost[i] = INFINITY_VAL;
        predecessor[i] = -1;
        visited[i] = false;
    }

    cost[source] = 0;
    for(int i = 0; i < numVertices; i++){
        int minCostVal = INFINITY_VAL;
        int u = -1;

        for(int j = 0; j < numVertices; j++){
            if(!visited[j] && cost[j] < minCostVal){
                minCostVal = cost[j];
                u = j;
            }
        }

        if(u == -1){
            i = numVertices;
        }
        visited[u] = true;

        if(u == destination){
            i = numVertices;
        }else{
            EdgeNode* current = adjacencyList[u];
            while(current != nullptr){
                int v = current->destination;
                int weightVal = current->weight;

                if(!visited[v] && cost[u] + weightVal < cost[v]){
                    cost[v] = cost[u] + weightVal;
                    predecessor[v] = u;
                }
                current = current->nextPtr;
            }
        }
    }

    if(cost[destination] == INFINITY_VAL){
        cout << "No path exists to vertex: " << destination << " from " << source << "\n";
    }else{
        cout << "\nOptimal route: ";
        
        int* tempRoute = new int[numVertices];
        int steps = 0;

        int current = destination;
        while(current != -1){
            tempRoute[steps] = current;
            steps++;
            current = predecessor[current];
        }

        for(int i = steps - 1; i >= 0; i--){
            cout << vertexList[tempRoute[i]].data;
            if(i > 0){
                cout << " -> ";
            }
        }
        cout << "\nTotal weight: " << cost[destination] << "\n";
        delete[] tempRoute;
    }

    delete[] cost;
    delete[] predecessor;
    delete[] visited;
}

/**
 * @brief Depth-first search traversal wrapper.
 * @param source Origin vertex index.
 */
void Graph::depthFirstSearch(int source){
    if(numVertices == 0 || source < 0 || source >= numVertices){
        cout << "\nNo vertices available to apply depth-first search";
        return;
    }

    int* vertices = new int[numVertices];
    bool* visited = new bool[numVertices];
    for(int i = 0; i < numVertices; i++){
        vertices[i] = -1;
        visited[i] = false;
    }
    
    int idx = 0;
    dfsHelper(source, visited, vertices, idx);

    for(int i = 0; i < idx; i++){
        cout << vertexList[vertices[i]].data;
        if(i < idx - 1){
            cout << " -> ";
        }
    }

    if(idx < numVertices){
        cout << " | ";
        bool first = true;
        for(int i = 0; i < numVertices; i++){
            if(!visited[i]){
                if(!first){
                    cout << ",";
                }
                cout << vertexList[i].data;
                first = false;
            }
        }
    }

    cout << "\n\n";

    delete[] vertices;
    delete[] visited;
}

/**
 * @brief Helper for Depth-first search traversal.
 * @param u Subtree vertex index.
 * @param visited Tracker array.
 * @param vertices Traversal path output.
 * @param idx Traversal path size reference.
 */
void Graph::dfsHelper(int u, bool* visited, int* vertices, int& idx){
    if(visited[u]){
        return;
    }

    visited[u] = true;
    vertices[idx] = u;
    idx++;

    EdgeNode* current = adjacencyList[u];
    while(current != nullptr){
        dfsHelper(current->destination, visited, vertices, idx);
        current = current->nextPtr;    
    }
}

/**
 * @brief Breadth-first search traversal wrapper.
 * @param source Origin vertex index.
 */
void Graph::breadthFirstSearch(int source){
    if(numVertices == 0 || source < 0 || source >= numVertices){
        cout << "\nNo vertices available to apply breadth-first search";
        return;
    }

    int* vertices = new int[numVertices];
    bool* visited = new bool[numVertices];
    for(int i = 0; i < numVertices; i++){
        vertices[i] = -1;
        visited[i] = false;
    }

    vertices[0] = source;
    visited[source] = true;
    int j = 1;
    int i = 0;
    while(i < j){
        int idx = vertices[i];
        i++;
        EdgeNode* current = adjacencyList[idx];
        while(current != nullptr){
            if(!visited[current->destination]){
                visited[current->destination] = true;
                vertices[j] = current->destination;
                j++;
            }
            current = current->nextPtr;
        }
    }

    for(int i = 0; i < j; i++){
        cout << vertexList[vertices[i]].data;
        if(i < j - 1){
            cout << " -> ";
        }
    }

    if(j < numVertices){
        cout << " | ";
        bool first = true;
        for(int i = 0; i < numVertices; i++){
            if(!visited[i]){
                if(!first){
                    cout << ",";
                }
                cout << vertexList[i].data;
                first = false;
            }
        }
    }

    cout << "\n\n";

    delete[] vertices;
    delete[] visited;
}

/**
 * @brief Checks if the graph is directed.
 * @return true if directed, false if undirected.
 */
bool Graph::isDirected() {
    for (int i = 0; i < numVertices; i++) {
        EdgeNode* current = adjacencyList[i];
        while (current != nullptr) {
            int dest = current->destination;
            int weightVal = current->weight;

            EdgeNode* returnEdge = adjacencyList[dest];
            bool symmetric = false;
            bool found = false;
            while (returnEdge != nullptr && !found) {
                if (returnEdge->destination == i && returnEdge->weight == weightVal) {
                    symmetric = true;
                    found = true;
                }
                returnEdge = returnEdge->nextPtr;
            }
            if (!symmetric) {
                return true; 
            }
            current = current->nextPtr;
        }
    }
    return false; 
}

/**
 * @brief Checks if every edge in the graph is weighted.
 * @return true if weighted, false otherwise.
 */
bool Graph::isWeighted() {
    for (int i = 0; i < numVertices; i++) {
        EdgeNode* current = adjacencyList[i];
        while (current != nullptr) {
            if (current->weight == 0) {
                return false; 
            }
            current = current->nextPtr;
        }
    }
    return true; 
}

/**
 * @brief Checks if the graph contains negative weights.
 * @return true if negative weights exist, false otherwise.
 */
bool Graph::hasNegativeWeights() {
    for (int i = 0; i < numVertices; i++) {
        EdgeNode* current = adjacencyList[i];
        while (current != nullptr) {
            if (current->weight <= 0) {
                return true; 
            }
            current = current->nextPtr;
        }
    }
    return false;
}

/**
 * @brief Interactive driver function for Graph testing.
 * @return int Status code.
 */
int createGraph(){
    int option, t;
    Graph myGraph;
    do{
        graphMenu();
        cin >> option;
        if(!validateMenuInput(cin, 16, option)){
            system("pause");
            option = 0;
        }

        switch(option){
            case 1: {
                int value, idx;
                cout << "\nEnter the vertex value: ";
                cin >> value;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                idx = myGraph.addVertex(value);
                cout << "The vertex was placed at position: " << idx << "\n\n";
                system("pause");
                break;
            }
            case 2: {
                int source;
                cout << "Enter the position of the vertex to delete: ";
                cin >> source;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                myGraph.deleteVertex(source);
                system("pause");
                break;
            }
            case 3: {
                int source, destination, weight;
                char answer;
                bool bidirectional = true;
                cout << "\n              [CREATE EDGE]\n";
                cout << "Enter the source vertex position: ";
                cin >> source;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                cout << "Enter the destination vertex position: ";
                cin >> destination;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                cout << "Enter the weight (use 0 for unweighted): ";
                cin >> weight;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                cout << "Is the connection directed (Y/N): ";
                cin >> answer;

                if(answer == 'y' || answer == 'Y'){
                    bidirectional = false;
                }else if(answer != 'n' && answer != 'N'){
                    cout << "Option not found";
                    cin.clear();
                    while (getchar() != '\n'); 
                    break;
                }
                if(myGraph.addEdge(source, destination, weight, bidirectional)){
                    cout << "\n\nA new connection has been created\n\n";
                }
                system("pause");
                break;
            }
            case 4: {
                int source, destination;
                char answer;
                bool bidirectional = true;
                cout << "Enter the source vertex position: ";
                cin >> source;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                cout << "Enter the destination vertex position: ";
                cin >> destination;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                cout << "Delete only one direction (Y/N): ";
                cin >> answer;

                if (answer == 'y' || answer == 'Y'){
                    bidirectional = false;
                }else if(answer != 'n' && answer != 'N'){
                    cout << "Option not found";
                    cin.clear();
                    while (getchar() != '\n'); 
                    break;
                }
                myGraph.deleteEdge(source, destination, bidirectional);
                cout << "\n\nThe connection has been deleted\n\n";
                system("pause");
                break;
            }
            case 5:{
                int value, idx;
                cout << "\nEnter the position of the vertex to modify: ";
                cin >> idx;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                cout << "Enter the new value: ";
                cin >> value;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                myGraph[idx].data = value;
                cout << "\n\nThe value has been modified successfully.\n\n";
                system("pause");
                break;
            }
            case 6:
                myGraph.displayGraph();
                system("pause");
                break;
            case 7: {
                int source, destination;
                bool isAdj = false;
                cout << "Enter the source vertex position: ";
                cin >> source;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                cout << "Enter the destination vertex position: ";
                cin >> destination;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }

                isAdj = myGraph.isAdjacent(source, destination);

                if(isAdj == true){
                    cout << "Vertex " << source << " is adjacent to " << destination << "\n";
                }else{
                    cout << "Vertex " << source << " is not adjacent to " << destination << "\n";
                }
                system("pause");
                break;
            }
            case 8:
                myGraph.addVertex(1);
                myGraph.addVertex(2);
                myGraph.addVertex(3);
                myGraph.addVertex(4);
                myGraph.addVertex(5);
                myGraph.addVertex(6);
                myGraph.addVertex(7);
                myGraph.addVertex(8);
                myGraph.addVertex(9);

                myGraph.addEdge(0, 5, 5, true);
                myGraph.addEdge(0, 4, 6, true);
                myGraph.addEdge(1, 2, 9, true);
                myGraph.addEdge(1, 4, 7, true);
                myGraph.addEdge(3, 4, 2, true);
                myGraph.addEdge(3, 8, 1, true);
                myGraph.addEdge(4, 6, 11, true);
                myGraph.addEdge(4, 7, 6, true);
                myGraph.addEdge(5, 8, 4, true);
                myGraph.addEdge(7, 8, 5, true);
                myGraph.addEdge(7, 7, 4, true);

                cout << "\nGraph created\n\n";
                system("pause");
                break;
            case 9:
                myGraph.addVertex(1);
                myGraph.addVertex(2);
                myGraph.addVertex(3);
                myGraph.addVertex(4);
                myGraph.addVertex(5);
                myGraph.addVertex(6);
                myGraph.addVertex(7);

                myGraph.addEdge(0, 1, 0, true);
                myGraph.addEdge(0, 5, 0, true);
                myGraph.addEdge(1, 6, 0, true);
                myGraph.addEdge(1, 4, 0, false);
                myGraph.addEdge(2, 1, 0, false);
                myGraph.addEdge(2, 6, 0, false);
                myGraph.addEdge(3, 2, 0, false);
                myGraph.addEdge(3, 3, 0, true);
                myGraph.addEdge(4, 6, 0, true);
                myGraph.addEdge(4, 5, 0, false);
                myGraph.addEdge(5, 2, 0, false);

                cout << "\nGraph created\n\n";
                system("pause");
                break;
            case 10:
                myGraph.addVertex(1);
                myGraph.addVertex(2);
                myGraph.addVertex(3);
                myGraph.addVertex(4);
                myGraph.addVertex(5);

                myGraph.addEdge(0, 1, 5, true);
                myGraph.addEdge(0, 3, 5, true);
                myGraph.addEdge(1, 3, 11, true);
                myGraph.addEdge(1, 4, 42, true);
                myGraph.addEdge(2, 3, 5, true);
                myGraph.addEdge(2, 4, 11, true);

                cout << "\nGraph created\n\n";
                system("pause");
                break;
            case 11:
                if(!myGraph.isDirected() && myGraph.isWeighted()){
                    myGraph.kruskal();
                }else{
                    cout << "\nThe graph is directed or unweighted. Cannot use Kruskal's algorithm\n";
                }
                system("pause");
                break;
            case 12:
                if(!myGraph.isDirected() && myGraph.isWeighted()){
                    myGraph.prim();
                }else{
                    cout << "\nThe graph is directed or unweighted. Cannot use Prim's algorithm\n";
                }
                system("pause");
                break;  
            case 13:
                if(!myGraph.hasNegativeWeights() && myGraph.isWeighted()){
                    int source, destination;
                    cout << "Enter the source vertex position: ";
                    cin >> source;
                    if(!validateInteger(cin)){
                        system("pause");
                        break;
                    }
                    cout << "Enter the destination vertex position: ";
                    cin >> destination;
                    if(!validateInteger(cin)){
                        system("pause");
                        break;
                    }
                    myGraph.dijkstra(source, destination);
                }else{
                    cout << "\nThe graph has negative or zero weights. Cannot use Dijkstra's algorithm\n";
                }
                system("pause");
                break;
            case 14:{
                int source;
                cout << "Enter the source vertex position: ";
                cin >> source;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                myGraph.depthFirstSearch(source);
                system("pause");
                break;
            }
            case 15:{
                int source;
                cout << "Enter the source vertex position: ";
                cin >> source;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                myGraph.breadthFirstSearch(source);
                system("pause");
                break;
            }
            case 16:
                cout << "Exiting...";
                break;
        }
    }while(option != 16);

    return 0;
}
