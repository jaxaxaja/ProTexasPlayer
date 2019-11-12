#include <move/Bet.h>
#include "Player.h"

void Bet::updatePlayer(Player* player, const float)
{
    player->adjustStack(-size_ + player->betSize());
    float tmp = player->betSize();
    player->setBetSize(size_);
    size_ = size_ - tmp;

    if (player->getStackSize() <= 0)
        player->fold();
}
