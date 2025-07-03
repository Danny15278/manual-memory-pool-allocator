# A Manual Memory Pool Allocator

PLEASE NOTE THAT THIS PROJECT IS STILL IN DEVELOPMENT AND NOT FULLY COMPLETED WITH ALL INTENDED FEATURES.

This project creates a fixed-size memory pool allocator, written up in modern C++. 

This tool is designed to pre-allocate a large block of memory up initially during construction, which is split into equal sized chunks. Individual allocations are manually managed using a simply linked free list, avoiding calls to 'new' or 'malloc' and allowing for fast, reusable allocation/deallocation that avoids heap framentation and allocation overhead.

Features include:
- Pre-allocation of memory block at construction.
- Fixed-size chunk allocations.
- Fast manual allocation/deallocation.
- Reusability of free chunks using a free list.
- Unit tests with Catch2
- Memcheck with Valgrind

# Build Instructions

git clone https://github.com/Danny15278/manual-memory-pool-allocator.git<br />
cd manual-memory-pool-allocator<br />
mkdir build<br />
cd build<br />
cmake ..<br />
cmake --build .<br />
./allocator_main (Run main demo)<br />
./allocator_tests (Run test cases)<br />
