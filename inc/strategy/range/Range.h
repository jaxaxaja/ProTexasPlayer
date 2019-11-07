#ifndef RANGE_H
#define RANGE_H

#include "Hand.h"
#include <set>
#include <vector>

class Range
{
    struct Comparator{
        bool operator()(const Hand& lhs, const Hand& rhs) const { return lhs.operatorLess(rhs); }
    };
    std::set<Hand, Comparator> range_;

public:
    Range() = default;
    Range(const std::vector<Hand>& v) { std::move(v.begin(), v.end(), std::inserter(range_, range_.begin())); }
    bool insert(const Hand& h) { return range_.insert(h).second; }
    void insert(const std::vector<Hand>& v) { std::move(v.begin(), v.end(), std::inserter(range_, range_.begin())); }
    bool isInRange(Hand h) const { return range_.find(h) != range_.end(); }
    size_t combinations() const {return range_.size(); }
};

#endif // RANGE_H
