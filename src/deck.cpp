#include "deck.h"

Deck::Deck()
{
    for (Card c = Card::As; c != Card::TwoC; ++c)
        deck_.insert(c);
    deck_.insert(Card::TwoC);
}

bool Deck::isInDeck(const Card& c) const
{
    if (deck_.find(c) != deck_.end())
        return true;
    return false;
}
