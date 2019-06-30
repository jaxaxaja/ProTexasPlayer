#ifndef HAND_H
#define HAND_H

#include "card.h"
#include <string>
#include <map>

class Hand
{
private:
    std::string hand_;
    static const std::map<Card, std::string> cardToStringMap_;
public:
    Hand(Card a, Card b);
    std::string getHand() const;
};

#endif // HAND_H
