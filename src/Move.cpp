#include "Move.h"
#include <vector>

std::ostream& operator<<(std::ostream& os, const Move& p)
{
    static const std::vector<std::string> moveToString = {"Fold", "Check", "Call", "Bet", "Raise", "Unknown"};
    os << moveToString.at(static_cast<size_t>(p.first));
    os << (p.first == Action::Bet || p.first == Action::Raise ? ":" : "") ;
    return os;
}
