cmake_minimum_required(VERSION 3.10)

SET(CMAKE_C_COMPILER C:/Qt/Tools/mingw730_64/bin/gcc.exe)
SET(CMAKE_CXX_COMPILER C:/Qt/Tools/mingw730_64/bin/g++.exe)

project(ProTexasPlayer)

set(SOURCES src/hand.cpp
            src/deck.cpp
            src/range.cpp
            src/main.cpp)
			
add_executable(ProTexasPlayer ${SOURCES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc/)
