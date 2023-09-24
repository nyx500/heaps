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
}


/**This ctor receives 2 input args: a list and a Boolean value.
 * If the bool value is True, build heap out-of-place ('incrementally') using the insert method.
 * If the bool value is False, build heap in-place using buildMaxHeap
 * In both cases, make sure that the constructor creates the storage area for the heap and initializes
 * the heap size accordingly
*/
Heap::Heap(std::vector<int> source, bool incremental) {

    if (incremental)
    {   
        std::vector<int> newArray(0);
        array = newArray;
        heap_size = 0;

        std::cout << "Insert out of place" << std::endl;

        for (int value : source)
        {   
            insert(value);
        }
    }
    else
    {   
        heap_size = source.size();
        array = source;
        buildMaxHeap();
    }
}

/**Insert element k into heap maintaining heap properties*/
void Heap::insert(int k) {
    // Insert new element into last position in the heap (heap_size = last element filled + 1)
    unsigned int pos_of_new_element = heap_size;
    array.push_back(k);
    // Increment heap size by 1
    ++heap_size;
    
    // While-loop: only runs if the new-element is inserted at index greater than 0 (first index)
    // AND parent-element of the new element is less than the value of the new element
    while (pos_of_new_element > 0 && array[parent(pos_of_new_element)] < array[pos_of_new_element])
    {   
        // Swap the element with its parent element
        swap(parent(pos_of_new_element), pos_of_new_element);
        // Update the position of the new element following the swap (going up the tree/heap)
        pos_of_new_element = parent(pos_of_new_element);
    }

}

/**Swap the elements at the two indexes specified in the input arguments*/
void Heap::swap(unsigned int pos_1, unsigned int pos_2){
    // Tmp holder for the swapped value
    int tmp = array[pos_1];
    array[pos_1] = array[pos_2];
    array[pos_2] = tmp;
}

/**Return max element but do not extract*/
int Heap::maximum() {
    if (heap_size > 0)
    {
        return array[0];
    }
    else
    {   
        std::cout << "Empty heap!" << std::endl;
        return -1;
    }
}

/**Used in max-heapify function: returns index of largest child node if exists, else returns
 * root index
*/
int Heap::get_largest_node_index(int i){

    // Get index of array[i]'s left child
    int left_child_index = left(i);
    
    // Get index of array[i]'s right child
    int right_child_index = right(i);

    int largest_index = i;

    // Check if left child is larger
    if (left_child_index < heap_size && array[left_child_index] > array[largest_index])
    {
        largest_index = left_child_index;
    }
    // Check if right child is larger
    if (right_child_index < heap_size && array[right_child_index] > array[largest_index])
    {
        largest_index = right_child_index;
    }

    // Return largest element's index
    return largest_index;
}

/**This method applies max-heapify from the element in position index 'downwards' in the
 *tree visualization*/
void Heap::maxHeapify(int i) { // i = like the root of the heap sub-tree we are interested in

    // Get the index of largest child-node of this element or same index if no greater children
    int largest_node_index = get_largest_node_index(i);
    
    // Run this logic if and only if there is a child element larger than current node
    if (largest_node_index != i)
    {   
        // Swap current node with the larger child node
        swap(largest_node_index, i);
        // Current node now in largest index, child moved up a level, call function again
        maxHeapify(largest_node_index);
    }
}

/**This method builds the heap in place*/
void Heap::buildMaxHeap() {
    for (int i = floor(heap_size / 2) - 1; i >= 0; --i)
    {   
        std::cout << "Heapify: " << i <<", ";
        maxHeapify(i);
    }
}

/**This method extracts (meaning it deletes) the maximum element from the heap,
 * maintaining the heap properties, and returns its values
*/
int Heap::extractMax() {

    if (heap_size == 0)
    {   
        std::cout << "Empty heap!" << std::endl;
        return 0;
    }

    // Copy content of last element into root and delete last position in the heap
    int max = array[0]; // Save max to return later
    array[0] = array[heap_size - 1];
    // Decrement the heap size
    --heap_size;
    // Then heapify the result
    maxHeapify(0);
    // Print max being deleted from heap
    std::cout << "Extracting element with value " << max << std::endl;
    // Return the max value now it has been deleted
    return max;
}

/**Sorts the content of array and returns it*/
std::vector<int> Heap::sort() {

    // Array is already max heap due to constructor, so skip first step of algorithm

    while (heap_size > 0)
    {
        int i = heap_size-1;
        array[i] = extractMax();
    }

    return array;
}

