#define ROARING_AMALGAMATION
#include "roaring.c"  // Include the implementation here
#include "roaring_filter.h"
#include <stdexcept>

namespace filtering {

RoaringFilter::RoaringFilter() : total_operations_(0), total_time_ms_(0) {}

RoaringFilter::RoaringFilter(const std::vector<unsigned int>& query_attributes) 
    : total_operations_(0), total_time_ms_(0) {
    setQueryAttributes(query_attributes);
}

bool RoaringFilter::operator()(hnswlib::labeltype label_id) {
    last_operation_start_ = std::chrono::high_resolution_clock::now();
    
    auto it = point_attributes_.find(label_id);
    bool result = false;
    
    if (it != point_attributes_.end()) {
        // Check if all query bits are present in point's bitmap
        result = query_bitmap_.isSubset(it->second);
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    last_operation_time_ms_ = std::chrono::duration<double, std::milli>(end - last_operation_start_).count();
    total_time_ms_ += last_operation_time_ms_;
    total_operations_++;
    
    return result;
}

bool RoaringFilter::hasAttribute(hnswlib::labeltype point_id, unsigned int attr_id) const {
    last_operation_start_ = std::chrono::high_resolution_clock::now();
    
    auto it = point_attributes_.find(point_id);
    bool result = (it != point_attributes_.end() && it->second.contains(attr_id));
    
    auto end = std::chrono::high_resolution_clock::now();
    last_operation_time_ms_ = std::chrono::duration<double, std::milli>(end - last_operation_start_).count();
    total_time_ms_ += last_operation_time_ms_;
    total_operations_++;
    
    return result;
}

bool RoaringFilter::hasAttributes(hnswlib::labeltype point_id, 
                                const std::vector<unsigned int>& attrs) const {
    last_operation_start_ = std::chrono::high_resolution_clock::now();
    
    auto it = point_attributes_.find(point_id);
    if (it == point_attributes_.end()) {
        auto end = std::chrono::high_resolution_clock::now();
        last_operation_time_ms_ = std::chrono::duration<double, std::milli>(end - last_operation_start_).count();
        total_time_ms_ += last_operation_time_ms_;
        total_operations_++;
        return false;
    }

    roaring::Roaring query;
    for (unsigned int attr : attrs) {
        query.add(attr);
    }
    
    bool result = query.isSubset(it->second);
    
    auto end = std::chrono::high_resolution_clock::now();
    last_operation_time_ms_ = std::chrono::duration<double, std::milli>(end - last_operation_start_).count();
    total_time_ms_ += last_operation_time_ms_;
    total_operations_++;
    
    return result;
}

void RoaringFilter::addAttribute(hnswlib::labeltype point_id, unsigned int attr_id) {
    last_operation_start_ = std::chrono::high_resolution_clock::now();
    
    point_attributes_[point_id].add(attr_id);
    
    auto end = std::chrono::high_resolution_clock::now();
    last_operation_time_ms_ = std::chrono::duration<double, std::milli>(end - last_operation_start_).count();
    total_time_ms_ += last_operation_time_ms_;
    total_operations_++;
}

void RoaringFilter::removeAttribute(hnswlib::labeltype point_id, unsigned int attr_id) {
    last_operation_start_ = std::chrono::high_resolution_clock::now();
    
    auto it = point_attributes_.find(point_id);
    if (it != point_attributes_.end()) {
        it->second.remove(attr_id);
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    last_operation_time_ms_ = std::chrono::duration<double, std::milli>(end - last_operation_start_).count();
    total_time_ms_ += last_operation_time_ms_;
    total_operations_++;
}

void RoaringFilter::setQueryAttributes(const std::vector<unsigned int>& attributes) {
    query_bitmap_ = roaring::Roaring();
    for (unsigned int attr : attributes) {
        query_bitmap_.add(attr);
    }
}

size_t RoaringFilter::getNumAttributes(hnswlib::labeltype point_id) const {
    auto it = point_attributes_.find(point_id);
    return it != point_attributes_.end() ? it->second.cardinality() : 0;
}

size_t RoaringFilter::getCardinality(hnswlib::labeltype point_id) const {
    auto it = point_attributes_.find(point_id);
    return it != point_attributes_.end() ? it->second.cardinality() : 0;
}

double RoaringFilter::getLastOperationTimeMs() const {
    return last_operation_time_ms_;
}

uint64_t RoaringFilter::getTotalOperations() const {
    return total_operations_;
}

double RoaringFilter::getAverageOperationTimeMs() const {
    return total_operations_ > 0 ? total_time_ms_ / total_operations_ : 0.0;
}

size_t RoaringFilter::getMemoryUsage() const {
    size_t total = 0;
    for (const auto& pair : point_attributes_) {
        total += pair.second.getSizeInBytes();
    }
    return total;
}

} // namespace filtering