#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <set>
#include <iostream>

class Deck
{
private:
    std::set<Card> deck_;
    Deck();

public:
    Deck(const Deck&) = delete;
    Deck(Deck&&) = delete;
    Deck& operator=(Deck&) = delete;
    Deck& operator=(Deck&&) = delete;

    static Deck& getInstance()
    {
        static Deck instance_;
        return instance_;
    }

    std::size_t size() const { return deck_.size();}
    bool isInDeck(const Card& c) const;

};

#endif // DECK_H
