#include <move/Fold.h>
#include "Player.h"

void Fold::updatePlayer(Player* player, const float)
{
    player->fold();
}
