#include <iostream>
#include <cstddef>
#include <stdexcept>

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
	MemoryPool(size_t chunkSize, size_t chunkCount) : chunkSize(chunkSize), chunkCount(chunkCount), poolMemory(nullptr), freeListHead(nullptr) {
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

	void* allocate() {
		if (!freeListHead)
			return nullptr;
		Chunk* allocatedChunk = freeListHead;
		freeListHead = freeListHead -> next;
		return allocatedChunk;
	}
	
	void deallocate(void* ptr) {
		Chunk* freedChunk = reinterpret_cast<Chunk*>(ptr);
		freedChunk -> next = freeListHead;
		freeListHead = freedChunk;
	}
	
	~MemoryPool() {
		operator delete(poolMemory);
	}
};


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
