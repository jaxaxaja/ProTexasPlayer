#ifndef STANDARD_INPUT_DECK_H
#define STANDARD_INPUT_DECK_H

#include <deck/DeckImpl.h>
#include <deck/StreamParser.h>
#include <map>

class StandardInputDeck : public DeckImpl
{
    StreamParser parser_;
public:
    StandardInputDeck() = default;

    virtual void dealCardsToPlayer(Player *player) override;
    virtual void dealFlopCards(Board& board) override;
    virtual void dealTurnCards(Board& board) override;
    virtual void dealRiverCards(Board& board) override;
};

#endif //STANDARD_INPUT_DECK_H
