#include <deck/StandardInputDeck.h>
#include "CardConverter.h"
#include <iostream>
#include <algorithm>

Card StandardInputDeck::getCard()
{
    Card c = Card::Unknown;
    while (c == Card::Unknown)
    {
        std::string card;
        std::cin >> card;
        c = CardConverter::CardFromString(card);
    }
    return c;
}

Hand StandardInputDeck::getHand()
{
    Hand h;
    while (h.getHand().find("Unknown"))
    {
        std::string hand;
        std::cin >> hand;
        h = CardConverter::HandFromString(hand);
    }
    return h;
}

std::vector<Card> StandardInputDeck::getFlop()
{
    std::vector<Card> flop = {Card::Unknown, Card::Unknown, Card::Unknown};
    auto hasUnknown = [&flop](){ return (std::find(flop.begin(), flop.end(), Card::Unknown) != flop.end()); };
    while (hasUnknown())
    {
        std::string cards;
        std::cin >> cards;
        flop = CardConverter::FlopFromString(cards);
    }
    return flop;
}

void StandardInputDeck::dealCardsToPlayer(Player& player)
{
    std::cout << "Specify cards for player " << player.getName() << ": ";
    player.setHand(getHand());
}

void StandardInputDeck::dealFlopCards(Board& board)
{
    std::cout << "Specify cards for Flop: ";
    board.setFlop(getFlop());
}

void StandardInputDeck::dealTurnCards(Board& board)
{
    std::cout << "Specify card for turn: ";
    board.setTurn(getCard());
}

void StandardInputDeck::dealRiverCards(Board& board)
{
    std::cout << "Specify cards for river: ";
    board.setRiver(getCard());
}
