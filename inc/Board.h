#ifndef BOARD_H
#define BOARD_H

#include "Card.h"
#include <vector>
#include <gtest/gtest.h>

struct Board
{
    Board() : turn_(Card::Unknown), river_(Card::Unknown), pot_(0) {}
    std::vector<Card> flop_;
    Card turn_;
    Card river_;
    size_t pot_;            //number in big blinds
};

#endif
