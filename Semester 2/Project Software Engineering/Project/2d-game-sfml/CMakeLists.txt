cmake_minimum_required(VERSION 3.20)
project(project)


# Stel het pad naar SFML in
set(SFML_DIR "C:/SFML/lib/cmake/SFML")


find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)
set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
        main.cpp
        Game.cpp
        Game.h
        Room.cpp
        Room.h
        Entity.cpp
        Entity.h
)
add_executable(project ${SOURCE_FILES})
target_link_libraries(project sfml-graphics sfml-window sfml-system)