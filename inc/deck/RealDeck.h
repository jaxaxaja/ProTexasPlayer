#ifndef REAL_DECK_H
#define REAL_DECK_H

#include <deck/DeckImpl.h>
#include "Card.h"
#include <set>
#include <gtest/gtest.h>

class RealDeck : public DeckImpl
{
private:
    std::set<Card> deck_; //a moze zamienic na vector?

    std::size_t size() const { return deck_.size();}
    bool isInDeck(const Card& c) const;
    Card getRandomCard();

    FRIEND_TEST(RealDeckTest, EntireDeck);
    FRIEND_TEST(RealDeckTest, RandomCards);

public:
    RealDeck();

    virtual void dealCardsToPlayer(std::unique_ptr<Player>& player) override;
    virtual void dealFlopCards(Board& board) override;
    virtual void dealTurnCards(Board& board) override;
    virtual void dealRiverCards(Board& board) override;
    ~RealDeck() override = default;
};

#endif // REAL_DECK_H
