#include "CubeModel_3D_Array.h"
#include "CubeModel_1D_Array.h"
#include "CubeModel_Bitboard.h"
#include "DFS_Solver.h"
#include "BFS_Solver.h"
#include "IDDFS_Solver.h"
#include "IDAStar_Solver.h"
#include "Corner_Pattern_Database.h"
#include "Corner_DB_Maker.h"

int main() {
    //  C:\Users\akshi\CLionProjects\Rubik’s Cube Project\Corner_Depth.txt
    string fileName = "C:\\Users\\akshi\\CLionProjects\\Rubik's Cube Project\\Corner_Depth.txt";


    //    Code to create Corner Database
    Corner_DB_Maker dbMaker(fileName, 0x55);
    dbMaker.bfsAndStore();
    //
    // CubeModel_Bitboard cube1;
    //
    // cube1.print();
    //
    //
    // cout<<"Shuffling the Cube:\n";
    // for (auto move_ : cube1.randomShuffle(9)) {
    //     cout<<Generic_Rubiks_Cube::getMove(move_)<<'\n';
    // }
    // cube1.print();
    // cout<<'\n';
    // cout<<"Solving the Cube:\n";
    // IDAStar_Solver<CubeModel_Bitboard,Hash_Bitboard> solve_cube(cube1,fileName);
    // for (auto move_ : solve_cube.solve()) {
    //     cout<<Generic_Rubiks_Cube::getMove(move_)<<'\n';
    //     cube1.move(move_);
    //     cube1.print();
    // }
    // cout<<'\n';

    return 0;
}