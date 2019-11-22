#ifndef MP_RANGE_BUILDER_H
#define MP_RANGE_BUILDER_H

#include <strategy/range/RangeBuilder.h>

class MpRangeBuilder : public RangeBuilder
{
public:
    MpRangeBuilder() : RangeBuilder(2.5f, 3.4f, 2.3f) {}
    Range buildRfiRange() override {return  rangeCreator_.createRange("AT+,A5s,A4s,A3s,A2s,KJ+,KTs,"
                                                                      "QJs,55+,JTs,T9s,98s,87s,76s"); }
    std::map<Position, Range> buildColdCallRange() override;
    std::map<Position, Range> build3bRange() override;
    std::map<Position, Range> buildVs3bCallRange() override;
    std::map<Position, Range> buildVsSqzCallRange() override;
    std::map<Position, Range> build4bRange() override;
    std::map<Position, Range> buildVs4bCallRange() override;
    std::map<Position, Range> buildBrokeRange() override;
    ~MpRangeBuilder() override = default;
};

#endif //MP_RANGE_BUILDER_H
