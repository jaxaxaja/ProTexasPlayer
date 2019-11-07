#ifndef POSITIONAL_RANGE_H
#define POSITIONAL_RANGE_H

#include <strategy/range/Range.h>
#include <strategy/range/RangeBuilder.h>
#include <memory>

class PositionalRange
{
    Range rfi_;
    Range coldCall_;
    Range threeBet_;
    Range vs3betCall_;
    Range vsSqzCall_;
    Range fourBet_;
    Range vs4betCall_;
    Range broke_;

public:
    PositionalRange(std::unique_ptr<RangeBuilder> builder);
    bool isInRfi(Hand h) { return rfi_.isInRange(h); }
    bool isInColdCall(Hand h) { return coldCall_.isInRange(h); }
    bool isInThreeBet(Hand h) { return threeBet_.isInRange(h); }
    bool isInVs3betCall(Hand h) { return vs3betCall_.isInRange(h); }
    bool isInVsSqzCall(Hand h) { return vsSqzCall_.isInRange(h); }
    bool isInFourBet(Hand h) { return fourBet_.isInRange(h); }
    bool isInVs4betCall(Hand h) { return vs4betCall_.isInRange(h); }
    bool isInBroke(Hand h) { return broke_.isInRange(h); }
};

#endif //POSITIONAL_RANGE_H
