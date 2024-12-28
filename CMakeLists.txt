cmake_minimum_required(VERSION 3.10)
project(hnsw_filter_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add Google Benchmark
add_subdirectory(external/benchmark)

# Add includes
include_directories(${CMAKE_SOURCE_DIR}/external/hnswlib)
include_directories(${CMAKE_SOURCE_DIR}/external/roaring)

# Add filter library
add_library(filter_lib
    src/core/naive_filter.cpp
    src/core/bitset_filter.cpp
    src/core/roaring_filter.cpp
)

# Existing executables
add_executable(run_tests tests/test_naive_filter.cpp)
target_link_libraries(run_tests filter_lib)

add_executable(test_bitset tests/test_bitset_filter.cpp)
target_link_libraries(test_bitset filter_lib)

add_executable(test_roaring tests/test_roaring_filter.cpp)
target_link_libraries(test_roaring filter_lib)

add_executable(hnsw_example examples/hnsw_example.cpp)
target_link_libraries(hnsw_example filter_lib)

add_executable(hnsw_bitset_example examples/hnsw_bitset_example.cpp)
target_link_libraries(hnsw_bitset_example filter_lib)

add_executable(hnsw_roaring_example examples/hnsw_roaring_example.cpp)
target_link_libraries(hnsw_roaring_example filter_lib)

# Add benchmark executable
add_executable(run_benchmarks benchmarks/filter_benchmarks.cpp)
target_link_libraries(run_benchmarks 
    filter_lib 
    benchmark::benchmark 
    benchmark::benchmark_main
)