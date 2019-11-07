#ifndef RANGE_CREATOR_H
#define RANGE_CREATOR_H

#include <strategy/range/Range.h>
#include <string>
#include <map>

class RangeCreator
{
    static const std::map<char, Card> stringToGeneralCardMap_;
    std::vector<Hand> createPairs(const Card& c);
    std::vector<Hand> createSuitedCombos(const Card& c, const Card& d);
    std::vector<Hand> createOffSuitCombos(const Card& c, const Card& d);
    std::vector<Hand> createCombos(const Card& c, const Card& d);
    std::vector<Hand> ranger(const std::string& s);

public:
    Range createRange(const std::string& range);
};

#endif //RANGE_CREATOR_H
