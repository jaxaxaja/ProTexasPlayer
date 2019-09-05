#ifndef BOARD_H
#define BOARD_H

#include "Card.h"
#include <vector>

class Board
{
public:
    Board() : turn_(Card::Unknown), river_(Card::Unknown), pot_(0) {}
    void setFlop(const std::vector<Card>& flop) { flop_ = flop; }
    void setTurn(Card turn) { turn_ = turn; }
    void setRiver(Card river) { river_ = river; }
private:
    std::vector<Card> flop_;
    Card turn_;
    Card river_;
    size_t pot_;            //number in big blinds
};

#endif
