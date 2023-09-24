#ifndef HEAP_HPP
#define HEAP_HPP

#include <vector>

// This	method returns the index of the parent of the element stored in index.
unsigned int parent(unsigned int);
// This method returns the index of the left child of the element stored in index.
unsigned int left(unsigned int);
// This method returns the index of the right child of the element stored in index.
unsigned int right(unsigned int);

class Heap {
public: // for cppunit testing purposes
    std::vector<int> array; //array where the heap is stored
    unsigned int heap_size; //the size of the heap
public:
    /**This is a simple constructor with a single integer input argument.
     * The constructor creates the storage area for a heap of size N and initializes the heap size.
    */
    Heap(unsigned int);
    Heap(std::vector<int>, bool = false);
    void insert(int);
    int maximum();
    void maxHeapify(int);
    void buildMaxHeap();
    int extractMax();
    std::vector<int> sort();
};

#endif
