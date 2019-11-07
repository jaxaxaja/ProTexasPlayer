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
    Hand(Card a, Card b);
    std::pair<Card, Card> get() const { return std::make_pair(a_, b_); }
    std::string show() const;
    bool operator<(const Hand& rhs) const;
    bool operatorLess(const Hand& rhs) const; //used for comparison in std::set
    bool operator==(const Hand& rhs) const;
};

#endif // HAND_H
