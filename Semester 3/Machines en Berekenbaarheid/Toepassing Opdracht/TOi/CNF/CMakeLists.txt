cmake_minimum_required(VERSION 3.30)
project(CNF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CNF main.cpp
        CFG.cpp
        CFG.h
        json.hpp
        Production.h
        Production.cpp
        Utils.cpp
        Utils.h)
