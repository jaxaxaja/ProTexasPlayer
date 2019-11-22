#include <strategy/range/MpRangeBuilder.h>

std::map<Position, Range> MpRangeBuilder::buildColdCallRange()
{
    std::map<Position, Range> result;
    result[Position::EP] = rangeCreator_.createRange("JJ-99,AQs,AQo,AKo");
    result[Position::CO] = {};
    result[Position::BU] = {};
    result[Position::SB] = {};
    result[Position::BB] = {};

    return result;
}

std::map<Position, Range> MpRangeBuilder::build3bRange()
{
    std::map<Position, Range> result;
    result[Position::EP] = rangeCreator_.createRange("AKs,AA-QQ,AJs,ATs");
    result[Position::CO] = {};
    result[Position::BU] = {};
    result[Position::SB] = {};
    result[Position::BB] = {};

    return result;
}

std::map<Position, Range> MpRangeBuilder::buildVs3bCallRange()
{
    std::map<Position, Range> result;
    result[Position::EP] = rangeCreator_.createRange("AK+,AQs,QQ,JJ"); //this might be limp and then 3b
    result[Position::CO] = rangeCreator_.createRange("AK+,AQs,QQ,JJ");
    result[Position::BU] = rangeCreator_.createRange("AK+,AQs,QQ,JJ");
    result[Position::SB] = rangeCreator_.createRange("AK+,AQs,QQ,JJ");
    result[Position::BB] = rangeCreator_.createRange("AK+,AQs,QQ,JJ");

    return result;
}

std::map<Position, Range> MpRangeBuilder::buildVsSqzCallRange()
{
    std::map<Position, Range> result;
    result[Position::EP] = rangeCreator_.createRange("AQ+,AJs,QQ-66");
    result[Position::CO] = rangeCreator_.createRange("AQ+,AJs,QQ-66");
    result[Position::BU] = rangeCreator_.createRange("AQ+,AJs,QQ-66");
    result[Position::SB] = rangeCreator_.createRange("AQ+,AJs,QQ-66");
    result[Position::BB] = rangeCreator_.createRange("AQ+,AJs,QQ-66");
    return result;
}

std::map<Position, Range> MpRangeBuilder::build4bRange()
{
    std::map<Position, Range> result;
    result[Position::EP] = rangeCreator_.createRange("KK+,AJs");
    result[Position::CO] = rangeCreator_.createRange("KK+,AJs");
    result[Position::BU] = rangeCreator_.createRange("KK+,AJs");
    result[Position::SB] = rangeCreator_.createRange("KK+,AJs");
    result[Position::BB] = rangeCreator_.createRange("KK+,AJs");
    return result;
}

std::map<Position, Range> MpRangeBuilder::buildVs4bCallRange()
{
    std::map<Position, Range> result;
    result[Position::EP] = rangeCreator_.createRange("AKs,QQ");
    result[Position::CO] = rangeCreator_.createRange("AKs,QQ");
    result[Position::BU] = rangeCreator_.createRange("AKs,QQ");
    result[Position::SB] = rangeCreator_.createRange("AKs,QQ");
    result[Position::BB] = rangeCreator_.createRange("AKs,QQ");

    return result;
}

std::map<Position, Range> MpRangeBuilder::buildBrokeRange()
{
    std::map<Position, Range> result;
    result[Position::EP] = rangeCreator_.createRange("KK+");
    result[Position::CO] = rangeCreator_.createRange("KK+");
    result[Position::BU] = rangeCreator_.createRange("KK+");
    result[Position::SB] = rangeCreator_.createRange("KK+");
    result[Position::BB] = rangeCreator_.createRange("KK+");
    return result;
}
