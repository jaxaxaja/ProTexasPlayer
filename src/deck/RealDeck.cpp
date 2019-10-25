#include <deck/RealDeck.h>
#include <random>
#include <chrono>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

RealDeck::RealDeck()
{
    for (Card c = Card::As; c <= Card::TwoC; ++c)
        deck_.insert(c);
}

bool RealDeck::isInDeck(const Card& c) const
{
    return deck_.find(c) != deck_.end();
}

Card RealDeck::getRandomCard() //jak deck bedzie vectorem to mozna shuffle zrobic i brac dowolne karty, trzeba tylko sprawdzic jak losowy jest schuffle
{
    auto duration = std::chrono::system_clock::now().time_since_epoch();
    auto mili = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    std::mt19937 generator(mili);
    std::uniform_int_distribution<std::mt19937::result_type> deck52(1, 52);

    Card c;
    do {
        c = static_cast<Card>(deck52(generator));
    } while (!isInDeck(c));

    deck_.erase(c);
    spdlog::debug("Random card generated from deck: {}", c);
    return c;
}

void RealDeck::dealCardsToPlayer(std::unique_ptr<Player> &player)
{
    player->setHand({getRandomCard(), getRandomCard()});
}

void RealDeck::dealFlopCards(Board &board)
{
    board.flop_ = {getRandomCard(), getRandomCard(), getRandomCard()};
}

void RealDeck::dealTurnCards(Board &board)
{
    board.turn_ = getRandomCard();
}

void RealDeck::dealRiverCards(Board &board)
{
    board.river_  = getRandomCard();
}
