#include "Hand.h"
#include <sstream>

Hand::Hand(Card a, Card b)
{
    if (a < b)
    {
        a_ = a;
        b_ = b;
    }
    else
    {
        a_ = b;
        b_ = a;
    }
}

bool Hand::operator<(const Hand& rhs) const
{
    if (static_cast<size_t>(a_) / 4 == static_cast<size_t>(rhs.a_) / 4)
            return b_ > rhs.b_;
    else if (a_ > rhs.a_)
        return true;
    else
        return false;
}

bool Hand::operatorLess(const Hand& rhs) const
{
    if (static_cast<size_t>(a_) / 4 == static_cast<size_t>(rhs.a_) / 4)
    {
        if (static_cast<size_t>(a_) % 4 == static_cast<size_t>(rhs.a_) % 4)
            return b_ > rhs.b_;
        else
            return a_ > rhs.a_;
    }
    else if (a_ > rhs.a_)
        return true;
    else
        return false;
}

bool Hand::operator==(const Hand& rhs) const
{
    return (static_cast<size_t>(a_) / 4 == static_cast<size_t>(rhs.a_) /4) && (static_cast<size_t>(b_) / 4 == static_cast<size_t>(rhs.b_) / 4);
}

std::string Hand::show() const
{
    std::stringstream cards;
    cards << a_ << b_;

    return cards.str();
}
