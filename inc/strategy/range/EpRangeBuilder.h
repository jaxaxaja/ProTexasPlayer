#ifndef EP_RANGE_BUILDER_H
#define EP_RANGE_BUILDER_H

#include <strategy/range/RangeBuilder.h>

class EpRangeBuilder : public RangeBuilder
{
public:
    EpRangeBuilder() : RangeBuilder(2.5, 0, 2.3) {}
    Range buildRfiRange() override { return rangeCreator_.createRange("AJ+,ATs,A5s,A4s,A3s,A2s,KQ+,KJs,66+,T9s,98s"); }
    std::map<Position, Range> buildColdCallRange() override    { return {}; } //not applicable in this Position
    std::map<Position, Range> build3bRange() override          { return {}; } //not applicable in this Position
    std::map<Position, Range> buildVs3bCallRange() override;
    std::map<Position, Range> buildVsSqzCallRange() override;
    std::map<Position, Range> build4bRange() override;
    std::map<Position, Range> buildVs4bCallRange() override;
    std::map<Position, Range> buildBrokeRange() override;
    ~EpRangeBuilder() = default;
};

#endif //EP_RANGE_BUILDER_H
