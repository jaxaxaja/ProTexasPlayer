#include <strategy/range/BbRangeBuilder.h>

std::map<Position, Range> BbRangeBuilder::buildColdCallRange()
{
    std::map<Position, Range> result;
    result[Position::EP] = rangeCreator_.createRange("JJ-99,AQs,AQo,AKo");
    result[Position::MP] = {};//add range
    result[Position::CO] = {};
    result[Position::BU] = {};
    result[Position::SB] = {};

    return result;
}

std::map<Position, Range> BbRangeBuilder::build3bRange()
{
    std::map<Position, Range> result;
    result[Position::EP] = rangeCreator_.createRange("AKs,AA-QQ,AJs,ATs");
    result[Position::MP] = {};//add range
    result[Position::CO] = {};
    result[Position::BU] = {};
    result[Position::SB] = {};

    return result;
}

std::map<Position, Range> BbRangeBuilder::buildVs3bCallRange()
{
    std::map<Position, Range> result;
    result[Position::EP] = rangeCreator_.createRange("AK+,AQs,QQ,JJ"); //this might be limp and then 3b
    result[Position::MP] = rangeCreator_.createRange("AK+,AQs,QQ,JJ");
    result[Position::CO] = rangeCreator_.createRange("AK+,AQs,QQ,JJ");
    result[Position::BU] = rangeCreator_.createRange("AK+,AQs,QQ,JJ");
    result[Position::SB] = rangeCreator_.createRange("AK+,AQs,QQ,JJ");

    return result;
}

std::map<Position, Range> BbRangeBuilder::buildVsSqzCallRange()
{
    std::map<Position, Range> result;
    result[Position::EP] = rangeCreator_.createRange("AQ+,AJs,QQ-66");
    result[Position::MP] = rangeCreator_.createRange("AQ+,AJs,QQ-66");
    result[Position::CO] = rangeCreator_.createRange("AQ+,AJs,QQ-66");
    result[Position::BU] = rangeCreator_.createRange("AQ+,AJs,QQ-66");
    result[Position::SB] = rangeCreator_.createRange("AQ+,AJs,QQ-66");
    return result;
}

std::map<Position, Range> BbRangeBuilder::build4bRange()
{
    std::map<Position, Range> result;
    result[Position::EP] = rangeCreator_.createRange("KK+,AJs");
    result[Position::MP] = rangeCreator_.createRange("KK+,AJs");
    result[Position::CO] = rangeCreator_.createRange("KK+,AJs");
    result[Position::BU] = rangeCreator_.createRange("KK+,AJs");
    result[Position::SB] = rangeCreator_.createRange("KK+,AJs");
    return result;
}

std::map<Position, Range> BbRangeBuilder::buildVs4bCallRange()
{
    std::map<Position, Range> result;
    result[Position::EP] = rangeCreator_.createRange("AKs,QQ");
    result[Position::MP] = rangeCreator_.createRange("AKs,QQ");
    result[Position::CO] = rangeCreator_.createRange("AKs,QQ");
    result[Position::BU] = rangeCreator_.createRange("AKs,QQ");
    result[Position::SB] = rangeCreator_.createRange("AKs,QQ");

    return result;
}

std::map<Position, Range> BbRangeBuilder::buildBrokeRange()
{
    std::map<Position, Range> result;
    result[Position::EP] = rangeCreator_.createRange("KK+");
    result[Position::MP] = rangeCreator_.createRange("KK+");
    result[Position::CO] = rangeCreator_.createRange("KK+");
    result[Position::BU] = rangeCreator_.createRange("KK+");
    result[Position::SB] = rangeCreator_.createRange("KK+");
    return result;
}
