#include <strategy/range/PositionalRange.h>

PositionalRange::PositionalRange(std::unique_ptr<RangeBuilder> builder)
{
    rfi_ = builder->buildRfiRange();
    coldCall_ = builder->buildColdCallRange();
    threeBet_ = builder->build3bRange();
    vs3betCall_ = builder->buildVs3bCallRange();
    vsSqzCall_ = builder->buildVsSqzCallRange();
    fourBet_ = builder->build4bRange();
    vs4betCall_ = builder->buildVs4bCallRange();
    broke_ = builder->buildBrokeRange();
}