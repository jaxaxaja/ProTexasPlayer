cmake_minimum_required(VERSION 3.10)

project(ProTexasPlayerTest)

set(SOURCES src/handtest.cpp
            src/decktest.cpp
            src/main.cpp
            ../src/hand.cpp
            ../src/deck.cpp)

add_executable(ProTexasPlayerTest ${SOURCES})

target_link_libraries(ProTexasPlayerTest ${CMAKE_CURRENT_SOURCE_DIR}/../../gtest/googletest/build/lib/libgtest.a)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../gtest/googletest/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/../inc)
