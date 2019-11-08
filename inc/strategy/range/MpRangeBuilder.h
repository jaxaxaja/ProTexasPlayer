#ifndef MP_RANGE_BUILDER_H
#define MP_RANGE_BUILDER_H

#include <strategy/range/RangeBuilder.h>

class MpRangeBuilder : public RangeBuilder
{
public:
    Range buildRfiRange() override { rangeCreator_.createRange("AT+,A5s,A4s,A3s,A2s,KJ+,KTs,QJs,55+,JTs,T9s,98s,87s,76s"); }
    Range buildColdCallRange() override {}
    Range build3bRange() override {}
    Range buildVs3bCallRange() override {}
    Range buildVsSqzCallRange() override {}
    Range build4bRange() override {}
    Range buildVs4bCallRange() override {}
    Range buildBrokeRange() override {}
    ~MpRangeBuilder() = default;
};

#endif //MP_RANGE_BUILDER_H
