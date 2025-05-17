#include <iostream>
#include "graph.h"

int main() {
    Graph g(4);              // Initialize graph with 4 vertices
    g.addEdge(0, 1, 2);      // Add edge 0 - 1 with weight 2
    g.addEdge(0, 2, 4);      // Add edge 0 - 2 with weight 4
    g.addEdge(1, 2, 1);      // Add edge 1 - 2 with weight 1
    g.addEdge(1, 3, 7);      // Add edge 1 - 3 with weight 7
    g.addEdge(2, 3, 3);      // Add edge 2 - 3 with weight 3
    g.primMST();             // Call Prim's algorithm

    return 0;
}