#include "Hand.h"
#include <sstream>

Hand::Hand(Card a, Card b)
{
    std::stringstream cards;
    if (a < b)
        cards << a << b;
    else
        cards << b << a;

    hand_ = cards.str();
}

const std::string& Hand::getHand() const
{
    return hand_;
}
