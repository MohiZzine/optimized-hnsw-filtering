#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
#include "../src/core/bitset_filter.h"
#include "../external/hnswlib/hnswlib.h"

void printPoint(const float* point, size_t dim) {
    std::cout << "[";
    for (size_t i = 0; i < dim; i++) {
        std::cout << std::fixed << std::setprecision(3) << point[i];
        if (i < dim - 1) std::cout << ", ";
    }
    std::cout << "]";
}

void runBitsetHNSWExample() {
    // Parameters
    const size_t dim = 16;               // Vector dimension
    const size_t num_points = 10000;     // Number of points
    const size_t num_attributes = 100;    // Total possible attributes
    const size_t attrs_per_point = 5;    // Attributes per point
    const size_t k = 5;                  // Number of nearest neighbors to find
    
    std::cout << "Initializing with:\n"
              << "- Dimensions: " << dim << "\n"
              << "- Points: " << num_points << "\n"
              << "- Total attributes: " << num_attributes << "\n"
              << "- Attributes per point: " << attrs_per_point << "\n\n";

    // Initialize HNSW index
    hnswlib::L2Space space(dim);
    auto* alg_hnsw = new hnswlib::HierarchicalNSW<float>(&space, num_points);
    
    // Initialize random generators
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis_vec(-1.0, 1.0);  // For vector components
    std::uniform_int_distribution<> dis_attr(0, num_attributes-1);  // For attributes

    // Create filter
    filtering::BitsetFilter filter;
    
    // Generate and add points
    std::vector<std::vector<float>> points(num_points, std::vector<float>(dim));
    
    std::cout << "Adding points and attributes...\n";
    for (size_t i = 0; i < num_points; i++) {
        // Generate random vector
        for (size_t j = 0; j < dim; j++) {
            points[i][j] = dis_vec(gen);
        }
        
        // Add point to HNSW
        alg_hnsw->addPoint(points[i].data(), i);
        
        // Add random attributes
        std::vector<bool> used_attrs(num_attributes, false);
        for (size_t j = 0; j < attrs_per_point; j++) {
            unsigned int attr;
            do {
                attr = dis_attr(gen);
            } while (used_attrs[attr]);
            
            used_attrs[attr] = true;
            filter.addAttribute(i, attr);
        }
        
        if (i % 1000 == 0) {
            std::cout << "Processed " << i << " points\n";
        }
    }
    
    // Run some example queries
    std::cout << "\nRunning example queries...\n";
    const size_t num_queries = 5;
    
    // Let's try different attribute combinations
    std::vector<std::vector<unsigned int>> query_attributes = {
        {0},                    // Single attribute
        {0, 1},                // Two attributes
        {0, 1, 2},             // Three attributes
        {num_attributes - 1},   // Last attribute
        {}                      // No attributes (should return nothing)
    };
    
    for (size_t i = 0; i < num_queries; i++) {
        // Generate random query vector
        std::vector<float> query(dim);
        for (size_t j = 0; j < dim; j++) {
            query[j] = dis_vec(gen);
        }
        
        // Set query attributes
        filter.setQueryAttributes(query_attributes[i]);
        
        std::cout << "\nQuery " << i + 1 << ":"
                  << "\nQuery vector: ";
        printPoint(query.data(), dim);
        std::cout << "\nQuerying for points with attributes: [";
        for (size_t j = 0; j < query_attributes[i].size(); j++) {
            std::cout << query_attributes[i][j];
            if (j < query_attributes[i].size() - 1) std::cout << ", ";
        }
        std::cout << "]\n";
        
        // Time the query
        auto start = std::chrono::high_resolution_clock::now();
        auto result = alg_hnsw->searchKnn(query.data(), k, &filter);
        auto end = std::chrono::high_resolution_clock::now();
        double query_time = std::chrono::duration<double, std::milli>(end - start).count();
        
        // Print results
        std::cout << "Found " << result.size() << " results in " << query_time << "ms:\n";
        while (!result.empty()) {
            auto& top_result = result.top();
            std::cout << "Point " << top_result.second << " (distance: " << top_result.first << "): ";
            printPoint(points[top_result.second].data(), dim);
            std::cout << "\n";
            result.pop();
        }
    }
    
    // Print performance metrics
    std::cout << "\nPerformance Metrics:\n"
              << "Average filter operation time: " << filter.getAverageOperationTimeMs() << "ms\n"
              << "Total filter operations: " << filter.getTotalOperations() << "\n";
    
    delete alg_hnsw;
}

int main() {
    runBitsetHNSWExample();
    return 0;
}