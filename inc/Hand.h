#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <string>
#include <map>

class Hand
{
private:
    std::string hand_;
public:
    Hand() { Hand(Card::Unknown, Card::Unknown); }
    Hand(Card a, Card b);
    std::string getHand() const;
};

#endif // HAND_H
