# Multi-Attribute Filtering Optimization in HNSW with Bitsets and Roaring Bitmaps

![C++](https://img.shields.io/badge/C++-17-blue.svg)
![Build](https://img.shields.io/badge/build-passing-green.svg)

## Project Overview

This project implements and compares three approaches for efficient multi-attribute filtering in Approximate Nearest Neighbor (ANN) search using HNSW (Hierarchical Navigable Small World) indexing. The challenge addressed is optimizing the filtering process when each data point can have numerous attributes (1000+), and queries may specify one or multiple attributes as filters.

### Key Features
- Naive filtering implementation (baseline)
- Bitset-based filtering optimization
- Roaring bitmap-based filtering optimization
- Comprehensive benchmarking suite
- Integration with HNSWLib
- Support for both single and multi-attribute queries

## Technical Architecture

The project implements three distinct filtering approaches:

1. **Naive Filter**
   - Direct attribute scanning
   - Simple but inefficient for large attribute sets
   - O(n) complexity where n is number of attributes

2. **Bitset Filter**
   - Uses std::bitset for efficient attribute checking
   - Fast for dense attribute sets
   - Constant time attribute checks
   - Fixed memory overhead

3. **Roaring Bitmap Filter**
   - Hybrid data structure
   - Efficient for sparse attributes
   - Compressed storage
   - Optimized for large attribute spaces

### Integration with HNSW

```cpp
class BaseFilter {
    virtual bool operator()(labeltype label_id) = 0;
    virtual bool hasAttribute(labeltype point_id, unsigned int attr_id) = 0;
    virtual bool hasAttributes(labeltype point_id, 
                             const std::vector<unsigned int>& attrs) = 0;
};
```

## Performance

### Benchmark Results

Performance comparison across different scenarios:

1. **Single Attribute Query**
   - Bitset: ~1.5μs per query
   - Roaring: ~1.9μs per query
   - Naive: ~2.8μs per query

2. **Multi-Attribute Query**
   - Bitset: ~1.4μs per query
   - Roaring: ~1.5μs per query
   - Naive: ~2.7μs per query


### When to Use Each Filter

- **Naive Filter**
  - Small number of attributes (<100)
  - Simple implementation needed
  - Memory is constrained

- **Bitset Filter**
  - Dense attribute distribution
  - Fast query time priority
  - Memory availability

- **Roaring Bitmap**
  - Sparse attributes
  - Large attribute space (>10000)
  - Memory efficiency needed

## Installation

### Prerequisites
- C++17 compatible compiler
- CMake 3.10 or higher
- [HNSWLib](https://github.com/nmslib/hnswlib)
- Python 3.x (for visualizations)

### Build Instructions

```bash
# Clone repository
git clone [repository-url]

# Create build directory
mkdir build && cd build

# Configure with CMake
cmake -G "MinGW Makefiles" -DCMAKE_SH="CMAKE_SH-NOTFOUND" ..

# Build
cmake --build .
```

## Usage Examples

### Basic Usage

```cpp
// Create filter
filtering::BitsetFilter filter;

// Add attributes to points
filter.addAttribute(point_id, attribute_id);

// Set query attributes
std::vector<unsigned int> query_attrs = {1, 2, 3};
filter.setQueryAttributes(query_attrs);

// Use with HNSW
auto results = alg_hnsw->searchKnn(query_vector, k, &filter);
```

### Advanced Usage

```cpp
// Configure for specific scenarios
filtering::RoaringFilter filter;

// Track performance
std::cout << "Average operation time: " 
          << filter.getAverageOperationTimeMs() << "ms\n";
std::cout << "Memory usage: " 
          << filter.getMemoryUsage() << " bytes\n";
```

## Project Structure

```
project_root/
├── CMakeLists.txt
├── external/
│   ├── hnswlib/
│   └── roaring/
├── src/
│   └── core/
│       ├── filter_interface.h
│       ├── naive_filter.h/cpp
│       ├── bitset_filter.h/cpp
│       └── roaring_filter.h/cpp
├── tests/
│   ├── test_naive_filter.cpp
│   ├── test_bitset_filter.cpp
│   └── test_roaring_filter.cpp
├── examples/
│   ├── hnsw_example.cpp
│   ├── hnsw_bitset_example.cpp
│   └── hnsw_roaring_example.cpp
└── benchmarks/
    ├── filter_benchmarks.cpp
    └── visualize_results.py
```


## Implementation Details

### Filter Interface
All filters implement a common interface ensuring consistent usage:

```cpp
class BaseFilter {
    virtual bool operator()(labeltype label_id);
    virtual bool hasAttribute(labeltype point_id, unsigned int attr_id);
    virtual bool hasAttributes(labeltype point_id, 
                             const std::vector<unsigned int>& attrs);
};
```

### Key Design Decisions

1. **Attribute Storage**
   - Naive: std::unordered_set
   - Bitset: std::bitset<MAX_ATTRIBUTES>
   - Roaring: roaring::Roaring

2. **Performance Tracking**
   - Operation timing
   - Memory usage monitoring
   - Query statistics

3. **Thread Safety**
   - Read-only during queries
   - Mutex protection for modifications


## Benchmarking

### Running Benchmarks

```bash
# Build and run benchmarks
cd build
./run_benchmarks.exe --benchmark_format=json > results.json

# Generate visualizations
python ../benchmarks/visualize_results.py results.json
```
