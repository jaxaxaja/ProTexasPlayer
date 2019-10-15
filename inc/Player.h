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
    std::string name_;
    Hand hand_;
    float bigBlinds_;
    float betSize_ = 0;                 //the highest number of bb which player bet/call/raise on current street
    std::unique_ptr<StrategyImpl> strategy_;
    PlayerStatistics statistics_;
    bool isActive_ = true;              //still plays his hand
    const Board& board_;
    Position position_ = Position::Unknown;

public:
    Player(const std::string& name, const Board& board, float bigBlinds, Position position, std::unique_ptr<StrategyImpl> strategy);
    bool isActive() const { return isActive_; }
    const std::string& getName() const { return name_; }
    void setHand(Hand hand) { hand_ = hand; }
    void resetBetSize() { betSize_ = 0; }
    const std::string& showHand() const { return hand_.getHand(); }
    Position getPosition() const { return position_; }
    float getStackSize() const { return bigBlinds_; }
    void addMoney(const float size) { bigBlinds_ += size; }
    Move makeMove(const float bb);
};

#endif //PLAYER_H
