#include "bitset_filter.h"
#include <stdexcept>

namespace filtering {

BitsetFilter::BitsetFilter() : total_operations_(0), total_time_ms_(0) {}

BitsetFilter::BitsetFilter(const std::vector<unsigned int>& query_attributes) 
    : total_operations_(0), total_time_ms_(0) {
    setQueryAttributes(query_attributes);
}

bool BitsetFilter::operator()(hnswlib::labeltype label_id) {
    last_operation_start_ = std::chrono::high_resolution_clock::now();
    
    auto it = point_attributes_.find(label_id);
    bool result = false;
    
    if (it != point_attributes_.end()) {
        // Check if all query bits are set in point's bitset
        result = (it->second & query_bitset_) == query_bitset_;
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    last_operation_time_ms_ = std::chrono::duration<double, std::milli>(end - last_operation_start_).count();
    total_time_ms_ += last_operation_time_ms_;
    total_operations_++;
    
    return result;
}

bool BitsetFilter::hasAttribute(hnswlib::labeltype point_id, unsigned int attr_id) const {
    validateAttributeId(attr_id);
    
    last_operation_start_ = std::chrono::high_resolution_clock::now();
    
    auto it = point_attributes_.find(point_id);
    bool result = (it != point_attributes_.end() && it->second[attr_id]);
    
    auto end = std::chrono::high_resolution_clock::now();
    last_operation_time_ms_ = std::chrono::duration<double, std::milli>(end - last_operation_start_).count();
    total_time_ms_ += last_operation_time_ms_;
    total_operations_++;
    
    return result;
}

bool BitsetFilter::hasAttributes(hnswlib::labeltype point_id, 
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

    AttributeBitset query;
    for (unsigned int attr : attrs) {
        validateAttributeId(attr);
        query.set(attr);
    }
    
    bool result = (it->second & query) == query;
    
    auto end = std::chrono::high_resolution_clock::now();
    last_operation_time_ms_ = std::chrono::duration<double, std::milli>(end - last_operation_start_).count();
    total_time_ms_ += last_operation_time_ms_;
    total_operations_++;
    
    return result;
}

void BitsetFilter::addAttribute(hnswlib::labeltype point_id, unsigned int attr_id) {
    validateAttributeId(attr_id);
    
    last_operation_start_ = std::chrono::high_resolution_clock::now();
    
    point_attributes_[point_id].set(attr_id);
    
    auto end = std::chrono::high_resolution_clock::now();
    last_operation_time_ms_ = std::chrono::duration<double, std::milli>(end - last_operation_start_).count();
    total_time_ms_ += last_operation_time_ms_;
    total_operations_++;
}

void BitsetFilter::removeAttribute(hnswlib::labeltype point_id, unsigned int attr_id) {
    validateAttributeId(attr_id);
    
    last_operation_start_ = std::chrono::high_resolution_clock::now();
    
    auto it = point_attributes_.find(point_id);
    if (it != point_attributes_.end()) {
        it->second.reset(attr_id);
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    last_operation_time_ms_ = std::chrono::duration<double, std::milli>(end - last_operation_start_).count();
    total_time_ms_ += last_operation_time_ms_;
    total_operations_++;
}

void BitsetFilter::setQueryAttributes(const std::vector<unsigned int>& attributes) {
    query_bitset_.reset();
    for (unsigned int attr : attributes) {
        validateAttributeId(attr);
        query_bitset_.set(attr);
    }
}

size_t BitsetFilter::getNumAttributes(hnswlib::labeltype point_id) const {
    auto it = point_attributes_.find(point_id);
    return it != point_attributes_.end() ? it->second.count() : 0;
}

double BitsetFilter::getLastOperationTimeMs() const {
    return last_operation_time_ms_;
}

uint64_t BitsetFilter::getTotalOperations() const {
    return total_operations_;
}

double BitsetFilter::getAverageOperationTimeMs() const {
    return total_operations_ > 0 ? total_time_ms_ / total_operations_ : 0.0;
}

void BitsetFilter::validateAttributeId(unsigned int attr_id) const {
    if (attr_id >= MAX_ATTRIBUTES) {
        throw std::out_of_range("Attribute ID exceeds maximum allowed value");
    }
}

} // namespace filtering