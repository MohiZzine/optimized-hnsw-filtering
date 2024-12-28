#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
#include "../src/core/roaring_filter.h"
#include "../external/hnswlib/hnswlib.h"

void printPoint(const float* point, size_t dim) {
    std::cout << "[";
    for (size_t i = 0; i < dim; i++) {
        std::cout << std::fixed << std::setprecision(3) << point[i];
        if (i < dim - 1) std::cout << ", ";
    }
    std::cout << "]";
}

void runRoaringHNSWExample() {
    // Parameters
    const size_t dim = 128;              // Vector dimension
    const size_t num_points = 100000;    // Number of points
    const size_t num_attributes = 10000;  // Total possible attributes
    const size_t attrs_per_point = 50;    // Attributes per point
    const size_t k = 5;                   // Number of nearest neighbors
    
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
    std::uniform_real_distribution<> dis_vec(-1.0, 1.0);
    std::uniform_int_distribution<> dis_attr(0, num_attributes-1);

    // Create filter
    filtering::RoaringFilter filter;
    
    // Generate and add points
    std::vector<std::vector<float>> points(num_points, std::vector<float>(dim));
    
    std::cout << "Adding points and attributes...\n";
    auto start_build = std::chrono::high_resolution_clock::now();
    
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
        
        if (i % 10000 == 0) {
            std::cout << "Processed " << i << " points\n";
        }
    }
    
    auto end_build = std::chrono::high_resolution_clock::now();
    double build_time = std::chrono::duration<double>(end_build - start_build).count();
    std::cout << "Build time: " << build_time << " seconds\n";
    
    // Run queries with different attribute combinations
    std::cout << "\nRunning queries...\n";
    const size_t num_queries = 5;
    
    std::vector<std::vector<unsigned int>> query_attributes = {
        {0},                        // Single attribute
        {0, 1},                    // Two attributes
        {0, 1, 2},                 // Three attributes
        {num_attributes - 1},       // Last attribute
        {}                         // No attributes
    };
    
    double total_query_time = 0;
    size_t total_results = 0;
    
    for (size_t i = 0; i < num_queries; i++) {
        // Generate random query vector
        std::vector<float> query(dim);
        for (size_t j = 0; j < dim; j++) {
            query[j] = dis_vec(gen);
        }
        
        // Set query attributes
        filter.setQueryAttributes(query_attributes[i]);
        
        std::cout << "\nQuery " << i + 1 << ":"
                  << "\nQuerying for points with attributes: [";
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
        total_query_time += query_time;
        total_results += result.size();
        
        // Print results
        std::cout << "Found " << result.size() << " results in " << query_time << "ms\n";
        size_t num_to_show = std::min(result.size(), size_t(3));  // Show top 3 results
        
        while (!result.empty() && num_to_show > 0) {
            auto& top = result.top();
            std::cout << "Point " << top.second << " (distance: " << top.first << ")\n";
            result.pop();
            num_to_show--;
        }
    }
    
    // Print performance metrics
    std::cout << "\nPerformance Metrics:\n"
              << "Build time: " << build_time << " seconds\n"
              << "Average query time: " << total_query_time / num_queries << "ms\n"
              << "Average results per query: " << static_cast<double>(total_results) / num_queries << "\n"
              << "Filter average operation time: " << filter.getAverageOperationTimeMs() << "ms\n"
              << "Total filter operations: " << filter.getTotalOperations() << "\n"
              << "Total memory usage for attributes: " << filter.getMemoryUsage() / 1024.0 / 1024.0 << " MB\n";
    
    delete alg_hnsw;
}

int main() {
    runRoaringHNSWExample();
    return 0;
}