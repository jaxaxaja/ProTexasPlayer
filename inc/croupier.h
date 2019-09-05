#ifndef CROUPIER_H
#define CROUPIER_H

#include <deck/DeckImpl.h>
#include "player.h"
#include "Board.h"
#include <vector>
#include <memory>

class Croupier
{
public:
    Croupier(Board& board, const std::vector<Player>& players);
private:
    std::unique_ptr<DeckImpl> deck_;
    Board& board_;
    const std::vector<Player>& players_;
};

#endif //CROUPIER_H
