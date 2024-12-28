#include <thread>
#include <mutex>
#include <random>
#include <iostream> 
#include "../external/hnswlib/hnswlib.h"

// Filter that allows labels divisible by divisor
class PickDivisibleIds: public hnswlib::BaseFilterFunctor {
    unsigned int divisor = 1;
public:
    PickDivisibleIds(unsigned int divisor): divisor(divisor) {
        assert(divisor != 0);
    }
    bool operator()(hnswlib::labeltype label_id) {
        return label_id % divisor == 0;
    }
};

int main() {
    int dim = 16;               // Dimension of the elements
    int max_elements = 10000;   // Maximum number of elements
    int M = 16;                 // Tightly connected with internal dimensionality
    int ef_construction = 200;  // Controls index search speed/build speed tradeoff

    std::cout << "Initializing index with dim=" << dim << ", max_elements=" << max_elements << std::endl;
    
    // Initing index
    hnswlib::L2Space space(dim);
    hnswlib::HierarchicalNSW<float>* alg_hnsw = new hnswlib::HierarchicalNSW<float>(&space, max_elements, M, ef_construction);

    // Generate random data
    std::cout << "Generating random data..." << std::endl;
    std::mt19937 rng;
    rng.seed(47);
    std::uniform_real_distribution<> distrib_real;
    float* data = new float[dim * max_elements];
    for (int i = 0; i < dim * max_elements; i++) {
        data[i] = distrib_real(rng);
    }

    // Add data to index
    std::cout << "Adding points to index..." << std::endl;
    for (int i = 0; i < max_elements; i++) {
        alg_hnsw->addPoint(data + i * dim, i);
        if (i % 1000 == 0) {
            std::cout << "Added " << i << " points" << std::endl;
        }
    }

    // Create filter that allows only even labels
    std::cout << "\nCreating filter for even labels..." << std::endl;
    PickDivisibleIds pickIdsDivisibleByTwo(2);

    // Query the elements for themselves with filter
    int k = 10;  // number of nearest neighbors to retrieve
    int totalQueries = 0;
    int evenResults = 0;

    std::cout << "Running queries with filter..." << std::endl;
    for (int i = 0; i < max_elements; i++) {
        std::vector<std::pair<float, hnswlib::labeltype>> result = 
            alg_hnsw->searchKnnCloserFirst(data + i * dim, k, &pickIdsDivisibleByTwo);
        
        totalQueries += result.size();
        for (auto& item : result) {
            if (item.second % 2 == 0) {
                evenResults++;
            } else {
                std::cout << "Error: found odd label " << item.second << std::endl;
            }
        }
        
        if (i % 1000 == 0) {
            std::cout << "Processed " << i << " queries" << std::endl;
        }
    }

    std::cout << "\nResults Summary:" << std::endl;
    std::cout << "Total queries: " << max_elements << std::endl;
    std::cout << "Total results: " << totalQueries << std::endl;
    std::cout << "Even results: " << evenResults << std::endl;
    std::cout << "Filter efficiency: " << (100.0 * evenResults / totalQueries) << "%" << std::endl;

    delete[] data;
    delete alg_hnsw;
    return 0;
}