//
// Created by akshi on 18-06-2025.                          4 - Completed - 2
//

#include "CubeModel_3D_Array.h"

    // Now, we need to define all the virtual functions for the parent class Generic_Rubiks_Cube.
    // And you can't use override outside the class implementation, so I have written it on the declaration side.

    [[nodiscard]] CubeModel_3D_Array::COLOR CubeModel_3D_Array::getColor(FACE face, unsigned row, unsigned column) const {
        switch (cube[static_cast<int>(face)][row][column]) {            // A bit of change just to get rid of warnings and nothing.
            case 'R' : return COLOR::RED;
            case 'G' : return COLOR::GREEN;
            case 'B' : return COLOR::BLUE;
            case 'Y' : return COLOR::YELLOW;
            case 'W' : return COLOR::WHITE;
            case 'O' : return COLOR::ORANGE;
            default: throw std::runtime_error("Invalid color character in cube.");
        }
    }

    [[nodiscard]] bool CubeModel_3D_Array::isSolved() const {
         for (int i = 0; i < 6; i++) {
             for (int j = 0; j < 3; j++) {
                 for (int k = 0; k < 3; k++) {
                     if(cube[i][j][k] == getColorLetter(static_cast<COLOR>(i)))continue;
                     return false;
                 }
             }
         }
        return true;
    }

        Generic_Rubiks_Cube & CubeModel_3D_Array::u() {
        this->rotateFace(0);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[4][0][2 - i];
        for (int i = 0; i < 3; i++) cube[4][0][2 - i] = cube[1][0][2 - i];
        for (int i = 0; i < 3; i++) cube[1][0][2 - i] = cube[2][0][2 - i];
        for (int i = 0; i < 3; i++) cube[2][0][2 - i] = cube[3][0][2 - i];
        for (int i = 0; i < 3; i++) cube[3][0][2 - i] = temp_arr[i];

        return *this;
    }

    Generic_Rubiks_Cube & CubeModel_3D_Array::uPrime() {
        this->u();
        this->u();
        this->u();

        return *this;
    }

    Generic_Rubiks_Cube & CubeModel_3D_Array::u2() {
        this->u();
        this->u();

        return *this;
    }

    Generic_Rubiks_Cube & CubeModel_3D_Array::l() {
        this->rotateFace(1);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][i][0];
        for (int i = 0; i < 3; i++) cube[0][i][0] = cube[4][2 - i][2];
        for (int i = 0; i < 3; i++) cube[4][2 - i][2] = cube[5][i][0];
        for (int i = 0; i < 3; i++) cube[5][i][0] = cube[2][i][0];
        for (int i = 0; i < 3; i++) cube[2][i][0] = temp_arr[i];

        return *this;
    }

    Generic_Rubiks_Cube & CubeModel_3D_Array::lPrime() {
        this->l();
        this->l();
        this->l();

        return *this;
    }

    Generic_Rubiks_Cube & CubeModel_3D_Array::l2() {
        this->l();
        this->l();

        return *this;
    }

    Generic_Rubiks_Cube & CubeModel_3D_Array::f() {
        this->rotateFace(2);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2][i];
        for (int i = 0; i < 3; i++) cube[0][2][i] = cube[1][2 - i][2];
        for (int i = 0; i < 3; i++) cube[1][2 - i][2] = cube[5][0][2 - i];
        for (int i = 0; i < 3; i++) cube[5][0][2 - i] = cube[3][i][0];
        for (int i = 0; i < 3; i++) cube[3][i][0] = temp_arr[i];

        return *this;
    }

    Generic_Rubiks_Cube & CubeModel_3D_Array::fPrime() {
        this->f();
        this->f();
        this->f();

        return *this;
    }

    Generic_Rubiks_Cube & CubeModel_3D_Array::f2() {
        this->f();
        this->f();

        return *this;
    }

    Generic_Rubiks_Cube & CubeModel_3D_Array::r() {
        this->rotateFace(3);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2 - i][2];
        for (int i = 0; i < 3; i++) cube[0][2 - i][2] = cube[2][2 - i][2];
        for (int i = 0; i < 3; i++) cube[2][2 - i][2] = cube[5][2 - i][2];
        for (int i = 0; i < 3; i++) cube[5][2 - i][2] = cube[4][i][0];
        for (int i = 0; i < 3; i++) cube[4][i][0] = temp_arr[i];

        return *this;
    }

    Generic_Rubiks_Cube & CubeModel_3D_Array::rPrime() {
        this->r();
        this->r();
        this->r();

        return *this;
    }

    Generic_Rubiks_Cube & CubeModel_3D_Array::r2() {
        this->r();
        this->r();

        return *this;
    }

    Generic_Rubiks_Cube & CubeModel_3D_Array::b() {
        this->rotateFace(4);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][0][2 - i];
        for (int i = 0; i < 3; i++) cube[0][0][2 - i] = cube[3][2 - i][2];
        for (int i = 0; i < 3; i++) cube[3][2 - i][2] = cube[5][2][i];
        for (int i = 0; i < 3; i++) cube[5][2][i] = cube[1][i][0];
        for (int i = 0; i < 3; i++) cube[1][i][0] = temp_arr[i];

        return *this;
    }

    Generic_Rubiks_Cube & CubeModel_3D_Array::bPrime() {
        this->b();
        this->b();
        this->b();

        return *this;
    }

    Generic_Rubiks_Cube & CubeModel_3D_Array::b2() {
        this->b();
        this->b();

        return *this;
    }

    Generic_Rubiks_Cube & CubeModel_3D_Array::d() {
        this->rotateFace(5);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[2][2][i];
        for (int i = 0; i < 3; i++) cube[2][2][i] = cube[1][2][i];
        for (int i = 0; i < 3; i++) cube[1][2][i] = cube[4][2][i];
        for (int i = 0; i < 3; i++) cube[4][2][i] = cube[3][2][i];
        for (int i = 0; i < 3; i++) cube[3][2][i] = temp_arr[i];

        return *this;
    }

    Generic_Rubiks_Cube & CubeModel_3D_Array::dPrime() {
        this->d();
        this->d();
        this->d();

        return *this;
    }

    Generic_Rubiks_Cube & CubeModel_3D_Array::d2() {
        this->d();
        this->d();

        return *this;
    }

    bool CubeModel_3D_Array::operator==(const CubeModel_3D_Array &r1) const {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (r1.cube[i][j][k] != cube[i][j][k]) return false;
                }
            }
        }
        return true;
    }

    CubeModel_3D_Array &CubeModel_3D_Array::operator=(const CubeModel_3D_Array &r1) {
        if (this ==&r1) return *this;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[i][j][k] = r1.cube[i][j][k];
                }
            }
        }
        return *this;
    }

