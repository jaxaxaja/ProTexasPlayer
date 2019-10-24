#include <game/RealGameFactory.h>

std::vector<std::unique_ptr<Player>> RealGameFactory::createPlayers(Board &board)
{
    //call AHK to count number of players and create those players with specific positions and strategies calling createPlayerStrategy
    //create also a Hero player with Real strategy calling createHeroStrategy
}
