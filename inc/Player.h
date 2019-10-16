#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include "Board.h"
#include <strategy/StrategyImpl.h>
#include "PlayerStatistics.h"
#include "Position.h"
#include <move/Move.h>
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
    void fold() { isActive_ = false; }
    const std::string& getName() const { return name_; }
    void setHand(Hand hand) { hand_ = hand; }
    void setBetSize(const float s) { betSize_ = s; }
    void setSbBetSize() { betSize_ = 0.5; bigBlinds_ -= 0.5; }
    void setBbBetSize() { betSize_ = 1; bigBlinds_ -= 1; }
    float betSize() const { return betSize_; }
    std::string showHand() const { return hand_.show(); }
    std::pair<Card, Card> getHand() const { return hand_.getHand(); }
    Position getPosition() const { return position_; }
    float getStackSize() const { return bigBlinds_; }
    void adjustStack(const float size) { bigBlinds_ += size; }
    std::unique_ptr<Move> makeMove(const float bb);
};

#endif //PLAYER_H
