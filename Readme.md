[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Itali Pizarro Valentin

## Description
This program follows the Prim's algorithm rules. It stars with a vertex, and then it follows the edges that have less
weight making sure that the path connects all the vertices with following edges with minimum weight.

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | O(1)            |
| Extract Min          | O(1)            |
| Decrease Key         | O(n)            |
| Prim’s MST Overall   | O(n^2)          |

This MST has a O(1) insertion in MinHeap since you just need the position where you want to insert a value/element in the heap. The creation of the heap itself is an time complexity of O(n^2).
The decrease of a key takes an O(n) time since it the times it takes to decrease a key depends on how many adjacent vertices we need to check (to see if the weight of an edge is less or more).
The extraction of a min takes O(1), it takes the same amount of time to extract a min, since we extract the min at index 0 and then 1 and 2 and so on until we extract the last min, but we do not 
check every min every time we want to extract a min, instead we skip previously checked min value. Prim's MST overall time complexity is O(n^2) since we have to check for every value of the adjacent
matrix which vertices(n) determine the size of the matrix(n*n).

## Test Case Description

A test case was the one used in the PA3 Sample
Input:
Graph g(4);              // Initialize graph with 4 vertices
g.addEdge(0, 1, 2);      // Add edge 0 - 1 with weight 2
g.addEdge(0, 2, 4);      // Add edge 0 - 2 with weight 4
g.addEdge(1, 2, 1);      // Add edge 1 - 2 with weight 1
g.addEdge(1, 3, 7);      // Add edge 1 - 3 with weight 7
g.addEdge(2, 3, 3);      // Add edge 2 - 3 with weight 3
g.primMST();             // Call Prim's algorithm
 
Output:
0 -- 1 (2)
1 -- 2 (1)
2 -- 3 (3)

Input:
Graph g(5);
g.addEdge(0, 1, 2);
g.addEdge(0, 3, 6);
g.addEdge(1, 2, 3);
g.addEdge(1, 3, 8);
g.addEdge(1, 4, 5);
g.addEdge(2, 4, 7);
g.addEdge(3, 4, 9);

g.primMST();

Output:
0 -- 1 (2)
1 -- 2 (3)
0 -- 3 (6)
1 -- 4 (5)

I debugged mainly by printing the keyArray, heapArray, and positionArray. I did not know where to use certain methods in heap.h, 
such as the isEmpty method, so I did not use it. Something that I found difficult was finding a way to find the edges that corresponded to the keyValues, at the end I 
decided to just use the same loop that extracted the minValue (keyValues) to print the edges and the weight together.