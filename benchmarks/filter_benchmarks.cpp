#include <benchmark/benchmark.h>
#include "../src/core/naive_filter.h"
#include "../src/core/bitset_filter.h"
#include "../src/core/roaring_filter.h"
#include <random>
#include <string>

enum class Scenario {
    DENSE,      // 1K attributes, 50 per point
    SPARSE,     // 100K attributes, 50 per point
    VERY_SPARSE // 100K attributes, 5 per point
};

struct ScenarioParams {
    size_t total_attributes;
    size_t attrs_per_point;
    std::string name;
};

const ScenarioParams SCENARIOS[] = {
    {1000, 50, "Dense"},
    {100000, 50, "Sparse"},
    {100000, 5, "Very_Sparse"}
};

class FilterBenchmark : public benchmark::Fixture {
protected:
    std::vector<hnswlib::labeltype> points;
    std::mt19937 gen;
    std::uniform_int_distribution<unsigned int> dis_attr;
    
    filtering::NaiveFilter naive_filter;
    filtering::BitsetFilter bitset_filter;
    filtering::RoaringFilter roaring_filter;
    
    void SetUp(const benchmark::State& state) {
        gen.seed(42);
        int scenario_idx = state.range(1);
        const auto& scenario = SCENARIOS[scenario_idx];
        
        dis_attr = std::uniform_int_distribution<unsigned int>(0, scenario.total_attributes - 1);
        points.resize(state.range(0));
        
        for (size_t i = 0; i < points.size(); i++) {
            points[i] = i;
            std::vector<bool> used_attrs(scenario.total_attributes, false);
            
            for (size_t j = 0; j < scenario.attrs_per_point; j++) {
                unsigned int attr;
                do {
                    attr = dis_attr(gen);
                } while (used_attrs[attr]);
                
                used_attrs[attr] = true;
                naive_filter.addAttribute(i, attr);
                bitset_filter.addAttribute(i, attr);
                roaring_filter.addAttribute(i, attr);
            }
        }
    }
};

// Naive Filter Benchmarks
BENCHMARK_DEFINE_F(FilterBenchmark, NaiveFilterSingle)(benchmark::State& state) {
    std::vector<unsigned int> query_attrs = {dis_attr(gen)};
    naive_filter.setQueryAttributes(query_attrs);
    
    for (auto _ : state) {
        for (auto point : points) {
            benchmark::DoNotOptimize(naive_filter(point));
        }
    }
    
    state.SetItemsProcessed(state.iterations() * points.size());
    state.SetLabel(SCENARIOS[state.range(1)].name);
}

// Bitset Filter Benchmarks
BENCHMARK_DEFINE_F(FilterBenchmark, BitsetFilterSingle)(benchmark::State& state) {
    std::vector<unsigned int> query_attrs = {dis_attr(gen)};
    bitset_filter.setQueryAttributes(query_attrs);
    
    for (auto _ : state) {
        for (auto point : points) {
            benchmark::DoNotOptimize(bitset_filter(point));
        }
    }
    
    state.SetItemsProcessed(state.iterations() * points.size());
    state.SetLabel(SCENARIOS[state.range(1)].name);
}

// Roaring Filter Benchmarks
BENCHMARK_DEFINE_F(FilterBenchmark, RoaringFilterSingle)(benchmark::State& state) {
    std::vector<unsigned int> query_attrs = {dis_attr(gen)};
    roaring_filter.setQueryAttributes(query_attrs);
    
    for (auto _ : state) {
        for (auto point : points) {
            benchmark::DoNotOptimize(roaring_filter(point));
        }
    }
    
    state.SetItemsProcessed(state.iterations() * points.size());
    state.SetLabel(SCENARIOS[state.range(1)].name);
}

// Multi-attribute benchmarks
BENCHMARK_DEFINE_F(FilterBenchmark, NaiveFilterMulti)(benchmark::State& state) {
    std::vector<unsigned int> query_attrs = {dis_attr(gen), dis_attr(gen)};
    naive_filter.setQueryAttributes(query_attrs);
    
    for (auto _ : state) {
        for (auto point : points) {
            benchmark::DoNotOptimize(naive_filter(point));
        }
    }
    
    state.SetItemsProcessed(state.iterations() * points.size());
    state.SetLabel(SCENARIOS[state.range(1)].name);
}

BENCHMARK_DEFINE_F(FilterBenchmark, BitsetFilterMulti)(benchmark::State& state) {
    std::vector<unsigned int> query_attrs = {dis_attr(gen), dis_attr(gen)};
    bitset_filter.setQueryAttributes(query_attrs);
    
    for (auto _ : state) {
        for (auto point : points) {
            benchmark::DoNotOptimize(bitset_filter(point));
        }
    }
    
    state.SetItemsProcessed(state.iterations() * points.size());
    state.SetLabel(SCENARIOS[state.range(1)].name);
}

BENCHMARK_DEFINE_F(FilterBenchmark, RoaringFilterMulti)(benchmark::State& state) {
    std::vector<unsigned int> query_attrs = {dis_attr(gen), dis_attr(gen)};
    roaring_filter.setQueryAttributes(query_attrs);
    
    for (auto _ : state) {
        for (auto point : points) {
            benchmark::DoNotOptimize(roaring_filter(point));
        }
    }
    
    state.SetItemsProcessed(state.iterations() * points.size());
    state.SetLabel(SCENARIOS[state.range(1)].name);
}

// Register all benchmarks
void RegisterBenchmarks() {
    std::vector<int64_t> sizes = {8, 64, 512, 4096, 8192, 16384};
    
    for (int64_t scenario_idx = 0; scenario_idx < 3; scenario_idx++) {
        for (auto size : sizes) {
            // Single attribute queries
            BENCHMARK_REGISTER_F(FilterBenchmark, NaiveFilterSingle)
                ->Args({size, scenario_idx})
                ->Unit(benchmark::kMicrosecond);
            BENCHMARK_REGISTER_F(FilterBenchmark, BitsetFilterSingle)
                ->Args({size, scenario_idx})
                ->Unit(benchmark::kMicrosecond);
            BENCHMARK_REGISTER_F(FilterBenchmark, RoaringFilterSingle)
                ->Args({size, scenario_idx})
                ->Unit(benchmark::kMicrosecond);
            
            // Multi attribute queries
            BENCHMARK_REGISTER_F(FilterBenchmark, NaiveFilterMulti)
                ->Args({size, scenario_idx})
                ->Unit(benchmark::kMicrosecond);
            BENCHMARK_REGISTER_F(FilterBenchmark, BitsetFilterMulti)
                ->Args({size, scenario_idx})
                ->Unit(benchmark::kMicrosecond);
            BENCHMARK_REGISTER_F(FilterBenchmark, RoaringFilterMulti)
                ->Args({size, scenario_idx})
                ->Unit(benchmark::kMicrosecond);
        }
    }
}

int main(int argc, char** argv) {
    RegisterBenchmarks();
    ::benchmark::Initialize(&argc, argv);
    ::benchmark::RunSpecifiedBenchmarks();
    return 0;
}