#include "naive_filter.h"
#include <algorithm>

namespace filtering {

NaiveFilter::NaiveFilter() : total_operations_(0), total_time_ms_(0) {}

NaiveFilter::NaiveFilter(const std::vector<unsigned int>& query_attributes) 
    : query_attributes_(query_attributes), total_operations_(0), total_time_ms_(0) {}

bool NaiveFilter::operator()(hnswlib::labeltype label_id) {
    last_operation_start_ = std::chrono::high_resolution_clock::now();
    
    bool result = hasAttributes(label_id, query_attributes_);
    
    auto end = std::chrono::high_resolution_clock::now();
    last_operation_time_ms_ = std::chrono::duration<double, std::milli>(end - last_operation_start_).count();
    total_time_ms_ += last_operation_time_ms_;
    total_operations_++;
    
    return result;
}

bool NaiveFilter::hasAttribute(hnswlib::labeltype point_id, unsigned int attr_id) const {
    last_operation_start_ = std::chrono::high_resolution_clock::now();
    
    auto it = point_attributes_.find(point_id);
    bool result = (it != point_attributes_.end() && it->second.count(attr_id) > 0);
    
    auto end = std::chrono::high_resolution_clock::now();
    last_operation_time_ms_ = std::chrono::duration<double, std::milli>(end - last_operation_start_).count();
    total_time_ms_ += last_operation_time_ms_;
    total_operations_++;
    
    return result;
}

bool NaiveFilter::hasAttributes(hnswlib::labeltype point_id, 
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

    bool result = std::all_of(attrs.begin(), attrs.end(),
        [&](unsigned int attr) { return it->second.count(attr) > 0; });
    
    auto end = std::chrono::high_resolution_clock::now();
    last_operation_time_ms_ = std::chrono::duration<double, std::milli>(end - last_operation_start_).count();
    total_time_ms_ += last_operation_time_ms_;
    total_operations_++;
    
    return result;
}

void NaiveFilter::addAttribute(hnswlib::labeltype point_id, unsigned int attr_id) {
    last_operation_start_ = std::chrono::high_resolution_clock::now();
    
    point_attributes_[point_id].insert(attr_id);
    
    auto end = std::chrono::high_resolution_clock::now();
    last_operation_time_ms_ = std::chrono::duration<double, std::milli>(end - last_operation_start_).count();
    total_time_ms_ += last_operation_time_ms_;
    total_operations_++;
}

void NaiveFilter::removeAttribute(hnswlib::labeltype point_id, unsigned int attr_id) {
    last_operation_start_ = std::chrono::high_resolution_clock::now();
    
    auto it = point_attributes_.find(point_id);
    if (it != point_attributes_.end()) {
        it->second.erase(attr_id);
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    last_operation_time_ms_ = std::chrono::duration<double, std::milli>(end - last_operation_start_).count();
    total_time_ms_ += last_operation_time_ms_;
    total_operations_++;
}

void NaiveFilter::setQueryAttributes(const std::vector<unsigned int>& attributes) {
    query_attributes_ = attributes;
}

double NaiveFilter::getLastOperationTimeMs() const {
    return last_operation_time_ms_;
}

uint64_t NaiveFilter::getTotalOperations() const {
    return total_operations_;
}

double NaiveFilter::getAverageOperationTimeMs() const {
    return total_operations_ > 0 ? total_time_ms_ / total_operations_ : 0.0;
}

} // namespace filtering