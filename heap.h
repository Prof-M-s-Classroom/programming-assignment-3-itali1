#ifndef HEAP_H
#define HEAP_H
#include <ranges>
#include <bits/algorithmfwd.h>

using namespace std;
class MinHeap {
public:
    MinHeap(int capacity) {
        this->capacity = 0;
        size = capacity;
        heapArray = new int[capacity];
        keyArray = new int[capacity];
        position = new int[capacity];
        for(int i = 0; i < size; i++) {
            if(i == 0) {
                keyArray[0] = 0;
            }
            else {
                keyArray[i] = INT_MAX;
            }
            heapArray[i] = i;
            position[i] = i;
        }
    }
    ~MinHeap(){}
    void insert(int vertex, int key) {
        keyArray[vertex] = key;
    }
    int extractMin() {
        int temp = 0;
        if(capacity == 0) {
            temp = 0;
        }
        else {
            temp = capacity;
        }
        capacity += 1;
        for(int i = 0; i < size; i++) {
            if(position[i] != 0) {
                position[i] = position[i] - 1;
            }
        }
        return keyArray[temp];
    }
    void decreaseKey(int vertex, int newKey) { //used to replace a key with a smaller one (more efficient path)
        if(keyArray[vertex] > newKey) {
            keyArray[vertex] = newKey;
        }

    }
    bool isInMinHeap(int vertex) { //did not use
        for(int i = 0; i < size; i++) {
            if(heapArray[i] != vertex) {
                return true;
            }
        }
        return false;
    }
    bool isEmpty() { //did not use
        if(capacity == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    void print() { // used for debugging
        cout<<"KeyArray: ";
        for(int i = 0; i < size; i++) {
            cout << keyArray[i] << " ";
        }
        cout << endl;
        cout<<"Position: ";
        for(int i = 0; i < size; i++) {
            cout << position[i] << " ";
        }
        cout << endl;
        cout<<"HeapArray: ";
        for(int i = 0; i < size; i++) {
            cout << heapArray[i] << " ";
        }
        cout<<endl;
    }

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap
    int capacity;
    int size;

    void minHeapify(int idx);
};

#endif