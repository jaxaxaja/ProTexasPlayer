cmake_minimum_required(VERSION 2.8)

project(ProTexasPlayer)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)

set(SOURCES src/Hand.cpp
            src/deck/RealDeck.cpp
            src/deck/AhkDeck.cpp
            src/range.cpp
            src/game.cpp
            src/player.cpp
            src/croupier.cpp
            src/strategy.cpp
            src/playerStatistics.cpp
            src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc ../gtest)
