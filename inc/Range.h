#ifndef RANGE_H
#define RANGE_H

#include "Hand.h"
#include <set>

class Range
{
public:
    Range();
private:
    std::set<Hand> range_;
};

#endif // RANGE_H
