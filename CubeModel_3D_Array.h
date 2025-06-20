//
// Created by akshi on 18-06-2025.                          3 - Completed - 1
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
    // override is used during declaration.

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

    // The reason to form the rest of the function is to ensure that = operator doesn't make a shallow copy and overloading it ensures that our data is properly maintained, and we can't rely on the hash function ability to always form a unique key that's why we need the == operator being overloaded to ensure that it correctly checks whether the two keys are identical or not.

    bool operator==(const CubeModel_3D_Array &r1) const;

    CubeModel_3D_Array &operator=(const CubeModel_3D_Array &r1);

};

    // We can't use normal mapping to ensure the visited nodes when we implement the DFS solver and the rest, as the generation of unique keys are not defined for the user-defined data types, so we need to implement that as well what we call normally as the hash function, and it's defined in a struct or class and by overriding the () operator.

struct Hash_3D {
    size_t operator()(const CubeModel_3D_Array &r1) const {
        string str = "";
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    str += r1.cube[i][j][k];
                }
            }
        }
        return hash<string>()(str);                         // string has it's way predefined for implementing its unique keys, and we are accessing that functionality through the function and defining our own hash unique key through it.
    }

};


#endif //CUBEMODEL_3D_ARRAY_H
