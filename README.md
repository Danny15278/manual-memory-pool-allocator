# A Manual Memory Pool Allocator

PLEASE NOTE THAT THIS PROJECT IS STILL IN PROGRESS AND NOT FULLY COMPLETED WITH ALL INTENDED FEATURES.

This is a simple project that creates a fixed-size memory pool allocator, written up in C++. 

It allocates a block of memory up initially and manages individual allocations manually using a free list, avoiding calls to 'new' or malloc.

Features include:
- Pre-allocation of memory block at construction.
- Fixed-size chunk allocations.
- Fast manual allocation/deallocation.
- Reusability of free chunks using a free list.

Build Instructions (THIS PROJECT STILL IN TESTING AND IS INCOMPLETE)

git clone https://github.com/Danny15278/manual-memory-pool-allocator.git
cd manual-memory-pool-allocator
mkdir build
cd build
cmake ..
cmake --build .
./allocator_main
