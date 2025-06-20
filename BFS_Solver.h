//
// Created by akshi on 19-06-2025.                          6 - Completed - 4
//

#include "Generic_Rubiks_Cube.h"

#ifndef BFS_SOLVER_H
#define BFS_SOLVER_H

template<typename T, typename H>

class BFS_Solver {

private:

    T cube;
    vector<Generic_Rubiks_Cube::MOVE> steps{};
    unordered_map<T,bool,H> visit{};
    unordered_map<T,Generic_Rubiks_Cube::MOVE,H> move_used{};

    void bfs() {
        queue<T> que;
        que.push(cube);
        while (!que.empty()) {
            T current_cube = que.front();
            que.pop();
            if (visit[current_cube]) continue;
            visit[current_cube] = true;
            if (current_cube.isSolved()) return;
            for (unsigned int i = 0; i < 18; i++) {
                current_cube.move(static_cast<Generic_Rubiks_Cube::MOVE>(i));
                if (visit[current_cube]) {
                    current_cube.invert(static_cast<Generic_Rubiks_Cube::MOVE>(i));
                    continue;
                }
                move_used[current_cube] = static_cast<Generic_Rubiks_Cube::MOVE>(i);
                que.push(current_cube);
                if (current_cube.isSolved()) return;
                current_cube.invert(static_cast<Generic_Rubiks_Cube::MOVE>(i));
            }
        }
    }

public:

    BFS_Solver(T cube_) {
        cube = cube_;
    }

    vector<Generic_Rubiks_Cube::MOVE> solve() {
        bfs();
        T solved_cube = T();
        stack<Generic_Rubiks_Cube::MOVE> store;
        while (!(solved_cube==cube)) {
        store.push(move_used[solved_cube]);
            solved_cube.invert(move_used[solved_cube]);
        }
        while (!store.empty()) {
            steps.push_back(store.top());
            store.pop();
        }
        return steps;
    }


};


#endif //BFS_SOLVER_H
