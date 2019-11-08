#ifndef POSITIONAL_RANGE_H
#define POSITIONAL_RANGE_H

#include <strategy/range/Range.h>
#include "Position.h"
#include <map>

class PositionalRange
{
    Range rfi_;
    Range coldCall_; //j.n.
    /*std::map<Position,*/ Range/*>*/ threeBet_; //to powinno byc z podzialem vs konkretna pozycja
    Range vs3betCall_; //j.w itd.
    Range vsSqzCall_;
    Range fourBet_;
    Range vs4betCall_;
    Range broke_;
    float rfiSize_;

public:
    PositionalRange(const Position position);
    bool isInRfi(Hand h) { return rfi_.isInRange(h); }
    bool isInColdCall(Hand h) { return coldCall_.isInRange(h); }
    bool isInThreeBet(Hand h) { return threeBet_.isInRange(h); }
    bool isInVs3betCall(Hand h) { return vs3betCall_.isInRange(h); }
    bool isInVsSqzCall(Hand h) { return vsSqzCall_.isInRange(h); }
    bool isInFourBet(Hand h) { return fourBet_.isInRange(h); }
    bool isInVs4betCall(Hand h) { return vs4betCall_.isInRange(h); }
    bool isInBroke(Hand h) { return broke_.isInRange(h); }
    float getRfiSize() const { return rfiSize_; }
};

#endif //POSITIONAL_RANGE_H
