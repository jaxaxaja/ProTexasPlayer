#include "HandEvaluator.h"
#include <algorithm>

bool HandStrength::operator==(const HandStrength& rhs)
{
    return strength_ == rhs.strength_ && handStrength_ == rhs.handStrength_;
}

bool HandStrength::operator>(const HandStrength& rhs)
{
    if (strength_ == rhs.strength_)
    {
        for (int i = 0; i < handStrength_.size(); ++i)
            if (handStrength_[i] > rhs.handStrength_[i])
                return false;
            else if (handStrength_[i] < rhs.handStrength_[i])
                return true;
        return true;
    }
    return strength_ > rhs.strength_;
}

HandStrength HandEvaluator::getHandStrength(Hand playerHand, const std::vector<Card>& flop, Card turn, Card river)
{
    std::fill(cardRanks_.begin(), cardRanks_.end(), 0);
    std::fill(cardSuits_.begin(), cardSuits_.end(), 0);

    ++cardRanks_[static_cast<size_t>(playerHand.get().first)/4];
    ++cardRanks_[static_cast<size_t>(playerHand.get().second)/4];
    ++cardRanks_[static_cast<size_t>(flop.front())/4];
    ++cardRanks_[static_cast<size_t>(flop.at(1))/4];
    ++cardRanks_[static_cast<size_t>(flop.back())/4];
    ++cardRanks_[static_cast<size_t>(turn)/4];
    ++cardRanks_[static_cast<size_t>(river)/4];
    ++cardSuits_[static_cast<size_t>(playerHand.get().first)%4];
    ++cardSuits_[static_cast<size_t>(playerHand.get().second)%4];
    ++cardSuits_[static_cast<size_t>(flop.front())%4];
    ++cardSuits_[static_cast<size_t>(flop.at(1))%4];
    ++cardSuits_[static_cast<size_t>(flop.back())%4];
    ++cardSuits_[static_cast<size_t>(turn)%4];
    ++cardSuits_[static_cast<size_t>(river)%4];

    HandEvaluator::StrengthType result;

    if ((result = isStreightFlush()).first)
        return HandStrength(HandStrength::StraightFlush, result.second);
    if ((result = isQuads()).first)
        return HandStrength(HandStrength::Quads, result.second);
    if ((result = isFullHouse()).first)
        return HandStrength(HandStrength::FullHouse, result.second);
    if ((result = isFlush()).first)
        return HandStrength(HandStrength::Flush, result.second);
    if ((result = isStreight()).first)
        return HandStrength(HandStrength::Streight, result.second);
    if ((result = isTriple()).first)
        return HandStrength(HandStrength::Triple, result.second);
    if ((result = isTwoPair()).first)
        return HandStrength(HandStrength::TwoPair, result.second);
    if ((result = isPair()).first)
        return HandStrength(HandStrength::Pair, result.second);

    return HandStrength(HandStrength::HighCard, {highCard(1), highCard(2), highCard(3), highCard(4), highCard(5)});
}

HandEvaluator::StrengthType HandEvaluator::isStreightFlush()
{

    return std::make_pair(false, std::vector<size_t>());
}

HandEvaluator::StrengthType HandEvaluator::isQuads()
{
    auto quads = std::find_if(cardRanks_.begin(), cardRanks_.end(), [](const size_t v){ return v == 4; });

    if (quads != cardRanks_.end())
    {
        size_t quadsRanking = std::distance(cardRanks_.begin(), quads);
        std::vector<size_t> v = {quadsRanking, quadsRanking, quadsRanking, quadsRanking, highCard(1,3)}; //fill the rest with high Cards
        return std::make_pair(true, v);
    }

    return std::make_pair(false, std::vector<size_t>());
}

HandEvaluator::StrengthType HandEvaluator::isFullHouse()
{
    auto triple = std::find_if(cardRanks_.begin(), cardRanks_.end(), [](const size_t v){ return v == 3; });
    size_t count = 0;
    auto firstPair = std::find_if(cardRanks_.begin(), cardRanks_.end(), [&count](const size_t v){ if (v == 2) return true; return v == 3 && ++count == 2; });

    if(triple != cardRanks_.end() && firstPair != cardRanks_.end())
    {
        size_t tripleRanking = std::distance(cardRanks_.begin(), triple);
        size_t firstPairRanking = std::distance(cardRanks_.begin(), firstPair);
        std::vector<size_t> v = {tripleRanking, tripleRanking, tripleRanking, firstPairRanking, firstPairRanking};
        return std::make_pair(true, v);
    }

    return std::make_pair(false, std::vector<size_t>());
}

HandEvaluator::StrengthType HandEvaluator::isFlush()
{
    auto isFlush = [](const size_t v){ return v >= 5; };
    auto flush = std::find_if(cardSuits_.begin(), cardSuits_.end(), isFlush);

    if (flush != cardSuits_.end())
    {

        return std::make_pair(true, std::vector<size_t>());
    }

    return std::make_pair(false, std::vector<size_t>());
}

HandEvaluator::StrengthType HandEvaluator::isStreight()
{
    int count = 0;
    auto isStreight = [&count](const size_t n){ if (n > 0) ++count; else count = 0; return count >= 5; };
    auto streight = std::find_if(cardRanks_.begin(), cardRanks_.end(), isStreight);

    if (streight != cardRanks_.end())
    {
        size_t streightRanking = std::distance(cardRanks_.begin(), streight);
        std::vector<size_t> v = {streightRanking-4, streightRanking-3, streightRanking-2, streightRanking-1, streightRanking};
        return std::make_pair(true, v);
    }

    return std::make_pair(false, std::vector<size_t>());
}

HandEvaluator::StrengthType HandEvaluator::isTriple()
{
    auto triple = std::find_if(cardRanks_.begin(), cardRanks_.end(), [](const size_t v){ return v == 3; });

    if (triple != cardRanks_.end())
    {
        size_t tripleRanking = std::distance(cardRanks_.begin(), triple);
        std::vector<size_t> v = {tripleRanking, tripleRanking, tripleRanking, highCard(1), highCard(2)}; //fill the rest with high Cards
        return std::make_pair(true, v);
    }

    return std::make_pair(false, std::vector<size_t>());
}

HandEvaluator::StrengthType HandEvaluator::isTwoPair()
{
    int count = 0;
    auto firstPair = std::find_if(cardRanks_.begin(), cardRanks_.end(), [](const size_t v){ return v == 2; });
    auto secondPair = std::find_if(cardRanks_.begin(), cardRanks_.end(), [&count](const size_t v){ return v == 2 && ++count == 2;});
    count = 0;
    auto highCard = std::find_if(cardRanks_.begin(), cardRanks_.end(), [&count](const size_t v){ return v == 1 || (v == 2 && ++count == 3); });

    if (secondPair != cardRanks_.end() && firstPair != cardRanks_.end() && secondPair != firstPair)
    {
        size_t firstPairRanking = std::distance(cardRanks_.begin(), firstPair);
        size_t secondPairRanking = std::distance(cardRanks_.begin(), secondPair);
        size_t highCardRanking = std::distance(cardRanks_.begin(), highCard);
        std::vector<size_t> v = {firstPairRanking, firstPairRanking, secondPairRanking, secondPairRanking, highCardRanking};
        return std::make_pair(true, v);
    }
    return std::make_pair(false, std::vector<size_t>());
}

HandEvaluator::StrengthType HandEvaluator::isPair()
{
    auto firstPair = std::find_if(cardRanks_.begin(), cardRanks_.end(), [](const size_t v){ return v == 2; });

    if (firstPair != cardRanks_.end())
    {
        size_t pairRanking = std::distance(cardRanks_.begin(), firstPair);
        std::vector<size_t> v = {pairRanking, pairRanking, highCard(1), highCard(2), highCard(3)}; //fill the rest with high Cards
        return std::make_pair(true, v);
    }
    return std::make_pair(false, std::vector<size_t>());
}

size_t HandEvaluator::highCard(const size_t t, const size_t ini)
{
    size_t count = 0;
    auto nthElem = std::find_if(cardRanks_.begin(), cardRanks_.end(), [&count, &t, &ini](const size_t v){ return v != 0 && v <= ini && ++count == t; });

    if (nthElem != cardRanks_.end())
            return std::distance(cardRanks_.begin(), nthElem);
    return 0;
}
