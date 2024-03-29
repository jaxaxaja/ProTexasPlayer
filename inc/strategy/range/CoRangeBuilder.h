#ifndef CO_RANGE_BUILDER_H
#define CO_RANGE_BUILDER_H

#include <strategy/range/RangeBuilder.h>

class CoRangeBuilder : public RangeBuilder
{
public:
    CoRangeBuilder() : RangeBuilder(2.2f, 3.2f, 2.3f) {}
    Range buildRfiRange() override { return rangeCreator_.createRange("A8+,A7s,A6s,A5s,A4s,A3s,A2s,KT+,K9s,QT+,Q9s,22+,JTs,"
                                                                      "J9s,T9s,T8s,98s,97s,87s,86s,76s,75s,65s,64s,54s"); }
    std::map<Position, Range> buildColdCallRange() override;
    std::map<Position, Range> build3bRange() override;
    std::map<Position, Range> buildVs3bCallRange() override;
    std::map<Position, Range> buildVsSqzCallRange() override;
    std::map<Position, Range> build4bRange() override;
    std::map<Position, Range> buildVs4bCallRange() override;
    std::map<Position, Range> buildBrokeRange() override;
    ~CoRangeBuilder() override = default;
};

#endif //CO_RANGE_BUILDER_H
