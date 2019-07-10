#include "deck.h"

Deck::Deck()
{
    for (Card c = Card::As; c <= Card::TwoC; ++c)
        deck_.insert(c);
}

bool Deck::isInDeck(const Card& c) const
{
    return deck_.find(c) != deck_.end();
}
