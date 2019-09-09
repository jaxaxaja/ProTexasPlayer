#include <game/Game.h>

Game::Game(long handNumber, const std::string stake, size_t numOfPlayers)
    : handNumber_(handNumber), stake_(stake), croupier_(board_, players_)
{
    //stworzyc numOfPlayers graczy z odpowiednimi parametrami
}
