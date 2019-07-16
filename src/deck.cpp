#include "deck.h"
#include <random>
#include <chrono>

Deck::Deck()
{
    for (Card c = Card::As; c <= Card::TwoC; ++c)
        deck_.insert(c);
}

bool Deck::isInDeck(const Card& c) const
{
    return deck_.find(c) != deck_.end();
}

Card Deck::getRandomCard()
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
