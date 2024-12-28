#include <iostream>
#include <random>
#include <chrono>
#include "../src/core/naive_filter.h"
#include "../external/hnswlib/hnswlib.h"

void runHNSWExample() {
    // Parameters
    const size_t dim = 16;
    const size_t num_points = 10000;
    const size_t num_attributes = 1000;
    const size_t max_attributes_per_point = 50;
    
    // Initialize HNSW index
    hnswlib::L2Space space(dim);
    auto* alg_hnsw = new hnswlib::HierarchicalNSW<float>(&space, num_points);
    
    // Initialize random number generators
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis_real(0, 1);
    std::uniform_int_distribution<> dis_attr(0, num_attributes-1);
    std::uniform_int_distribution<> dis_count(1, max_attributes_per_point);
    
    // Create filter
    filtering::NaiveFilter filter;
    
    // Generate and add points
    std::vector<std::vector<float>> points(num_points, std::vector<float>(dim));
    
    std::cout << "Adding points and attributes...\n";
    for (size_t i = 0; i < num_points; i++) {
        // Generate random vector
        for (size_t j = 0; j < dim; j++) {
            points[i][j] = dis_real(gen);
        }
        
        // Add point to HNSW
        alg_hnsw->addPoint(points[i].data(), i);
        
        // Add random attributes
        int num_attrs = dis_count(gen);
        for (int j = 0; j < num_attrs; j++) {
            filter.addAttribute(i, dis_attr(gen));
        }
        
        if (i % 1000 == 0) {
            std::cout << "Processed " << i << " points\n";
        }
    }
    
    // Run queries with filter
    std::cout << "\nRunning queries...\n";
    const size_t num_queries = 100;
    const size_t k = 10;  // number of nearest neighbors
    
    std::vector<unsigned int> query_attrs = {0, 1};  // Look for points with attributes 0 AND 1
    filter.setQueryAttributes(query_attrs);
    
    double total_query_time = 0;
    size_t total_results = 0;
    
    for (size_t i = 0; i < num_queries; i++) {
        // Generate random query point
        std::vector<float> query(dim);
        for (size_t j = 0; j < dim; j++) {
            query[j] = dis_real(gen);
        }
        
        auto start = std::chrono::high_resolution_clock::now();
        auto result = alg_hnsw->searchKnn(query.data(), k, &filter);
        auto end = std::chrono::high_resolution_clock::now();
        
        total_query_time += std::chrono::duration<double, std::milli>(end - start).count();
        total_results += result.size();
        
        std::cout << "Query " << i << ": found " << result.size() << " results\n";
    }
    
    // Print statistics
    std::cout << "\nResults:\n";
    std::cout << "Average query time: " << total_query_time / num_queries << "ms\n";
    std::cout << "Average results per query: " << static_cast<double>(total_results) / num_queries << "\n";
    std::cout << "Filter average operation time: " << filter.getAverageOperationTimeMs() << "ms\n";
    std::cout << "Total filter operations: " << filter.getTotalOperations() << "\n";
    
    delete alg_hnsw;
}

int main() {
    runHNSWExample();
    return 0;
}