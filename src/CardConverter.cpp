#include "CardConverter.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

const std::map<std::string, Card> CardConverter::stringToCardMap_ = {{"As", Card::As},       {"Ah", Card::Ah},       {"Ad", Card::Ad},       {"Ac", Card::Ac},
                                                                     {"Ks", Card::Ks},       {"Kh", Card::Kh},       {"Kd", Card::Kd},       {"Kc", Card::Kc},
                                                                     {"Qs", Card::Qs},       {"Qh", Card::Qh},       {"Qd", Card::Qd},       {"Qc", Card::Qc},
                                                                     {"Js", Card::Js},       {"Jh", Card::Jh},       {"Jd", Card::Jd},       {"Jc", Card::Jc},
                                                                     {"Ts", Card::Ts},       {"Th", Card::Th},       {"Td", Card::Td},       {"Tc", Card::Tc},
                                                                     {"9s", Card::NineS},    {"9h", Card::NineH},    {"9d", Card::NineD},    {"9c", Card::NineC},
                                                                     {"8s", Card::EightS},   {"8h", Card::EightH},   {"8d", Card::EightD},   {"8c", Card::EightC},
                                                                     {"7s", Card::SevenS},   {"7h", Card::SevenH},   {"7d", Card::SevenD},   {"7c", Card::SevenC},
                                                                     {"6s", Card::SixS},     {"6h", Card::SixH},     {"6d", Card::SixD},     {"6c", Card::SixC},
                                                                     {"5s", Card::FiveS},    {"5h", Card::FiveH},    {"5d", Card::FiveD},    {"5c", Card::FiveC},
                                                                     {"4s", Card::FourS},    {"4h", Card::FourH},    {"4d", Card::FourD},    {"4c", Card::FourC},
                                                                     {"3s", Card::ThreeS},   {"3h", Card::ThreeH},   {"3d", Card::ThreeD},   {"3c", Card::ThreeC},
                                                                     {"2s", Card::TwoS},     {"2h", Card::TwoH},     {"2d", Card::TwoD},     {"2c", Card::TwoC}};

Card CardConverter::CardFromString(const std::string& card)
{
    try {
        Card c = stringToCardMap_.at(card);
        spdlog::debug("Converted string {} to card: {}", card, c);
        return c;
    }
    catch (const std::out_of_range& e)
    {
        spdlog::error("Cannot convert string {} to Card type!", card);
        spdlog::error(e.what());
    }
    return Card::Unknown;
}

Hand CardConverter::HandFromString(const std::string& cards)
{
    try {
        Card c1 = CardFromString(cards.substr(0,2));
        Card c2 = CardFromString(cards.substr(2,2));
        spdlog::debug("Converted string {} to hand {}{}", cards, c1, c2);
        return Hand(c1,c2);
    }
    catch (const std::exception& e)
    {
        spdlog::error("Cannot convert string {} to Hand type!", cards);
        spdlog::error(e.what());
    }
    return Hand(Card::Unknown, Card::Unknown);
}
