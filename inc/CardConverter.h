#ifndef CARD_CONVERTER_H
#define CARD_CONVERTER_H

#include "Hand.h"
#include <spdlog/spdlog.h>
#include <map>

class CardConverter
{
    static const std::map<std::string, Card> stringToCardMap_;
public:
    static Card CardFromString(const std::string& card);
    static Hand HandFromString(const std::string& cards);
};

#endif
