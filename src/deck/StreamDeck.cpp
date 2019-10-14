#include <deck/StreamDeck.h>
#include "Exceptions.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

void StreamDeck::dealCardsToPlayer(Player* player)
{
    if (&ins_ == &std::cin)
        std::cout << "Specify cards for player " << player->getName() << ": ";

    Hand h;
    if (!parser_.parsePlayerHand(&ins_, h))
    {
        spdlog::error("Cannot parse player hand from stream input!");
        throw PlayerHandParsingError();
    }

    spdlog::info("Dealt hand {} to player {}", h.getHand(), player->getName());
    player->setHand(h);
}

void StreamDeck::dealFlopCards(Board &board)
{
    if (&ins_ == &std::cin)
        std::cout << "Specify cards for Flop: ";

    std::vector<Card> v;
    if (!parser_.parseFlopCards(&ins_, v))
    {
        spdlog::error("Cannot parse flop cards from stream!");
        throw FlopParsingError();
    }

    spdlog::info("Dealt flop cards: {}{}{}", v.front(), v.at(1), v.back());
    board.flop_ = v;
}

void StreamDeck::dealTurnCards(Board &board)
{
    if (&ins_ == &std::cin)
        std::cout << "Specify card for turn: ";

    Card c;
    if (!parser_.parseCard(&ins_, c))
    {
        spdlog::error("Cannot parse card from stream!");
        throw TurnParsingError();
    }

    spdlog::info("Dealt turn card: {}", c);
    board.turn_ = c;
}

void StreamDeck::dealRiverCards(Board &board)
{
    if (&ins_ == &std::cin)
        std::cout << "Specify cards for river: ";

    Card c;
    if (!parser_.parseCard(&ins_, c))
    {
        spdlog::error("Cannot parse card from stream!");
        throw RiverParsingError();
    }

    spdlog::info("Dealt river card: {}", c);
    board.river_ = c;
}
