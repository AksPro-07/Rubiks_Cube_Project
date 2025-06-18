//
// Created by akshi on 18-06-2025.
//



#ifndef CUBEMODEL_3D_ARRAY_H
#define CUBEMODEL_3D_ARRAY_H

#include "Generic_Rubiks_Cube.h"

class CubeModel_3D_Array : public Generic_Rubiks_Cube {

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

    // Declaring is must for the parent class functions so that we can use it and make their implementation in the .cpp and that's how we can separate the header and cpp files.

    [[nodiscard]] COLOR getColor(FACE face, unsigned row, unsigned column) const override;

    [[nodiscard]] bool isSolved() const;

    Generic_Rubiks_Cube &f();

    Generic_Rubiks_Cube &fPrime();

    Generic_Rubiks_Cube &f2();

    Generic_Rubiks_Cube &b();

    Generic_Rubiks_Cube &bPrime();

    Generic_Rubiks_Cube &b2();

    Generic_Rubiks_Cube &u();

    Generic_Rubiks_Cube &uPrime();

    Generic_Rubiks_Cube &u2();

    Generic_Rubiks_Cube &d();

    Generic_Rubiks_Cube &dPrime();

    Generic_Rubiks_Cube &d2();

    Generic_Rubiks_Cube &l();

    Generic_Rubiks_Cube &lPrime();

    Generic_Rubiks_Cube &l2();

    Generic_Rubiks_Cube &r();

    Generic_Rubiks_Cube &rPrime();

    Generic_Rubiks_Cube &r2();

    // Pending ...

};


#endif //CUBEMODEL_3D_ARRAY_H
