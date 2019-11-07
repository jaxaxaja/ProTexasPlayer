#include <strategy/range/RangeCreator.h>
#include "Exceptions.h"
#include "StreamParser.h"
#include <boost/tokenizer.hpp>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <sstream>

const std::map<char, Card> RangeCreator::stringToGeneralCardMap_ = {{'A', Card::Ac}, {'K', Card::Kc}, {'Q', Card::Qc}, {'J', Card::Jc},
                                                                    {'T', Card::Tc}, {'9', Card::NineC}, {'8', Card::EightC},
                                                                    {'7', Card::SevenC}, {'6', Card::SixC}, {'5', Card::FiveC},
                                                                    {'4', Card::FourC}, {'3', Card::ThreeC}, {'2', Card::TwoC}};

std::vector<Hand> RangeCreator::createPairs(const Card& c)
{
    std::vector<Hand> result;

    Card border;
    for (Card left = c; left >= Card::As; --left)
    {
        if (left % 4 == 3)
            border = left;

        for (Card right = left+1; right <= border; ++right)
            result.emplace_back(left, right);
    }

    return result;
}

std::vector<Hand> RangeCreator::createSuitedCombos(const Card& c, const Card& d)
{
    std::vector<Hand> result;
    Card left = c;
    Card right = d;

    result.emplace_back(left, right);
    result.emplace_back(--left, --right);
    result.emplace_back(--left, --right);
    result.emplace_back(--left, --right);

    return result;
}

std::vector<Hand> RangeCreator::createOffSuitCombos(const Card& c, const Card& d)
{
    std::vector<Hand> result;

    for (Card left = c; left >= c-3; --left)
    {
        for (Card right = d; right >= d-3; --right)
            if (left % 4 != right % 4)
                result.emplace_back(left, right);
    }

    return result;
}

std::vector<Hand> RangeCreator::createCombos(const Card& c, const Card& d)
{
    std::vector<Hand> result;

    for (Card left = c; left >= Card::As; --left)
    {
        for (Card right = d; right >= Card::As; --right)
            if (left / 4 != right / 4)
                result.emplace_back(left, right);
    }

    return result;
}

std::vector<Hand> RangeCreator::ranger(const std::string& s)
{
    if (s.size() != 3)
        throw RangeParsingError();

    if (s.back() != 's' && s.back() != 'o' && s.back() != '+')
        throw RangeParsingError();

    Card a;
    Card b;
    try {
        a = stringToGeneralCardMap_.at(s.front());
        b = stringToGeneralCardMap_.at(s.at(1));
        spdlog::debug("Converted string {} to general card: {}", s.front(), a);
        spdlog::debug("Converted string {} to general card: {}", s.at(1), b);
    }
    catch (const std::out_of_range& e)
    {
        spdlog::error("Cannot convert string {}{} to general cards!", s.front(), s.at(1));
        spdlog::error(e.what());
        throw;
    }

    if (s.back() == '+')
    {
        if (a == b)
            return createPairs(a);
        else
            return createCombos(a, b);
    }

    if (s.back() == 's')
        return createSuitedCombos(a, b);

    if (s.back() == 'o')
        return createOffSuitCombos(a, b);
}

Range RangeCreator::createRange(const std::string& range)
{
    using Tokenizer = boost::tokenizer<boost::char_separator<char>>;
    boost::char_separator<char> sep(",");
    Tokenizer tokens(range, sep);

    Range result;
    for (const auto& tok : tokens)
    {
        std::vector<Hand> tmp = ranger(tok);
        result.insert(tmp);
    }

    return result;
}
