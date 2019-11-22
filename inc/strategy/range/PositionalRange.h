#ifndef POSITIONAL_RANGE_H
#define POSITIONAL_RANGE_H

#include <strategy/range/Range.h>
#include "Position.h"
#include <map>

class PositionalRange
{
    Range rfi_;
    std::map<Position, Range> coldCall_;
    std::map<Position, Range> threeBet_;
    std::map<Position, Range> vs3betCall_;
    std::map<Position, Range> vsSqzCall_;
    std::map<Position, Range> fourBet_;
    std::map<Position, Range> vs4betCall_;
    std::map<Position, Range> broke_;
    float rfiSize_;
    float threeBetSize_;
    float fourBetSize_;

public:
    PositionalRange(const Position position);
    bool isInRfi(const Hand& h) const { return rfi_.isInRange(h); }
    bool isInColdCall(const Hand& h, const Position& p) const { return coldCall_.at(p).isInRange(h); }
    bool isIn3Bet(const Hand& h, const Position& p) const { return threeBet_.at(p).isInRange(h); }
    bool isInVs3betCall(const Hand& h, const Position& p) const { return vs3betCall_.at(p).isInRange(h); }
    bool isInVsSqzCall(const Hand& h, const Position& p) const { return vsSqzCall_.at(p).isInRange(h); }
    bool isIn4Bet(const Hand& h, const Position& p) const { return fourBet_.at(p).isInRange(h); }
    bool isInVs4betCall(const Hand& h, const Position& p) const { return vs4betCall_.at(p).isInRange(h); }
    bool isInBroke(const Hand& h, const Position& p) const { return broke_.at(p).isInRange(h); }
    float getRfiSize() const { return rfiSize_; }
    float get3BetSize() const { return threeBetSize_; }
    float get4BetSize() const { return fourBetSize_; }
};

#endif //POSITIONAL_RANGE_H
