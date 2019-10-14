cmake_minimum_required(VERSION 2.8)

project(ProTexasPlayer)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)

set(SOURCES src/Card.cpp
            src/Hand.cpp
            src/deck/RealDeck.cpp
            src/deck/StreamDeck.cpp
            src/deck/AhkDeck.cpp
            src/StreamParser.cpp
            src/Position.cpp
            src/Move.cpp
            src/game/Game.cpp
            src/game/PreFlop.cpp
            src/game/Flop.cpp
            src/game/Turn.cpp
            src/game/River.cpp
            src/strategy/AhkStrategy.cpp
            src/strategy/StreamStrategy.cpp
            src/strategy/RealStrategy.cpp
            src/strategy/Range.cpp
            src/Player.cpp
            src/Croupier.cpp
            src/PlayerStatistics.cpp
            src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc ${CMAKE_CURRENT_SOURCE_DIR}/lib/gtest ${CMAKE_CURRENT_SOURCE_DIR}/lib/spdlog)
