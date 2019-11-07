#ifndef RANGE_BUILDER_H
#define RANGE_BUILDER_H

#include <strategy/range/Range.h>

class RangeBuilder
{
public:
    virtual Range buildRfiRange() = 0;
    virtual Range buildColdCallRange() = 0;
    virtual Range build3bRange() = 0;
    virtual Range buildVs3bCallRange() = 0;
    virtual Range buildVsSqzCallRange() = 0;
    virtual Range build4bRange() = 0;
    virtual Range buildVs4bCallRange() = 0;
    virtual Range buildBrokeRange() = 0;
    virtual ~RangeBuilder() = default;
};

#endif //RANGE_BUILDER_H
