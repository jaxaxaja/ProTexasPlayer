#include <game/Game.h>
#include <game/PreFlop.h>
#include <spdlog/spdlog.h>

Game::Game(const std::string& stake, const std::vector<Player*> &players, std::unique_ptr<DeckImpl> deck)
    : stake_(stake), players_(players), croupier_(board_, players_, std::move(deck))
{

}

void Game::setGameState(GameState* state)
{
    gameState_ = state;
}

size_t Game::playersInHand()
{
    return croupier_.activePlayers() + croupier_.allInPlayers();
}

void Game::playHand()
{
    ++handNumber_;
    try {
        spdlog::info("Start of a hand! Playing hand number: {} on stake {}", handNumber_, stake_);
        setGameState(new PreFlop());
        while (playersInHand() > 1 && gameState_)
        {
            spdlog::debug("Number of active players: {}", croupier_.activePlayers());
            gameState_->dealCards(croupier_);
            gameState_->askPlayers(croupier_);
            gameState_->nextState(this);
        }
        croupier_.chooseWinner();
    }
    catch (const std::exception& e)
    {
        spdlog::critical(e.what());
        spdlog::critical("Cannot play a hand!");
    }
    spdlog::info("End of a hand! Hand number: {}", handNumber_);
}

Game::~Game()
{
    if (gameState_)
        delete gameState_;
}
