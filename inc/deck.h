#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <set>

class Deck
{
private:
    std::set<Card> deck_;

public:
    Deck();

    std::size_t size() const { return deck_.size();}
    bool isInDeck(const Card& c) const;
    Card getRandomCard();
};

#endif // DECK_H
