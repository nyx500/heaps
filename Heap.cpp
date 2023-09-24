#include <iostream>
#include <cmath>
// Lets you copy an array into another array
#include <algorithm>
#include "Heap.hpp"

// This	method returns the index of the parent of the element stored in index.
unsigned int parent(unsigned int i) {
    int parent = floor((i - 1) / 2 );
    return parent;
}

// This method returns the index of the left child of the element stored in index.
unsigned int left(unsigned int i) {
    int left = (2 * i) + 1;
    return left;
}

// This method returns the index of the right child of the element stored in index.
unsigned int right(unsigned int i) {
    int right = (2 * i) + 2;
    return right;
}

/**This is a simple constructor with a single integer input argument.
 * The constructor creates the storage area for a heap of size N and initializes the heap size.
*/
Heap::Heap(unsigned int len) {
    std::vector<int> newArray(len);
    array = newArray;
    heap_size = len;
    std::cout << "Heap::Heap: new heap/array created at memory position: " << &array << std::endl;
}

Heap::Heap(std::vector<int> source, bool incremental) {
}

void Heap::insert(int k) {
}

int Heap::maximum() {
    return 0;
}

void Heap::maxHeapify(int i) {
}

void Heap::buildMaxHeap() {
}

int Heap::extractMax() {
    return 0;
}

std::vector<int> Heap::sort() {
    return array;
}

