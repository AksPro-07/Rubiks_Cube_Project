//
// Created by akshi on 21-06-2025.                          22 - Completed - 22
//

#ifndef CUBEMODEL_BITBOARD_H
#define CUBEMODEL_BITBOARD_H


#include "Generic_Rubiks_Cube.h"

class CubeModel_Bitboard : public Generic_Rubiks_Cube {

private:
    uint64_t solved_side_config[6]{};

    int arr[3][3] = {{0, 1, 2},
                     {7, 8, 3},
                     {6, 5, 4}};

    uint64_t one_8 = (1 << 8) - 1, one_24 = (1 << 24) - 1;

    void rotateFace(int ind) {
        uint64_t side = bitboard[ind];
        side = side >> (8 * 6);
        bitboard[ind] = (bitboard[ind] << 16) | (side);
    }

    void rotateSide(int s1, int s1_1, int s1_2, int s1_3, int s2, int s2_1, int s2_2, int s2_3) {
        uint64_t clr1 = (bitboard[s2] & (one_8 << (8 * s2_1))) >> (8 * s2_1);
        uint64_t clr2 = (bitboard[s2] & (one_8 << (8 * s2_2))) >> (8 * s2_2);
        uint64_t clr3 = (bitboard[s2] & (one_8 << (8 * s2_3))) >> (8 * s2_3);

        bitboard[s1] = (bitboard[s1] & ~(one_8 << (8 * s1_1))) | (clr1 << (8 * s1_1));
        bitboard[s1] = (bitboard[s1] & ~(one_8 << (8 * s1_2))) | (clr2 << (8 * s1_2));
        bitboard[s1] = (bitboard[s1] & ~(one_8 << (8 * s1_3))) | (clr3 << (8 * s1_3));
    }

//    Helper to getCorners()
    static int get5bitCorner(const string &corner) {
        int ret = 0;
        string actual_str;
        for (auto c: corner) {
            if (c != 'W' && c != 'Y') continue;
            actual_str.push_back(c);
            if (c == 'Y') {
                ret |= (1 << 2);
            }
        }

        for (auto c: corner) {
            if (c != 'R' && c != 'O') continue;
            if (c == 'O') {
                ret |= (1 << 1);
            }
        }

        for (auto c: corner) {
            if (c != 'B' && c != 'G') continue;
            if (c == 'G') {
                ret |= (1 << 0);
            }
        }

        if (corner[1] == actual_str[0]) {
            ret |= (1 << 3);
        } else if (corner[2] == actual_str[0]) {
            ret |= (1 << 4);
        }
        return ret;
    }

    //    This function was used for testing / printing

//    void print5bitbin(int a){
//        for(int i=4; i>=0; i--){
//            if(a & (1 << i)) cout << 1;
//            else cout << 0;
//        }
//    }

public:
    uint64_t bitboard[6]{};

    CubeModel_Bitboard() {
        for (int side = 0; side < 6; side++) {
            uint64_t clr = 1 << side;
            bitboard[side] = 0;
            for (int faceIdx = 0; faceIdx < 8; faceIdx++) {
                bitboard[side] |= clr << (8 * faceIdx);
            }
            solved_side_config[side] = bitboard[side];
        }
    }


    COLOR getColor(FACE face, unsigned row, unsigned col) const override;

    bool isSolved() const override;

    Generic_Rubiks_Cube &u() override;

    Generic_Rubiks_Cube &uPrime() override;

    Generic_Rubiks_Cube &u2() override;

    Generic_Rubiks_Cube &l() override;

    Generic_Rubiks_Cube &lPrime() override;

    Generic_Rubiks_Cube &l2() override;

    Generic_Rubiks_Cube &f() override;

    Generic_Rubiks_Cube &fPrime() override;

    Generic_Rubiks_Cube &f2() override;

    Generic_Rubiks_Cube &r() override;

    Generic_Rubiks_Cube &rPrime() override;

    Generic_Rubiks_Cube &r2() override;

    Generic_Rubiks_Cube &b() override;

    Generic_Rubiks_Cube &bPrime() override;

    Generic_Rubiks_Cube &b2() override;

    Generic_Rubiks_Cube &d() override;

    Generic_Rubiks_Cube &dPrime() override;

    Generic_Rubiks_Cube &d2() override;

    uint64_t getCorners() const;

    bool operator==(const CubeModel_Bitboard &r1) const;

    CubeModel_Bitboard &operator=(const CubeModel_Bitboard &r1);


};

struct Hash_Bitboard {
    size_t operator()(const CubeModel_Bitboard &r1) const {
        uint64_t final_hash = r1.bitboard[0];
        for (int i = 1; i < 6; i++) final_hash ^= r1.bitboard[i];
        return (size_t) final_hash;
    }
};



#endif //CUBEMODEL_BITBOARD_H
