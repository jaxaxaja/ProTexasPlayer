#ifndef STREAM_DECK_H
#define STREAM_DECK_H

#include <deck/DeckImpl.h>
#include "StreamParser.h"
#include <istream>

class StreamDeck : public DeckImpl
{
    std::istream& ins_;
    StreamParser parser_;

public:
    StreamDeck(std::istream &ins) : ins_(ins) {}
    virtual void dealCardsToPlayer(std::unique_ptr<Player>& player) override;
    virtual void dealFlopCards(Board& board) override;
    virtual void dealTurnCards(Board& board) override;
    virtual void dealRiverCards(Board& board) override;
    virtual ~StreamDeck() = default;
};

#endif //STREAM_DECK_H
