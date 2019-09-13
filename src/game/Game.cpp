#include <game/Game.h>
#include <game/PreFlop.h>
#include <spdlog/spdlog.h>

Game::Game(long handNumber, const std::string stake, const std::vector<Player> &players)
    : handNumber_(handNumber), stake_(stake), players_(players), croupier_(board_, players_), gameState_(nullptr)
{
    //stworzyc numOfPlayers graczy z odpowiednimi parametrami
}

size_t Game::activePlayers()
{
    auto Active = [](const Player& player) { return player.isActive(); };
    return std::count_if(players_.begin(), players_.end(), Active);
}

void Game::setGameState(GameState* state)
{
    gameState_ = state;
}

void Game::playHand()
{
    spdlog::info("Start of a hand! Playing hand number: {}", handNumber_);
    setGameState(new PreFlop());
    while (activePlayers() > 1)
    {
        spdlog::debug("Number of active players: {}", activePlayers());
        gameState_->dealCards(croupier_);
        gameState_->askPlayers(croupier_);
        gameState_->nextState(this);
    }
    spdlog::info("End of a hand! Hand number: {}", handNumber_);
}

Game::~Game()
{
    if (gameState_)
        delete gameState_;
}
