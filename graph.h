#ifndef GRAPH_H
#define GRAPH_H
#include "heap.h"

class Graph {
public:
    Graph(int vertices) {
        numVertices = vertices;
        //adjacency matrix of size numVertices*numVertices is created
        adjMatrix = new int *[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; j++) {
                if(i == j) {
                    adjMatrix[i][j] = 0;
                }
                else {
                    adjMatrix[i][j] = INT_MAX;
                }
            }
        }
    }
    ~Graph(){}
    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }
    void primMST() {
        // Must print MST edges and total weight
        int min;
        MinHeap a(numVertices); // initialize MinHeap of size numVertices
        for(int i = 0; i < numVertices; i++) {
            min = a.extractMin(); //returns the minKey at a certain index of KeyArray
            for(int j = 0; j < numVertices; j++) {
                if(adjMatrix[i][j] > 0) {
                    a.decreaseKey(j, adjMatrix[i][j]);
                }
                if(adjMatrix[i][j] == min) {
                    if(adjMatrix[i][j] != 0) {
                        cout<<j<<" -- "<<i<<" ("<<min<<")"<<endl;
                    }
                }
            }
        }
    }

private:
    int** adjMatrix;
    int numVertices;
};

#endif