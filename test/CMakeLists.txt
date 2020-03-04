cmake_minimum_required(VERSION 2.8)

project(ProTexasPlayerTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(SOURCES src/handtest.cpp
            src/decktest.cpp
            src/streamparsertest.cpp
            src/streamdecktest.cpp
            src/streamstrategytest.cpp
            src/handevaluatortest.cpp
            src/playertest.cpp
            src/croupiertest.cpp
            src/gametest.cpp
            src/rangecreatortest.cpp
            src/realstrategytest.cpp
            src/main.cpp
            ../src/Card.cpp
            ../src/Hand.cpp
            ../src/deck/RealDeck.cpp
            ../src/StreamParser.cpp
            ../src/HandEvaluator.cpp
            ../src/deck/StreamDeck.cpp
            ../src/game/Game.cpp
            ../src/Croupier.cpp
            ../src/Player.cpp
            ../src/move/Move.cpp
            ../src/move/Fold.cpp
            ../src/move/Call.cpp
            ../src/move/Bet.cpp
            ../src/move/Raise.cpp
            ../src/move/PlayerMoveInfo.cpp
            ../src/Position.cpp
            ../src/strategy/StreamStrategy.cpp
            ../src/strategy/RealStrategy.cpp
            ../src/strategy/StrategyState.cpp
            ../src/strategy/PreFlopStrategy.cpp
            ../src/strategy/FlopStrategy.cpp
            ../src/strategy/TurnStrategy.cpp
            ../src/strategy/RiverStrategy.cpp
            ../src/strategy/range/RangeCreator.cpp
            ../src/strategy/range/PositionalRange.cpp
            ../src/strategy/range/RangeBuilder.cpp
            ../src/strategy/range/EpRangeBuilder.cpp
            ../src/strategy/range/MpRangeBuilder.cpp
            ../src/strategy/range/CoRangeBuilder.cpp
            ../src/strategy/range/BuRangeBuilder.cpp
            ../src/strategy/range/SbRangeBuilder.cpp
            ../src/strategy/range/BbRangeBuilder.cpp)

add_executable(ProTexasPlayerTest ${SOURCES})

if(UNIX)
    target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/../lib/gtest/libgtest.a pthread)
else()
    target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/../lib/gtestWin/libgtest.a)
endif()

include_directories(../lib/gtest ../lib/spdlog ../inc ../lib/boost)
