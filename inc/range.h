#ifndef RANGE_H
#define RANGE_H

#include "hand.h"
#include <set>

class Range
{
public:
    Range();
private:
    std::set<Hand> range_;
};

#endif // RANGE_H
