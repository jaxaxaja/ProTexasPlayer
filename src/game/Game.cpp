#include <game/Game.h>
#include <game/PreFlop.h>
#include <spdlog/spdlog.h>

Game::Game(long handNumber, const std::string stake, const std::vector<Player> &players)
    : handNumber_(handNumber), stake_(stake), players_(players), croupier_(board_, players_), gameState_(nullptr)
{
    //stworzyc numOfPlayers graczy z odpowiednimi parametrami
}

void Game::setGameState(GameState* state)
{
    gameState_ = state;
}

void Game::playHand()
{
    try {
        spdlog::info("Start of a hand! Playing hand number: {}", handNumber_);
        setGameState(new PreFlop());
        while (croupier_.activePlayers() > 1)
        {
            spdlog::debug("Number of active players: {}", croupier_.activePlayers());
            gameState_->dealCards(croupier_);
            gameState_->askPlayers(croupier_);
            gameState_->nextState(this);
        }
    }
    catch (const std::exception& e)
    {
        spdlog::critical(e.what());
    }
    spdlog::info("End of a hand! Hand number: {}", handNumber_);
}

Game::~Game()
{
    if (gameState_)
        delete gameState_;
}
