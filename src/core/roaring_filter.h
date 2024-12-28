#pragma once
#include "filter_interface.h"
#include "../../external/roaring/roaring.hh"  // Keep this as we're using C++ interface
#include <unordered_map>
#include <chrono>

namespace filtering {

class RoaringFilter : public BaseFilter {
public:
    RoaringFilter();
    RoaringFilter(const std::vector<unsigned int>& query_attributes);
    
    // BaseFilter interface implementation
    bool operator()(hnswlib::labeltype label_id) override;
    bool hasAttribute(hnswlib::labeltype point_id, unsigned int attr_id) const override;
    bool hasAttributes(hnswlib::labeltype point_id, const std::vector<unsigned int>& attrs) const override;
    void addAttribute(hnswlib::labeltype point_id, unsigned int attr_id) override;
    void removeAttribute(hnswlib::labeltype point_id, unsigned int attr_id) override;

    // Additional functionality
    void setQueryAttributes(const std::vector<unsigned int>& attributes);
    size_t getNumAttributes(hnswlib::labeltype point_id) const;
    size_t getCardinality(hnswlib::labeltype point_id) const;
    
    // Performance metrics
    double getLastOperationTimeMs() const;
    uint64_t getTotalOperations() const;
    double getAverageOperationTimeMs() const;
    size_t getMemoryUsage() const;

private:
    // Data storage: point_id -> roaring bitmap of attributes
    std::unordered_map<hnswlib::labeltype, roaring::Roaring> point_attributes_;
    
    // Query bitmap
    roaring::Roaring query_bitmap_;

    // Performance tracking
    mutable std::chrono::high_resolution_clock::time_point last_operation_start_;
    mutable double last_operation_time_ms_;
    mutable uint64_t total_operations_;
    mutable double total_time_ms_;
};

} // namespace filtering