#include "Hand.h"
#include <sstream>

std::string Hand::show() const
{
    std::stringstream cards;
    if (a_ < b_)
        cards << a_ << b_;
    else
        cards << b_ << a_;

    return cards.str();
}
