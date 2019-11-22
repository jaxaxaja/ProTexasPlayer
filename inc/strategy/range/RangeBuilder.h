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
    float threeBetSize_;
    float fourBetSize_;
public:
    RangeBuilder(float rfiSize, float threeBetSize, float fourBetSize) : rfiSize_(rfiSize),
        threeBetSize_(threeBetSize), fourBetSize_(fourBetSize) {}
    static std::unique_ptr<RangeBuilder> createBuilder(const Position& position);
    virtual Range buildRfiRange() = 0;
    virtual std::map<Position, Range> buildColdCallRange() = 0;
    virtual std::map<Position, Range> build3bRange() = 0;
    virtual std::map<Position, Range> buildVs3bCallRange() = 0;
    virtual std::map<Position, Range> buildVsSqzCallRange() = 0;
    virtual std::map<Position, Range> build4bRange() = 0;
    virtual std::map<Position, Range> buildVs4bCallRange() = 0;
    virtual std::map<Position, Range> buildBrokeRange() = 0;
    float getRfiSize() const { return rfiSize_; }
    float get3BetSize() const { return threeBetSize_; }
    float get4BetSize() const { return fourBetSize_; }
    virtual ~RangeBuilder() = default;
};

#endif //RANGE_BUILDER_H
