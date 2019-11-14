#include <game/GameSimulationFactory.h>
#include <strategy/StrategyImpl.h>
#include <deck/DeckImpl.h>
#include <iostream>
#include <spdlog/spdlog.h>

std::unique_ptr<StrategyImpl> GameSimulationFactory::createPlayerStrategy(const std::string& playerName, const Position position)
{
    if (strategy_ == "F")
        return StrategyImpl::createStrategy(strategy_, position, ins_);

    bool error = true;
    std::unique_ptr<StrategyImpl> strategy;

    while (error)
    {
        error = false;
        std::cout << "What is strategy for " << playerName << "?: R - real, S - standard input" << std::endl;
        std::string str;
        std::cin >> str;

        try {
            strategy = StrategyImpl::createStrategy(str, position);
        }
        catch (const std::exception& e)
        {
            error = true;
            spdlog::error(e.what());
        }
    }

    return strategy;
}

std::unique_ptr<DeckImpl> GameSimulationFactory::createDeck()
{
    bool error = true;
    std::unique_ptr<DeckImpl> deck;

    while (error)
    {
        error = false;
        std::cout << "What is deck implementation?: R - real, S - standard input, F - file" << std::endl;
        std::cin >> strategy_;

        try {
            if (strategy_ == "F")
            {
                std::cout << "Provide file location: ";
                std::cin >> file_;
                ins_.open(file_);
                deck = DeckImpl::createDeck(strategy_, ins_);
            }
            else
                deck = DeckImpl::createDeck(strategy_);
        }
        catch (const std::exception& e)
        {
            error = true;
            spdlog::error(e.what());
        }
    }

    return deck;
}

std::vector<std::unique_ptr<Player>> GameSimulationFactory::createPlayers(const Board& board, std::vector<PlayerMoveInfo> &playersMoveInfo)
{
    std::vector<std::unique_ptr<Player>> players;
    int num;
    std::string name, pos;
    float bb;

    if (strategy_ == "F")
    {
        ins_ >> num;
        while (num--)
        {
            ins_ >> name >> pos >> bb;
            Position position = pos == "BU" ? Position::BU : pos == "SB" ? Position::SB : pos == "BB" ? Position::BB
                                           : pos == "EP" ? Position::EP : pos == "MP" ? Position::MP : Position ::CO;
            players.emplace_back(std::make_unique<Player>(name, board, bb, position, createPlayerStrategy(), playersMoveInfo));
        }
    }
    else
    {
        std::cout << "How many Players?: 1..6" << std::endl;
        std::cin >> num;
        std::cout << "Specify players in this way (PlayerName Position howManyBB) e.g.: Player1 BU 100" << std::endl;

        while (num--)
        {
            std::cin >> name >> pos >> bb;
            Position position = pos == "BU" ? Position::BU : pos == "SB" ? Position::SB : pos == "BB" ? Position::BB
                                                                                                      : pos == "EP" ? Position::EP : pos == "MP" ? Position::MP : Position ::CO;
            players.emplace_back(std::make_unique<Player>(name, board, bb, position, createPlayerStrategy(name, position), playersMoveInfo));
        }
    }

    return players;
}
