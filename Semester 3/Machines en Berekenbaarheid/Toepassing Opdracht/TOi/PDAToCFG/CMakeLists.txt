cmake_minimum_required(VERSION 3.30)
project(PDAToCFG)

set(CMAKE_CXX_STANDARD 17)

add_executable(PDAToCFG main.cpp
        PDA.cpp
        PDA.h
        json.hpp
        Transition.cpp
        Transition.h
        Utils.cpp
        Utils.h
        CFG.h
        CFG.cpp
        Production.cpp
        Production.h)
