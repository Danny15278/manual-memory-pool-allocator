
#pragma once
#include <cstddef>


struct Chunk {
	Chunk* next;
};


class MemoryPool {
private:
	size_t chunkSize;
	size_t chunkCount;
	void* poolMemory;
	Chunk* freeListHead;

public:
	MemoryPool(size_t chunkSize, size_t chunkCount);
	void* allocate();
	void deallocate(void* ptr);
	~MemoryPool();
};
