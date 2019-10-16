#ifndef STREAM_PARSER_H
#define STREAM_PARSER_H

#include "Hand.h"
#include <move/Move.h>
#include <map>
#include <vector>

class StreamParser
{
    static const std::map<std::string, Card> stringToCardMap_;
    Card CardFromString(const std::string& card);
    Hand HandFromString(const std::string& cards);
    std::vector<Card> FlopFromString(const std::string& cards);
    std::unique_ptr<Move> moveFromString(const std::string& move, std::istream* const istr);
public:
    bool parseCard(std::istream* const istr, Card& c);
    bool parsePlayerHand(std::istream* const istr, Hand& h);
    bool parseFlopCards(std::istream* const istr, std::vector<Card>& v);
    bool parsePlayerMove(std::istream* const istr, std::unique_ptr<Move> &m);
};

#endif //STREAM_PARSER_H
