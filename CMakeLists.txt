cmake_minimum_required(VERSION 3.31)
project(Rubiks_Cube_Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Rubiks_Cube_Project main.cpp
        Generic_Rubiks_Cube.cpp
        Generic_Rubiks_Cube.h)
