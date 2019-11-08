#ifndef RANGE_BUILDER_H
#define RANGE_BUILDER_H

#include <strategy/range/Range.h>
#include <strategy/range/RangeCreator.h>
#include "Position.h"
#include <memory>

class RangeBuilder
{
protected:
    RangeCreator rangeCreator_;
    float rfiSize_;
public:
    RangeBuilder(float rfiSize) : rfiSize_(rfiSize) {}
    static std::unique_ptr<RangeBuilder> createBuilder(const Position& position);
    virtual Range buildRfiRange() = 0;
    virtual Range buildColdCallRange() = 0;
    virtual Range build3bRange() = 0;
    virtual Range buildVs3bCallRange() = 0;
    virtual Range buildVsSqzCallRange() = 0;
    virtual Range build4bRange() = 0;
    virtual Range buildVs4bCallRange() = 0;
    virtual Range buildBrokeRange() = 0;
    float getRfiSize() const { return rfiSize_; }
    virtual ~RangeBuilder() = default;
};

#endif //RANGE_BUILDER_H
