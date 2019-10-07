#ifndef CROUPIER_H
#define CROUPIER_H

#include <deck/DeckImpl.h>
#include "Player.h"
#include "Board.h"
#include <vector>
#include <memory>

class Croupier
{
public:
    Croupier(Board& board, std::vector<Player>& players);
    void dealCardsToPlayers();
    void dealFlopCards();
    void dealTurnCards();
    void dealRiverCards();
    void checkOrBet();
    void callRaiseOrFold();
    size_t activePlayers();
private:
    std::unique_ptr<DeckImpl> deck_;
    Board& board_;
    std::vector<Player>& players_;
};

#endif //CROUPIER_H
