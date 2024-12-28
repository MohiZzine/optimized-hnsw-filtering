#pragma once
#include <vector>
#include "../../external/hnswlib/hnswlib.h"

namespace filtering {

class BaseFilter : public hnswlib::BaseFilterFunctor {
public:
    // Override from HNSW's base filter
    virtual bool operator()(hnswlib::labeltype label_id) override = 0;

    // Our additional interface methods
    virtual bool hasAttribute(hnswlib::labeltype point_id, unsigned int attr_id) const = 0;
    virtual bool hasAttributes(hnswlib::labeltype point_id, const std::vector<unsigned int>& attrs) const = 0;
    
    // Add/Remove attributes for a point
    virtual void addAttribute(hnswlib::labeltype point_id, unsigned int attr_id) = 0;
    virtual void removeAttribute(hnswlib::labeltype point_id, unsigned int attr_id) = 0;
    
    virtual ~BaseFilter() = default;
};

} // namespace filtering