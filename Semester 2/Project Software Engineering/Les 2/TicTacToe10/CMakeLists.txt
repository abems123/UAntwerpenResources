cmake_minimum_required(VERSION 3.6)
project(TicTacToe10)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Werror -O2")
set(CMAKE_EXE_LINKER_FLAGS -pthread)

# Set include dir
include_directories(../gtest/include)

# Set Library dir
link_directories(../gtest/lib)

# Set source files for RELEASE target
set(RELEASE_SOURCE_FILES TicTacToe.cpp TicTacToeMain.cpp)

# Set source files for DEBUG target
set(DEBUG_SOURCE_FILES TicTacToe.cpp TicTacToeTests.cpp)

# Create RELEASE target
add_executable(ttt ${RELEASE_SOURCE_FILES})

# Create DEBUG target
add_executable(ttt_debug ${DEBUG_SOURCE_FILES})

# Link library
target_link_libraries(ttt_debug gtest)