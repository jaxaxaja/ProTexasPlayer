#include "croupier.h"

Croupier::Croupier(Board& board, const std::vector<Player> &players)
    : board_(board), players_(players) {}
