#include <move/Raise.h>
#include "Player.h"

void Raise::updatePlayer(Player* player, const float)
{
    player->adjustStack(-this->moveSize() + player->betSize());
    float tmp = player->betSize();
    player->setBetSize(this->moveSize());
    this->adjustSize(this->moveSize() - tmp);

    if (player->getStackSize() <= 0)
        player->fold();
}
