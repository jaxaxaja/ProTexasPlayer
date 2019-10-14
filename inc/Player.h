#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include "Board.h"
#include <strategy/StrategyImpl.h>
#include "PlayerStatistics.h"
#include "Position.h"
#include "Move.h"
#include <string>

class Player
{
public:
    Player(const std::string& name, const Board& board, size_t bigBlinds, Position position, std::unique_ptr<StrategyImpl> strategy);
    bool isActive() const { return isActive_; }
    const std::string& getName() const { return name_; }
    void setHand(Hand hand) { hand_ = hand; }
    const std::string& showHand() const { return hand_.getHand(); }
    Position getPosition() const { return position_; }
    Move makeMove(const size_t bb);

private:
    std::string name_;
    Hand hand_;
    size_t bigBlinds_;
    std::unique_ptr<StrategyImpl> strategy_;
    PlayerStatistics statistics_;
    bool isActive_ = true;              //still plays his hand
    const Board& board_;
    Position position_ = Position::Unknown;
};

#endif //PLAYER_H
