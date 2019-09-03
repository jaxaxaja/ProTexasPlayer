#ifndef CROUPIER_H
#define CROUPIER_H

#include "deck.h"
#include "player.h"
#include "board.h"
#include <vector>
#include <memory>

class Croupier
{
public:
    Croupier(Board& board);
private:
    Deck deck_;
    Board& board_;
    std::vector<std::shared_ptr<Player>> players_;
};

#endif //CROUPIER_H
