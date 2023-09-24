#include <iostream>
#include "Heap.hpp"

int main() {
    std::cout << "Welcome to the Heaps programming exercise!" << std::endl;
    // std::cout << "The parent of the node at index 12 is at index: " << parent(12) << std::endl;
    // std::cout << "The left child of the node at index 12 is at index: " << left(12) << std::endl;
    // std::cout << "The right child of the node at index 12 is at index: " << right(12) << std::endl;
    // std::cout<<std::endl;

    // std::cout<< "Creating a new heap using an array: " << std::endl;
    // Heap h(0);
    // std::cout << "Created a new heap of " << h.heap_size << " elements in memory address: " << &h << std::endl;
    // std::cout<<std::endl;

    // std::cout<< "Inserting element 32 into the heap:" << std::endl;
    // h.insert(32);
    // std::cout<< "Inserting element 75 into the heap:" << std::endl;
    // h.insert(75);
    // std::cout<< "Inserting element 41 into the heap:" << std::endl;
    // h.insert(41);
    // std::cout<< "Inserting element 35 into the heap:" << std::endl;
    // h.insert(35);
    // std::cout<< "Inserting element 20 into the heap:" << std::endl;
    // h.insert(20);
    // std::cout<< "Inserting element 47 into the heap:" << std::endl;
    // h.insert(47);
    // std::cout<< "Inserting element 74 into the heap:" << std::endl;
    // h.insert(74);
    // std::cout<< "Inserting element 56 into the heap:" << std::endl;
    // h.insert(56);

    // for (const int& element : h.array)
    // {
    //     std::cout << element << ", ";
    // }

    // std::cout << std::endl;
    // std::cout << "Heap size: " << h.heap_size << std::endl;

    // //std::cout << "Extracting max from heap." << std::endl;
    // h.extractMax();
    // h.extractMax();
    // h.extractMax();

    // std::cout<< "Heap after extracting max element 3 times: ";
    // for (const int& element : h.array)
    // {
    //     std::cout << element << ", ";
    // }

    std::vector<int> practice_list{42, 37, 23, 17, 12, 20, 87, 14};

    Heap h{practice_list, false};

    // Sorting
    h.sort();

    for (const int& i : h.array)
    {
        std::cout << i << " ";
    }

    return 0;
}