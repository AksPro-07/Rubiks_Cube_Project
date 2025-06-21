#include "Cube Models/CubeModel_3D_Array.h"
#include "Cube Models/CubeModel_1D_Array.h"
#include "Cube Models/CubeModel_Bitboard.h"
#include "Solver Algorithms/DFS_Solver.h"
#include "Solver Algorithms/BFS_Solver.h"
#include "Solver Algorithms/IDDFS_Solver.h"
#include "Solver Algorithms/IDAStar_Solver.h"
#include "Pattern Database/Corner Pattern Database/Corner_Pattern_Database.h"
#include "Pattern Database/Corner Pattern Database/Corner_DB_Maker.h"

int main() {
    //  C:\Users\akshi\CLionProjects\Rubik's Cube Project\Database\Corner_Depth11.txt
    const string fileName = R"(C:\Users\akshi\CLionProjects\Rubik's Cube Project\Database\Corner_Depth11.txt)";



    CubeModel_Bitboard cube1;

    cube1.print();


    cout<<"Shuffling the Cube:\n";
    for (auto move_ : cube1.randomShuffle(18)) {
        cout<<Generic_Rubiks_Cube::getMove(move_)<<'\n';
    }
    cube1.print();
    cout<<'\n';
    cout<<"Solving the Cube:\n";
    IDAStar_Solver<CubeModel_Bitboard,Hash_Bitboard> solve_cube(cube1,fileName);
    for (auto move_ : solve_cube.solve()) {
        cout<<Generic_Rubiks_Cube::getMove(move_)<<'\n';
        cube1.move(move_);
        cube1.print();
    }
    cout<<'\n';


    // Code to create Corner Database
    // Corner_DB_Maker dbMaker(fileName, 0xBB);
    // dbMaker.bfsAndStore();

    return 0;
}