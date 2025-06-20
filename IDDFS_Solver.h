//
// Created by akshi on 19-06-2025.                          7 - Completed - 5
//

#include "Generic_Rubiks_Cube.h"

#ifndef IDDFS_SOLVER_H
#define IDDFS_SOLVER_H

template<typename T, typename H>

class IDDFS_Solver {

private:

    T cube;
    int max_depth;
    vector<Generic_Rubiks_Cube::MOVE> steps{};

public:

    IDDFS_Solver(T cube_, int max_depth_) {
        cube = cube_;
        max_depth = max_depth_;
    }

    vector<Generic_Rubiks_Cube::MOVE> solve() {
        for (unsigned i = 1; i <= max_depth ; i++) {
            DFS_Solver<T,H> solve_cube(cube);
            steps = solve_cube.solve(i);
            if (steps.empty()==false) {
                return solve_cube.solve(i);
            }
        }
        return steps;
    }


};


#endif //IDDFS_SOLVER_H
