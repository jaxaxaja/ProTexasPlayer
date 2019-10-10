#include "Position.h"
#include <vector>

std::ostream& operator<<(std::ostream& os, const Position& p)
{
    static const std::vector<std::string> positionToString = {"BU", "SB", "BB", "EP", "MP", "CO", "Unknown"};
    return os << positionToString.at(static_cast<size_t>(p));
}
