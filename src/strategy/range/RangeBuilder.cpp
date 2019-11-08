#include <strategy/range/RangeBuilder.h>
#include <strategy/range/EpRangeBuilder.h>
#include <strategy/range/MpRangeBuilder.h>
#include <strategy/range/CoRangeBuilder.h>
#include <strategy/range/BuRangeBuilder.h>
#include <strategy/range/SbRangeBuilder.h>
#include <strategy/range/BbRangeBuilder.h>

std::unique_ptr<RangeBuilder> RangeBuilder::createBuilder(const Position& position)
{
    switch (position) {
    case Position::EP:
        return std::make_unique<EpRangeBuilder>();
        break;
    case Position::MP:
        return std::make_unique<MpRangeBuilder>();
        break;
    case Position::CO:
        return std::make_unique<CoRangeBuilder>();
        break;
    case Position::BU:
        return std::make_unique<BuRangeBuilder>();
        break;
    case Position::SB:
        return std::make_unique<SbRangeBuilder>();
        break;
    case Position::BB:
        return std::make_unique<BbRangeBuilder>();
        break;
    default:
        break;
    }
}
