#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <utility>
#include <string>

class Hand
{
private:
    Card a_ = Card::Unknown;
    Card b_ = Card::Unknown;
public:
    Hand() = default;
    Hand(Card a, Card b) : a_(a), b_(b) {}
    std::pair<Card, Card> get() const { return std::make_pair(a_, b_); }
    std::string show() const;
};

#endif // HAND_H
