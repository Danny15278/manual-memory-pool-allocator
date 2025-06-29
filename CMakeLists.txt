cmake_minimum_required(VERSION 3.18)
project(memory_pool_allocator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-Wall -Wextra -pedantic -g)

include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.5.3
)

FetchContent_MakeAvailable(Catch2)

add_executable(allocator_main src/main.cpp src/allocator.cpp)

add_executable(allocator_tests tests/allocator_test.cpp src/allocator.cpp)

target_include_directories(allocator_tests PRIVATE src)
target_link_libraries(allocator_tests PRIVATE Catch2::Catch2WithMain)

enable_testing()
add_test(NAME AllocatorTests COMMAND allocator_tests)

