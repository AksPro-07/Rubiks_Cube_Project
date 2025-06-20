//
// Created by akshi on 19-06-2025.                          5 - Completed - 3
//

#include "Generic_Rubiks_Cube.h"

#ifndef DFS_SOLVER_H
#define DFS_SOLVER_H

// Typename T: RubiksCube Representation used (3d, 1d, Bitboard)
// Typename H: Corresponding Hash function

// When you are implementing anything, be sure of every step, what and at what condition, it is going to do what only then can you possibly be able to write correct codes.
// Whenever you learn a concept understand it to it's core what it's supposed to do in what scenario and don't just go writing blindly every line you write has it's implementation crystal clear in your mind.
// Here in this, in all the solver code they only carry the core concept and not the implementation you studied because it's a real-world wide problem with no domain and restrictions specified, and when you deal with such situation only your understanding helps in implementing, and not the implementation that you know of that in the exact manners.

template<typename T, typename H>

class DFS_Solver {

private:

    T cube;
    // unordered_map<T,bool,H> visit{};
    vector<Generic_Rubiks_Cube::MOVE> steps{};

    //    DFS code to find the solution (helper function)

    void dfs(int depth) {
        if (cube.isSolved()) {
            return;
        }
        if (depth <=0) {
            return;
        }
        // visit[cube]=true;

        for (unsigned i = 0; i < 18; i++ ) {

            cube.move(static_cast<Generic_Rubiks_Cube::MOVE>(i));

            // if (visit[cube]==true) {
            //     cube.invert(static_cast<Generic_Rubiks_Cube::MOVE>(i));
            //     continue;
            // }

            steps.push_back(static_cast<Generic_Rubiks_Cube::MOVE>(i));
            dfs(depth-1);
            if (cube.isSolved()) {
                return;
            }
            cube.invert(static_cast<Generic_Rubiks_Cube::MOVE>(i));
            steps.pop_back();
        }
    }


public:

    DFS_Solver(T cube_) {
        cube = cube_;
    }

    vector<Generic_Rubiks_Cube::MOVE> solve(int depth) {
        dfs(depth);
        return steps;
    }


};


#endif //DFS_SOLVER_H
