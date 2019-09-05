cmake_minimum_required(VERSION 2.8)

project(ProTexasPlayerTest)

set(SOURCES src/handtest.cpp
            src/decktest.cpp
            src/main.cpp
            ../src/Hand.cpp
            ../src/deck/RealDeck.cpp)

add_executable(ProTexasPlayerTest ${SOURCES})

if(UNIX)
    target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/../../gtest/libgtest.a pthread)
else()
    target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/../../gtest/libgtest.a)
endif()

include_directories(../../gtest ../inc)
