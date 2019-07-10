cmake_minimum_required(VERSION 3.10)

project(ProTexasPlayer)

set(SOURCES src/hand.cpp
            src/deck.cpp
            src/range.cpp
            src/main.cpp)
			
add_executable(ProTexasPlayer ${SOURCES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc/)
