#ifndef BOARD_H
#define BOARD_H

#include "Card.h"
#include <vector>
#include <gtest/gtest.h>

struct Board
{
    Board() = default;
    std::vector<Card> flop_;
    Card turn_ = Card::Unknown;
    Card river_ = Card::Unknown;
    float pot_ = 0;            //number in big blinds
};

#endif
