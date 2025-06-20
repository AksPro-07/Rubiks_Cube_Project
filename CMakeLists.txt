cmake_minimum_required(VERSION 3.31)
project(Rubiks_Cube_Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Rubiks_Cube_Project main.cpp
        Generic_Rubiks_Cube.cpp
        Generic_Rubiks_Cube.h
        CubeModel_3D_Array.cpp
        CubeModel_3D_Array.cpp
        CubeModel_3D_Array.h
        DFS_Solver.h
        BFS_Solver.h
        IDDFS_Solver.h
        IDAStar_Solver.h
        Nibble_Array.cpp
        Nibble_Array.h
        Pattern_Database.cpp
        Pattern_Database.h
        math.cpp
        math.h
        Permutation_Indexer.h
        Corner_Pattern_Database.cpp
        Corner_Pattern_Database.h
        Corner_DB_Maker.cpp
        Corner_DB_Maker.h
        CubeModel_1D_Array.cpp
        CubeModel_1D_Array.h
        CubeModel_Bitboard.cpp
        CubeModel_Bitboard.h)
