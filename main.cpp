#include <iostream>
#include "Heap.hpp"

int main() {
    std::cout << "Welcome to the Heaps programming exercise!" << std::endl;
    std::cout << "The parent of the node at index 12 is at index: " << parent(12) << std::endl;
    std::cout << "The left child of the node at index 12 is at index: " << left(12) << std::endl;
    std::cout << "The right child of the node at index 12 is at index: " << right(12) << std::endl;
    std::cout<<std::endl;
    std::cout<< "Creating a new heap using an array: " << std::endl;
    Heap h(10);
    return 0;
}