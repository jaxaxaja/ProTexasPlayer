#ifndef BOARD_H
#define BOARD_H

#include "card.h"
#include <vector>

class Board
{
public:
    Board() : turn_(Card::NoCard), river_(Card::NoCard), pot_(0) {}
private:
    std::vector<Card> flop_;
    Card turn_;
    Card river_;
    size_t pot_;            //number in big blinds
};

#endif
