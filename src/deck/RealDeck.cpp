#include <deck/RealDeck.h>
#include "Board.h"
#include <random>
#include <chrono>
#include <spdlog/spdlog.h>

RealDeck::RealDeck()
{
    for (Card c = Card::As; c <= Card::TwoC; ++c)
        deck_.insert(c);
}

bool RealDeck::isInDeck(const Card& c) const
{
    return deck_.find(c) != deck_.end();
}

Card RealDeck::getRandomCard()
{
    auto duration = std::chrono::system_clock::now().time_since_epoch();
    auto mili = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    std::mt19937 generator(mili);
    std::uniform_int_distribution<std::mt19937::result_type> deck52(1, 52);

    Card c;
    do {
        c = static_cast<Card>(deck52(generator));
    } while (!isInDeck(c));

    deck_.erase(c);
    return c;
}

void RealDeck::dealCardsToPlayer(Player &player)
{
    Hand hand(getRandomCard(), getRandomCard());
    spdlog::info("Dealt hand to player {}: {}", player.getName(), hand.getHand());
    player.setHand(hand);
}

void RealDeck::dealFlopCards(Board &board)
{
    std::vector<Card> flop = {getRandomCard(), getRandomCard(), getRandomCard()};
    board.setFlop(flop);
}

void RealDeck::dealTurnCards(Board &board)
{
    board.setTurn(getRandomCard());
}

void RealDeck::dealRiverCards(Board &board)
{
    board.setRiver(getRandomCard());
}
