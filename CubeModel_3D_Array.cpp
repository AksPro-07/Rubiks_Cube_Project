//
// Created by akshi on 18-06-2025.                    3
//

#include "Generic_Rubiks_Cube.h"

class CubeModel_3D_Array : Generic_Rubiks_Cube {
    private:

    // To make it ease in implementing the rotating function as they all do similar things with respect to their faces ( Understanding is clear, and it's written in notebook )

    void rotateFace(int face_number) {
        char temp_face[3][3]={};
        for (unsigned i = 0; i < 3; i++) {
            for (unsigned j = 0; j < 3; j++) {
                temp_face[i][j] = cube[face_number][i][j];
            }
        }
        for (unsigned i = 0; i < 3; i++) cube[face_number][0][i] = temp_face[2-i][0];
        for (unsigned i = 0; i < 3; i++) cube[face_number][i][2] = temp_face[0][i];
        for (unsigned i = 0; i < 3; i++) cube[face_number][2][2-i] = temp_face[i][2];
        for (unsigned i = 0; i < 3; i++) cube[face_number][2-i][0] = temp_face[2][2-i];
    }

    public:

    // Starting with declaring the cube data storage and initializing its constructor.

    char cube[6][3][3]{};

    /*                             This is currently using as the standard
    • Up → 0 (White)
    • Left → 1 (Green)
    • Front → 2 (Red)
    • Right → 3 (Blue)
    • Back → 4 (Orange)
    • Down → 5 (Yellow)
     */

    CubeModel_3D_Array() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[i][j][k] = getColorLetter(static_cast<COLOR>(i));              //Modern C++ - This is safe, explicit, and checked at compile time.
                }
            }
        }
    }

    // Now, we need to define all the virtual functions for the parent class Generic_Rubiks_Cube.

    [[nodiscard]] COLOR getColor(FACE face, unsigned row, unsigned column) const override {
        char color = cube[static_cast<int>(face)][row][column];
        switch (color) {
            case 'R' : return COLOR::RED;
            case 'G' : return COLOR::GREEN;
            case 'B' : return COLOR::BLUE;
            case 'Y' : return COLOR::YELLOW;
            case 'W' : return COLOR::WHITE;
            case 'O' : return COLOR::ORANGE;
        }
        throw std::runtime_error("Invalid color character in cube.");
    }

    [[nodiscard]] bool isSolved() const override {
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

        Generic_Rubiks_Cube &u() override {
        this->rotateFace(0);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[4][0][2 - i];
        for (int i = 0; i < 3; i++) cube[4][0][2 - i] = cube[1][0][2 - i];
        for (int i = 0; i < 3; i++) cube[1][0][2 - i] = cube[2][0][2 - i];
        for (int i = 0; i < 3; i++) cube[2][0][2 - i] = cube[3][0][2 - i];
        for (int i = 0; i < 3; i++) cube[3][0][2 - i] = temp_arr[i];

        return *this;
    }

    Generic_Rubiks_Cube &uPrime() override {
        this->u();
        this->u();
        this->u();

        return *this;
    }

    Generic_Rubiks_Cube &u2() override {
        this->u();
        this->u();

        return *this;
    }

    Generic_Rubiks_Cube &l() override {
        this->rotateFace(1);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][i][0];
        for (int i = 0; i < 3; i++) cube[0][i][0] = cube[4][2 - i][2];
        for (int i = 0; i < 3; i++) cube[4][2 - i][2] = cube[5][i][0];
        for (int i = 0; i < 3; i++) cube[5][i][0] = cube[2][i][0];
        for (int i = 0; i < 3; i++) cube[2][i][0] = temp_arr[i];

        return *this;
    }

    Generic_Rubiks_Cube &lPrime() override {
        this->l();
        this->l();
        this->l();

        return *this;
    }

    Generic_Rubiks_Cube &l2() override {
        this->l();
        this->l();

        return *this;
    }

    Generic_Rubiks_Cube &f() override {
        this->rotateFace(2);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2][i];
        for (int i = 0; i < 3; i++) cube[0][2][i] = cube[1][2 - i][2];
        for (int i = 0; i < 3; i++) cube[1][2 - i][2] = cube[5][0][2 - i];
        for (int i = 0; i < 3; i++) cube[5][0][2 - i] = cube[3][i][0];
        for (int i = 0; i < 3; i++) cube[3][i][0] = temp_arr[i];

        return *this;
    }

    Generic_Rubiks_Cube &fPrime() override {
        this->f();
        this->f();
        this->f();

        return *this;
    }

    Generic_Rubiks_Cube &f2() override {
        this->f();
        this->f();

        return *this;
    }

    Generic_Rubiks_Cube &r() override {
        this->rotateFace(3);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2 - i][2];
        for (int i = 0; i < 3; i++) cube[0][2 - i][2] = cube[2][2 - i][2];
        for (int i = 0; i < 3; i++) cube[2][2 - i][2] = cube[5][2 - i][2];
        for (int i = 0; i < 3; i++) cube[5][2 - i][2] = cube[4][i][0];
        for (int i = 0; i < 3; i++) cube[4][i][0] = temp_arr[i];

        return *this;
    }

    Generic_Rubiks_Cube &rPrime() override {
        this->r();
        this->r();
        this->r();

        return *this;
    }

    Generic_Rubiks_Cube &r2() override {
        this->r();
        this->r();

        return *this;
    }

    Generic_Rubiks_Cube &b() override {
        this->rotateFace(4);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][0][2 - i];
        for (int i = 0; i < 3; i++) cube[0][0][2 - i] = cube[3][2 - i][2];
        for (int i = 0; i < 3; i++) cube[3][2 - i][2] = cube[5][2][i];
        for (int i = 0; i < 3; i++) cube[5][2][i] = cube[1][i][0];
        for (int i = 0; i < 3; i++) cube[1][i][0] = temp_arr[i];

        return *this;
    }

    Generic_Rubiks_Cube &bPrime() override {
        this->b();
        this->b();
        this->b();

        return *this;
    }

    Generic_Rubiks_Cube &b2() override {
        this->b();
        this->b();

        return *this;
    }

    Generic_Rubiks_Cube &d() override {
        this->rotateFace(5);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[2][2][i];
        for (int i = 0; i < 3; i++) cube[2][2][i] = cube[1][2][i];
        for (int i = 0; i < 3; i++) cube[1][2][i] = cube[4][2][i];
        for (int i = 0; i < 3; i++) cube[4][2][i] = cube[3][2][i];
        for (int i = 0; i < 3; i++) cube[3][2][i] = temp_arr[i];

        return *this;
    }

    Generic_Rubiks_Cube &dPrime() override {
        this->d();
        this->d();
        this->d();

        return *this;
    }

    Generic_Rubiks_Cube &d2() override {
        this->d();
        this->d();

        return *this;
    }

    // Pending ...

};

// Pending ...
