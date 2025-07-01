#include <iostream>
#include "allocator.hpp"

int main() {
    std::cout << "Starting Memory Pool Allocator..." << std::endl;

    MemoryPool pool(64, 10);

    void* ptr1 = pool.allocate();
    std::cout << "Allocated chunk at: " << ptr1 << std::endl;

    void* ptr2 = pool.allocate();
    std::cout << "Allocated another chunk at: " << ptr2 << std::endl;

    pool.deallocate(ptr1);
    std::cout << "Deallocated first chunk." << std::endl;

    void* ptr3 = pool.allocate();
    std::cout << "Allocated again (reuse): " << ptr3 << std::endl;

    return 0;
}

