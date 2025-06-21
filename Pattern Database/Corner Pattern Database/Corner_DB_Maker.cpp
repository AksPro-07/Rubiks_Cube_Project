//
// Created by akshi on 20-06-2025.                          19 - Completed - 18
//

#include "Corner_DB_Maker.h"


using namespace std;

Corner_DB_Maker::Corner_DB_Maker(const string &_fileName) {
    fileName = _fileName;
}

Corner_DB_Maker::Corner_DB_Maker(const string &_fileName, uint8_t init_val) {
    fileName = _fileName;
    cornerDB = Corner_Pattern_Database(init_val);
}

bool Corner_DB_Maker::bfsAndStore() {
    CubeModel_Bitboard cube;
    queue<CubeModel_Bitboard> q;
    q.push(cube);
    cornerDB.setNumMoves(cube, 0);
    int curr_depth = 0;
    while (!q.empty()) {
        int n = q.size();
        curr_depth++;
        if (curr_depth == 9) break;
        for (int counter = 0; counter < n; counter++) {
            CubeModel_Bitboard node = q.front();
            q.pop();
            for (int i = 0; i < 18; i++) {
                auto curr_move = static_cast<Generic_Rubiks_Cube::MOVE>(i);
                node.move(curr_move);
                if (static_cast<int>(cornerDB.getNumMoves(node)) > curr_depth) {
                    cornerDB.setNumMoves(node, curr_depth);
                    q.push(node);
                }
                node.invert(curr_move);
            }
        }
    }

    cornerDB.toFile(fileName);
    return true;
}