cmake_minimum_required(VERSION 3.31)
project(Rubiks_Cube_Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Rubiks_Cube_Project main.cpp
        "Cube Models/Generic_Rubiks_Cube.cpp"
        "Cube Models/Generic_Rubiks_Cube.h"
        "Cube Models/CubeModel_3D_Array.cpp"
        "Cube Models/CubeModel_3D_Array.cpp"
        "Cube Models/CubeModel_3D_Array.h"
        "Solver Algorithms/DFS_Solver.h"
        "Solver Algorithms/BFS_Solver.h"
        "Solver Algorithms/IDDFS_Solver.h"
        "Solver Algorithms/IDAStar_Solver.h"
        "Database/Database Constructor/Nibble_Array.cpp"
        "Database/Database Constructor/Nibble_Array.h"
        "Pattern Database/Pattern_Database.cpp"
        "Pattern Database/Pattern_Database.h"
        BlackBOX/math.cpp
        BlackBOX/math.h
        BlackBOX/Permutation_Indexer.h
        "Pattern Database/Corner Pattern Database/Corner_Pattern_Database.cpp"
        "Pattern Database/Corner Pattern Database/Corner_Pattern_Database.h"
        "Pattern Database/Corner Pattern Database/Corner_DB_Maker.cpp"
        "Pattern Database/Corner Pattern Database/Corner_DB_Maker.h"
        "Cube Models/CubeModel_1D_Array.cpp"
        "Cube Models/CubeModel_1D_Array.h"
        "Cube Models/CubeModel_Bitboard.cpp"
        "Cube Models/CubeModel_Bitboard.h")
