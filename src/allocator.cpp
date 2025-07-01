
#include "allocator.hpp"
#include <stdexcept>
#include <new>

MemoryPool::MemoryPool(const size_t chunkSize,  const size_t chunkCount) : chunkSize(chunkSize), chunkCount(chunkCount), poolMemory(nullptr), freeListHead(nullptr) {
		poolMemory = operator new(chunkSize * chunkCount);

		if (chunkSize < sizeof(Chunk*)) {
			throw std::invalid_argument("chunkSize is too small to store a Chunk pointer.");
		}

		freeListHead = reinterpret_cast<Chunk*>(poolMemory);
		Chunk* current = freeListHead;

		for (size_t i{ 1 }; i < chunkCount; i++) {
			Chunk* next = reinterpret_cast<Chunk*>(reinterpret_cast<char*>(poolMemory) + i * chunkSize);
			current -> next = next;
			current = next;
		}

		current -> next = nullptr;
	}

void* MemoryPool::allocate() {
	if (!freeListHead)
		return nullptr;
	Chunk* allocatedChunk = freeListHead;
	freeListHead = freeListHead -> next;
	return allocatedChunk;
}
	
void MemoryPool::deallocate(void* ptr) {
	Chunk* freedChunk = reinterpret_cast<Chunk*>(ptr);
	freedChunk -> next = freeListHead;
	freeListHead = freedChunk;
}

MemoryPool::~MemoryPool() {
	operator delete(poolMemory);
}
