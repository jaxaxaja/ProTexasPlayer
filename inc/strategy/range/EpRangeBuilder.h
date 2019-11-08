#ifndef EP_RANGE_BUILDER_H
#define EP_RANGE_BUILDER_H

#include <strategy/range/RangeBuilder.h>

class EpRangeBuilder : public RangeBuilder
{
public:
    Range buildRfiRange() override { rangeCreator_.createRange("AJ+,ATs,A5s,A4s,A3s,A2s,KQ+,KJs,66+,T9s,98s"); }
    Range buildColdCallRange() override {}
    Range build3bRange() override {}
    Range buildVs3bCallRange() override {}
    Range buildVsSqzCallRange() override {}
    Range build4bRange() override {}
    Range buildVs4bCallRange() override {}
    Range buildBrokeRange() override {}
    ~EpRangeBuilder() = default;
};

#endif //EP_RANGE_BUILDER_H
