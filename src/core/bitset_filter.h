#pragma once
#include "filter_interface.h"
#include <bitset>
#include <unordered_map>
#include <chrono>

namespace filtering {

// Using 1024 bits to support up to 1024 attributes (can be adjusted)
constexpr size_t MAX_ATTRIBUTES = 1024;
using AttributeBitset = std::bitset<MAX_ATTRIBUTES>;

class BitsetFilter : public BaseFilter {
public:
    BitsetFilter();
    BitsetFilter(const std::vector<unsigned int>& query_attributes);
    
    // BaseFilter interface implementation
    bool operator()(hnswlib::labeltype label_id) override;
    bool hasAttribute(hnswlib::labeltype point_id, unsigned int attr_id) const override;
    bool hasAttributes(hnswlib::labeltype point_id, const std::vector<unsigned int>& attrs) const override;
    void addAttribute(hnswlib::labeltype point_id, unsigned int attr_id) override;
    void removeAttribute(hnswlib::labeltype point_id, unsigned int attr_id) override;

    // Additional functionality
    void setQueryAttributes(const std::vector<unsigned int>& attributes);
    size_t getNumAttributes(hnswlib::labeltype point_id) const;
    
    // Performance metrics
    double getLastOperationTimeMs() const;
    uint64_t getTotalOperations() const;
    double getAverageOperationTimeMs() const;

private:
    // Data storage: point_id -> bitset of attributes
    std::unordered_map<hnswlib::labeltype, AttributeBitset> point_attributes_;
    
    // Query bitset
    AttributeBitset query_bitset_;

    // Performance tracking
    mutable std::chrono::high_resolution_clock::time_point last_operation_start_;
    mutable double last_operation_time_ms_;
    mutable uint64_t total_operations_;
    mutable double total_time_ms_;

    // Helper function to validate attribute ID
    void validateAttributeId(unsigned int attr_id) const;
};

} // namespace filtering