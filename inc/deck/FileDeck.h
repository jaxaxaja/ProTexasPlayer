#ifndef FILE_DECK_H
#define FILE_DECK_H

#include <deck/DeckImpl.h>
#include <deck/StreamParser.h>
#include <fstream>

class FileDeck : public DeckImpl
{
    std::ifstream file_;
    std::string fileName_;
    StreamParser parser_;

public:
    FileDeck(const std::string& fileName);
    virtual void dealCardsToPlayer(Player *player) override;
    virtual void dealFlopCards(Board& board) override;
    virtual void dealTurnCards(Board& board) override;
    virtual void dealRiverCards(Board& board) override;
    virtual ~FileDeck();
};

#endif //FILE_DECK_H
