//
// Created by akshi on 21-06-2025.                          20 - Completed - 20
//

#ifndef CUBEMODEL_1D_ARRAY_H
#define CUBEMODEL_1D_ARRAY_H


#include "Generic_Rubiks_Cube.h"

class CubeModel_1D_Array : public Generic_Rubiks_Cube {
private:

    /*
     * Given a face index, row and col, return it's flattened index
     */
    static inline int getIndex(int ind, int row, int col) {
        return (ind * 9) + (row * 3) + col;
    }

    void rotateFace(int ind) {
        char temp_arr[9] = {};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                temp_arr[i * 3 + j] = cube[getIndex(ind, i, j)];
            }
        }
        for (int i = 0; i < 3; i++) cube[getIndex(ind, 0, i)] = temp_arr[getIndex(0, 2 - i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(ind, i, 2)] = temp_arr[getIndex(0, 0, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(ind, 2, 2 - i)] = temp_arr[getIndex(0, i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(ind, 2 - i, 0)] = temp_arr[getIndex(0, 2, 2 - i)];
    }

public:
    char cube[54]{};

    CubeModel_1D_Array() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[i * 9 + j * 3 + k] = getColorLetter(static_cast<COLOR>(i));
                }
            }
        }
    }

    [[nodiscard]] COLOR getColor(FACE face, unsigned row, unsigned column) const override;

    [[nodiscard]] bool isSolved() const override;

    Generic_Rubiks_Cube &f() override;

    Generic_Rubiks_Cube &fPrime() override;

    Generic_Rubiks_Cube &f2() override;

    Generic_Rubiks_Cube &b() override;

    Generic_Rubiks_Cube &bPrime() override;

    Generic_Rubiks_Cube &b2() override;

    Generic_Rubiks_Cube &u() override;

    Generic_Rubiks_Cube &uPrime() override;

    Generic_Rubiks_Cube &u2() override;

    Generic_Rubiks_Cube &d() override;

    Generic_Rubiks_Cube &dPrime() override;

    Generic_Rubiks_Cube &d2() override;

    Generic_Rubiks_Cube &l() override;

    Generic_Rubiks_Cube &lPrime() override;

    Generic_Rubiks_Cube &l2() override;

    Generic_Rubiks_Cube &r() override;

    Generic_Rubiks_Cube &rPrime() override;

    Generic_Rubiks_Cube &r2() override;

    bool operator==(const CubeModel_1D_Array &r1) const;

    CubeModel_1D_Array &operator=(const CubeModel_1D_Array &r1);

};

struct Hash_1D {
    size_t operator()(const CubeModel_1D_Array &r1) const {
        string str;
        for (const char i : r1.cube) str += i;
        return hash<string>()(str);
    }
};



#endif //CUBEMODEL_1D_ARRAY_H
