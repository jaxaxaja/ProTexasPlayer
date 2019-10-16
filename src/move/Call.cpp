#include <move/Call.h>
#include "Player.h"

void Call::updatePlayer(Player* player, const float bb)
{
    this->adjustSize(bb - player->betSize());
    player->adjustStack(-this->moveSize());
    player->setBetSize(bb);

    if (player->getStackSize() <= 0)
        player->fold();
}
