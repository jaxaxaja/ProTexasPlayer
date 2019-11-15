#include <strategy/range/EpRangeBuilder.h>

std::map<Position, Range> EpRangeBuilder::buildVs3bCallRange()
{
    std::map<Position, Range> result;
    result[Position::MP] = rangeCreator_.createRange("AK+,AQs,QQ,JJ");
    result[Position::CO] = rangeCreator_.createRange("AK+,AQs,QQ,JJ");
    result[Position::BU] = rangeCreator_.createRange("AK+,AQs,QQ,JJ");
    result[Position::SB] = rangeCreator_.createRange("AK+,AQs,QQ,JJ");
    result[Position::BB] = rangeCreator_.createRange("AK+,AQs,QQ,JJ");

    return result;
}

std::map<Position, Range> EpRangeBuilder::buildVsSqzCallRange()
{
    std::map<Position, Range> result;
    result[Position::MP] = rangeCreator_.createRange("AQ+,AJs,QQ-66");
    result[Position::CO] = rangeCreator_.createRange("AQ+,AJs,QQ-66");
    result[Position::BU] = rangeCreator_.createRange("AQ+,AJs,QQ-66");
    result[Position::SB] = rangeCreator_.createRange("AQ+,AJs,QQ-66");
    result[Position::BB] = rangeCreator_.createRange("AQ+,AJs,QQ-66");
    return result;
}

std::map<Position, Range> EpRangeBuilder::build4bRange()
{
    std::map<Position, Range> result;
    result[Position::MP] = rangeCreator_.createRange("KK+,AJs");
    result[Position::CO] = rangeCreator_.createRange("KK+,AJs");
    result[Position::BU] = rangeCreator_.createRange("KK+,AJs");
    result[Position::SB] = rangeCreator_.createRange("KK+,AJs");
    result[Position::BB] = rangeCreator_.createRange("KK+,AJs");
    return result;
}

std::map<Position, Range> EpRangeBuilder::buildVs4bCallRange()
{
    std::map<Position, Range> result;
    result[Position::MP] = rangeCreator_.createRange("AKs,QQ");
    result[Position::CO] = rangeCreator_.createRange("AKs,QQ");
    result[Position::BU] = rangeCreator_.createRange("AKs,QQ");
    result[Position::SB] = rangeCreator_.createRange("AKs,QQ");
    result[Position::BB] = rangeCreator_.createRange("AKs,QQ");

    return result;
}

std::map<Position, Range> EpRangeBuilder::buildBrokeRange()
{
    std::map<Position, Range> result;
    result[Position::MP] = rangeCreator_.createRange("KK+");
    result[Position::CO] = rangeCreator_.createRange("KK+");
    result[Position::BU] = rangeCreator_.createRange("KK+");
    result[Position::SB] = rangeCreator_.createRange("KK+");
    result[Position::BB] = rangeCreator_.createRange("KK+");
    return result;
}
