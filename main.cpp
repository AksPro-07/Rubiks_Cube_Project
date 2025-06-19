#include "CubeModel_3D_Array.h"
#include "DFS_Solver.h"
#include "BFS_Solver.h"
#include "IDDFS_Solver.h"

int main() {

    CubeModel_3D_Array cube1;

    cube1.print();


    cout<<"Shuffling the Cube:\n";
    for (auto move_ : cube1.randomShuffle(8)) {
        cout<<Generic_Rubiks_Cube::getMove(move_)<<'\n';
    }
    cube1.print();
    cout<<'\n';
    cout<<"Solving the Cube:\n";
    IDDFS_Solver<CubeModel_3D_Array,Hash_3D> solve_cube(cube1,20);
    for (auto move_ : solve_cube.solve()) {
        cout<<Generic_Rubiks_Cube::getMove(move_)<<'\n';
        cube1.move(move_);
        cube1.print();
    }
    cout<<'\n';

    return 0;
}