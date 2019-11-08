#ifndef CO_RANGE_BUILDER_H
#define CO_RANGE_BUILDER_H

#include <strategy/range/RangeBuilder.h>

class CoRangeBuilder : public RangeBuilder
{
public:
    Range buildRfiRange() override { rangeCreator_.createRange("A8+,A7s,A6s,A5s,A4s,A3s,A2s,KT+,K9s,QT+,Q9s,22+,JTs,J9s,T9s,T8s,98s,97s,87s,86s,76s,75s,65s,64s,54s"); }
    Range buildColdCallRange() override {}
    Range build3bRange() override {}
    Range buildVs3bCallRange() override {}
    Range buildVsSqzCallRange() override {}
    Range build4bRange() override {}
    Range buildVs4bCallRange() override {}
    Range buildBrokeRange() override {}
    ~CoRangeBuilder() = default;
};

#endif //CO_RANGE_BUILDER_H
