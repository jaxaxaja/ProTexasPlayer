#ifndef PLAYER_H
#define PLAYER_H

#include "hand.h"
#include "board.h"
#include "strategy.h"
#include "playerStatistics.h"
#include <string>

class Player
{
public:
    Player(const std::string& name, const Board& board, Hand hand, size_t bigBlinds);
    bool isActive() const { return isActive_; }
    std::string getName() const { return name_; }
    void showHand();
private:
    std::string name_;
    Hand hand_;
    size_t bigBlinds_;
    Strategy strategy_;
    PlayerStatistics statistics_;
    bool isActive_;                 //still plays his hand
    const Board& board_;
};

#endif //PLAYER_H
