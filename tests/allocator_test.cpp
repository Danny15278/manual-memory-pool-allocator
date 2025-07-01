
#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "../src/allocator.hpp"


TEST_CASE("Allocate returns non-null", "[MemoryPool]") {
	MemoryPool pool(64, 10);
	void* ptr = pool.allocate();
	REQUIRE(ptr != nullptr);
}

TEST_CASE("Reuse deallocated memory", "[MemoryPool]") {
	MemoryPool pool(64, 10);
	void* ptr1 = pool.allocate();
	pool.deallocate(ptr1);
	void* ptr2 = pool.allocate();
	REQUIRE(ptr2 == ptr1); 
}

TEST_CASE("Returns nullptr after all chunks allocated", "[MemoryPool]") {
	MemoryPool pool(64, 2);
	void* ptr1 = pool.allocate();
	void* ptr2 = pool.allocate();
	void* ptr3 = pool.allocate(); 
	
	(void)ptr1;
	(void)ptr2;
	REQUIRE(ptr3 == nullptr);
	REQUIRE(pool.allocate() == nullptr);
}


