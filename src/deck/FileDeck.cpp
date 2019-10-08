#include <deck/FileDeck.h>
#include "Exceptions.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

FileDeck::FileDeck(const std::string &fileName) : fileName_(fileName), file_(fileName)
{
    if (!file_.good())
        throw std::ifstream::failure("Cannot open file " + fileName);
}

void FileDeck::dealCardsToPlayer(Player* player)
{
    Hand h;
    if (!parser_.parsePlayerHand(&file_, h))
    {
        spdlog::error("Cannot parse player hand from file: {}", fileName_);
        throw PlayerHandParsingError();
    }

    spdlog::info("Dealt hand {} to player {}", h.getHand(), player->getName());
    player->setHand(h);
}

void FileDeck::dealFlopCards(Board &board)
{
    std::vector<Card> v;
    if (!parser_.parseFlopCards(&file_, v))
    {
        spdlog::error("Cannot parse flop cards from file: {}", fileName_);
        throw FlopParsingError();
    }

    spdlog::info("Dealt flop cards: {}{}{}", v.front(), v.at(1), v.back());
    board.flop_ = v;
}

void FileDeck::dealTurnCards(Board &board)
{
    Card c;
    if (!parser_.parseCard(&file_, c))
    {
        spdlog::error("Cannot parse card from file: {}", fileName_);
        throw TurnParsingError();
    }

    spdlog::info("Dealt turn card: {}", c);
    board.turn_ = c;
}

void FileDeck::dealRiverCards(Board &board)
{
    Card c;
    if (!parser_.parseCard(&file_, c))
    {
        spdlog::error("Cannot parse card from file: {}", fileName_);
        throw RiverParsingError();
    }

    spdlog::info("Dealt river card: {}", c);
    board.river_ = c;
}

FileDeck::~FileDeck()
{
    if (file_.is_open())
        file_.close();
}
