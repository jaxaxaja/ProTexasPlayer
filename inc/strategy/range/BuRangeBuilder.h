#ifndef BU_RANGE_BUILDER_H
#define BU_RANGE_BUILDER_H

#include <strategy/range/RangeBuilder.h>

class BuRangeBuilder : public RangeBuilder
{
public:
    Range buildRfiRange() override { rangeCreator_.createRange("A2+,K8+,K7s,K6s,Q9+,Q8s,Q7s,22+,JTs,J9s,J8s,J7s,T9s,T8s,T7s,98s,97s,96s,87s,86s,85s,76s,75s,74s,65s,64s,54s,53s,43s,42s,32s"); }
    Range buildColdCallRange() override {}
    Range build3bRange() override {}
    Range buildVs3bCallRange() override {}
    Range buildVsSqzCallRange() override {}
    Range build4bRange() override {}
    Range buildVs4bCallRange() override {}
    Range buildBrokeRange() override {}
    ~BuRangeBuilder() = default;
};

#endif //BU_RANGE_BUILDER_H
