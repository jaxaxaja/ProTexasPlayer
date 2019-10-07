#include <deck/StandardInputDeck.h>
#include "Exceptions.h"
#include <iostream>
#include <algorithm>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

void StandardInputDeck::dealCardsToPlayer(Player& player)
{
    std::cout << "Specify cards for player " << player.getName() << ": ";
    Hand h;
    if (!parser_.parsePlayerHand(&std::cin, h))
    {
        spdlog::error("Cannot parse player hand from user input");
        throw PlayerHandParsingError();
    }

    spdlog::info("Dealt hand {} to player {}", h.getHand(), player.getName());
    player.setHand(h);
}

void StandardInputDeck::dealFlopCards(Board& board)
{
    std::cout << "Specify cards for Flop: ";
    std::vector<Card> v;
    if (!parser_.parseFlopCards(&std::cin, v))
    {
        spdlog::error("Cannot parse flop cards from user input");
        throw FlopParsingError();
    }

    spdlog::info("Dealt flop cards: {}{}{}", v.front(), v.at(1), v.back());
    board.flop_ = v;
}

void StandardInputDeck::dealTurnCards(Board& board)
{
    std::cout << "Specify card for turn: ";
    Card c;
    if (!parser_.parseCard(&std::cin, c))
    {
        spdlog::error("Cannot parse card from user input");
        throw TurnParsingError();
    }

    spdlog::info("Dealt turn card: {}", c);
    board.turn_ = c;
}

void StandardInputDeck::dealRiverCards(Board& board)
{
    std::cout << "Specify cards for river: ";
    Card c;
    if (!parser_.parseCard(&std::cin, c))
    {
        spdlog::error("Cannot parse card from user input");
        throw RiverParsingError();
    }

    spdlog::info("Dealt river card: {}", c);
    board.river_ = c;
}
