cmake_minimum_required(VERSION 2.8)

project(ProTexasPlayerTest)

set(SOURCES src/handtest.cpp
            src/decktest.cpp
            src/gametest.cpp
            src/streamparsertest.cpp
            src/main.cpp
            ../src/Card.cpp
            ../src/Hand.cpp
            ../src/deck/RealDeck.cpp
            ../src/deck/StreamParser.cpp
            ../src/game/Game.cpp
            ../src/Croupier.cpp
            ../src/Player.cpp)

add_executable(ProTexasPlayerTest ${SOURCES})

if(UNIX)
    target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/../lib/gtest/libgtest.a pthread)
else()
    target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/../lib/gtest/libgtest.a)
endif()

include_directories(../lib/gtest ../lib/spdlog ../inc)
