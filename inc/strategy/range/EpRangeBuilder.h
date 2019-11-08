#ifndef EP_RANGE_BUILDER_H
#define EP_RANGE_BUILDER_H

#include <strategy/range/RangeBuilder.h>

class EpRangeBuilder : public RangeBuilder
{
public:
    EpRangeBuilder() : RangeBuilder(2.5) {}
    Range buildRfiRange() override          { rangeCreator_.createRange("AJ+,ATs,A5s,A4s,A3s,A2s,KQ+,KJs,66+,T9s,98s"); }
    Range buildColdCallRange() override     {} //not applicable in this Position
    Range build3bRange() override           {} //not applicable in this Position
    Range buildVs3bCallRange() override     { rangeCreator_.createRange("AK+,AQs,QQ,JJ"); }
    Range buildVsSqzCallRange() override    { rangeCreator_.createRange("AQ+,AJs,QQ-66"); }
    Range build4bRange() override           { rangeCreator_.createRange("KK+,AJs"); }
    Range buildVs4bCallRange() override     {} //not applicable in this Position
    Range buildBrokeRange() override        { rangeCreator_.createRange("KK+"); }
    ~EpRangeBuilder() = default;
};

#endif //EP_RANGE_BUILDER_H
