#include <move/Call.h>
#include "Player.h"

void Call::updatePlayer(Player* player, const float bb)
{
    size_ = bb - player->betSize();
    player->adjustStack(-size_);
    player->setBetSize(bb);

    if (player->getStackSize() <= 0)
        player->fold();
}
