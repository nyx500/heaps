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
    unsigned int heap_size; //the size of the heaps
public:
    /**This is a simple constructor with a single integer input argument.
     * The constructor creates the storage area for a heap of size N and initializes the heap size.
    */
    Heap(unsigned int);
    /**This ctor receives 2 input args: a list and a Boolean value.
     * If the bool value is True, build heap out-of-place ('incrementally') using the insert method.
     * If the bool value is False, build heap in-place using buildMaxHeap
     * In both cases, make sure that the constructor creates the storage area for the heap and initializes
     * the heap size accordingly
    */
    Heap(std::vector<int>, bool = false);
    /**Insert element k into heap maintaining heap properties*/
    void insert(int);
    /**Swap the elements at the two indexes specified in the input arguments*/
    void swap(unsigned int pos_1, unsigned int pos_2);
    int maximum();
    /**Used in max-heapify function: returns index of largest child node if exists, else returns
        * root index
    */
    int get_largest_node_index(int i);
    /**This method applies max-heapify from the element in position index 'downwards' in the
     *tree visualization*/
    void maxHeapify(int);
    /**This method builds the heap in place*/
    void buildMaxHeap();
    /**This method extracts (meaning it deletes) the maximum element from the heap,
     * maintaining the heap properties, and returns its values
    */
    int extractMax();
    std::vector<int> sort();
};

#endif
