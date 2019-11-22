#ifndef BB_RANGE_BUILDER_H
#define BB_RANGE_BUILDER_H

#include <strategy/range/RangeBuilder.h>

class BbRangeBuilder : public RangeBuilder
{
public:
    BbRangeBuilder() : RangeBuilder(3, 3.5, 2.3) {}
    Range buildRfiRange() override { rangeCreator_.createRange("A2+,K8+,K7s,K6s,Q9+,Q8s,Q7s,22+,JTs,J9s,J8s,J7s,T9s,"
                                                               "T8s,T7s,98s,97s,96s,87s,86s,85s,76s,75s,74s,65s,64s,"
                                                               "54s,53s,43s,42s,32s"); }
    std::map<Position, Range> buildColdCallRange() override;
    std::map<Position, Range> build3bRange() override;
    std::map<Position, Range> buildVs3bCallRange() override;
    std::map<Position, Range> buildVsSqzCallRange() override;
    std::map<Position, Range> build4bRange() override;
    std::map<Position, Range> buildVs4bCallRange() override;
    std::map<Position, Range> buildBrokeRange() override;
    ~BbRangeBuilder() = default;
};

#endif //BB_RANGE_BUILDER_H
