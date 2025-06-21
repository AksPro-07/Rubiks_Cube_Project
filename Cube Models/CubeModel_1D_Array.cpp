//
// Created by akshi on 21-06-2025.                          21 - Completed - 21
//

#include "CubeModel_1D_Array.h"


CubeModel_1D_Array::COLOR CubeModel_1D_Array::getColor(FACE face, const unsigned row, const unsigned column) const {
        const char color = cube[getIndex(static_cast<int>(face), static_cast<int>(row), static_cast<int>(column))];
        switch (color) {
            case 'B':
                return COLOR::BLUE;
            case 'R':
                return COLOR::RED;
            case 'G':
                return COLOR::GREEN;
            case 'O':
                return COLOR::ORANGE;
            case 'Y':
                return COLOR::YELLOW;
            default:
                return COLOR::WHITE;
        }
    }

    bool CubeModel_1D_Array::isSolved() const {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (this->cube[getIndex(i, j, k)] == getColorLetter(static_cast<COLOR>(i))) continue;
                    return false;
                }
            }
        }
        return true;
    }

    Generic_Rubiks_Cube &CubeModel_1D_Array::u() {
        this->rotateFace(0);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(4, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, 0, 2 - i)] = cube[getIndex(1, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 0, 2 - i)] = cube[getIndex(2, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 0, 2 - i)] = cube[getIndex(3, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 0, 2 - i)] = temp_arr[i];

        return *this;
    }

    Generic_Rubiks_Cube &CubeModel_1D_Array::uPrime() {
        this->u();
        this->u();
        this->u();

        return *this;
    }

    Generic_Rubiks_Cube &CubeModel_1D_Array::u2() {
        this->u();
        this->u();

        return *this;
    }

    Generic_Rubiks_Cube &CubeModel_1D_Array::l() {
        this->rotateFace(1);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, i, 0)] = cube[getIndex(4, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, 2 - i, 2)] = cube[getIndex(5, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, i, 0)] = cube[getIndex(2, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, i, 0)] = temp_arr[i];

        return *this;
    }

    Generic_Rubiks_Cube &CubeModel_1D_Array::lPrime() {
        this->l();
        this->l();
        this->l();

        return *this;
    }

    Generic_Rubiks_Cube &CubeModel_1D_Array::l2() {
        this->l();
        this->l();

        return *this;
    }

    Generic_Rubiks_Cube &CubeModel_1D_Array::f() {
        this->rotateFace(2);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 2, i)] = cube[getIndex(1, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 2 - i, 2)] = cube[getIndex(5, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 0, 2 - i)] = cube[getIndex(3, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, i, 0)] = temp_arr[i];

        return *this;
    }

    Generic_Rubiks_Cube &CubeModel_1D_Array::fPrime() {
        this->f();
        this->f();
        this->f();

        return *this;
    }

    Generic_Rubiks_Cube &CubeModel_1D_Array::f2() {
        this->f();
        this->f();

        return *this;
    }

    Generic_Rubiks_Cube &CubeModel_1D_Array::r() {
        this->rotateFace(3);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 2 - i, 2)] = cube[getIndex(2, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 2 - i, 2)] = cube[getIndex(5, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 2 - i, 2)] = cube[getIndex(4, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, i, 0)] = temp_arr[i];

        return *this;
    }

    Generic_Rubiks_Cube &CubeModel_1D_Array::rPrime() {
        this->r();
        this->r();
        this->r();

        return *this;
    }

    Generic_Rubiks_Cube &CubeModel_1D_Array::r2() {
        this->r();
        this->r();

        return *this;
    }

    Generic_Rubiks_Cube &CubeModel_1D_Array::b() {
        this->rotateFace(4);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 0, 2 - i)] = cube[getIndex(3, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 2 - i, 2)] = cube[getIndex(5, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 2, i)] = cube[getIndex(1, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, i, 0)] = temp_arr[i];

        return *this;
    }

    Generic_Rubiks_Cube &CubeModel_1D_Array::bPrime() {
        this->b();
        this->b();
        this->b();

        return *this;
    }

    Generic_Rubiks_Cube &CubeModel_1D_Array::b2() {
        this->b();
        this->b();

        return *this;
    }

    Generic_Rubiks_Cube &CubeModel_1D_Array::d() {
        this->rotateFace(5);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(2, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 2, i)] = cube[getIndex(1, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 2, i)] = cube[getIndex(4, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, 2, i)] = cube[getIndex(3, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 2, i)] = temp_arr[i];

        return *this;
    }

    Generic_Rubiks_Cube &CubeModel_1D_Array::dPrime() {
        this->d();
        this->d();
        this->d();

        return *this;
    }

    Generic_Rubiks_Cube &CubeModel_1D_Array::d2() {
        this->d();
        this->d();

        return *this;
    }

    bool CubeModel_1D_Array::operator==(const CubeModel_1D_Array &r1) const {
        for (int i = 0; i < 54; i++) {
            if (cube[i] != r1.cube[i]) return false;
        }
        return true;
    }

    CubeModel_1D_Array &CubeModel_1D_Array::operator=(const CubeModel_1D_Array &r1) {
        for (int i = 0; i < 54; i++) {
            cube[i] = r1.cube[i];
        }
        return *this;
    }