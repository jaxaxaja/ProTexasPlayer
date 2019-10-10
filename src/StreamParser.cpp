#include "StreamParser.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

const std::map<std::string, Card> StreamParser::stringToCardMap_ = {{"As", Card::As},       {"Ah", Card::Ah},       {"Ad", Card::Ad},       {"Ac", Card::Ac},
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

const std::map<std::string, Move> StreamParser::stringToMoveMap_ = {{"F", Move(Action::Fold, 0)}, {"CA", Move(Action::Call, 0)}, {"CH", Move(Action::Check, 0)},
                                                                    {"B", Move(Action::Bet, 0)}, {"R", Move(Action::Raise, 0)}};

Card StreamParser::CardFromString(const std::string& card)
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

Hand StreamParser::HandFromString(const std::string& cards)
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

std::vector<Card> StreamParser::FlopFromString(const std::string& cards)
{
    std::vector<Card> v;
    try {
        for (int i = 0; i < 3; ++i)
            v.push_back(CardFromString(cards.substr(i*2,2)));
        return v;
    }
    catch(const std::exception& e)
    {
        spdlog::error("Cannot convert string {} to Flop cards!", cards);
        spdlog::error(e.what());
    }
    return {};
}

bool StreamParser::parseCard(std::istream* const istr, Card& c)
{
    std::string card;
    *istr >> card;
    c = CardFromString(card);
    if (c == Card::Unknown)
    {
        spdlog::error("Got unknown card when parsing string: {}", card);
        return false;
    }

    return true;
}

bool StreamParser::parsePlayerHand(std::istream* const istr, Hand& h)
{
    std::string hand;
    *istr >> hand;
    h = HandFromString(hand);
    if (h.getHand().find("Unknown") != std::string::npos)
    {
        spdlog::error("Got unknown hand when parsing string: {}", hand);
        return false;
    }

    return true;
}

bool StreamParser::parseFlopCards(std::istream* const istr, std::vector<Card>& v)
{
    std::string cards;
    *istr >> cards;
    v = FlopFromString(cards);
    bool hasUnknown = [&v]{ return (std::find(v.begin(), v.end(), Card::Unknown) != v.end()); }();
    if (v.empty() || hasUnknown)
    {
        spdlog::error("Got unknown card when parsing flop string: {}", cards);
        return false;
    }

    return true;
}

Move StreamParser::moveFromString(const std::string& move, std::istream* const istr)
{
    try {
        Move m = stringToMoveMap_.at(move);
        spdlog::debug("Converted string {} to move: {}", move, m);

        if (m.first == Action::Bet || m.first == Action::Raise)
        {
            std::string bbString;
            *istr >> bbString;
            try {
                m.second = std::stoi(bbString);
                return m;
            }
            catch(const std::exception& e)
            {
                spdlog::error("Cannot convert {} to number in {} move", bbString, m);
                spdlog::error(e.what());
            }
        }
        return m;
    }
    catch (const std::out_of_range& e)
    {
        spdlog::error("Cannot convert string {} to Move type!", move);
        spdlog::error(e.what());
    }

    return Move(Action::Unknown, 0);
}

bool StreamParser::parsePlayerMove(std::istream* const istr, Move& m)
{
    std::string move;
    *istr >> move;
    m = moveFromString(move, istr);

    if (m.first == Action::Unknown)
    {
        spdlog::error("Got unknown Move when parsing string: {}", move);
        return false;
    }

    if ((m.first == Action::Bet || m.first == Action::Raise) && m.second == 0)
    {
        spdlog::error("Got unknown size of Bet/Raise when parsing move: {}", m);
        return false;
    }

    return true;
}
