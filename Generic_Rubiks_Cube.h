//
// Created by akshi on 17-06-2025.                          1 - Completed - 10
//

/*
    Task 1: Generic Rubik’s Cube:
    Write an abstract class of a Generic Rubik’s Cube that has the following operations as virtual functions:
    1. All the 18 different rotations of the cube: F, Fprime, F2, U, Uprime, etc.
    2. Print function: A function that takes the Rubik’s Cube and prints it in the Planar Representation Format.
    3. Random Shuffle: A function that returns a randomly shuffled Rubik’s Cube which is solvable.
    4. isSolved(): a boolean function that tells whether the current configuration of the Rubik’s Cube is solved or not.
*/

#ifndef GENERIC_RUBIKS_CUBE_H
#define GENERIC_RUBIKS_CUBE_H

// It's the file to start with, because we first declare the main base class.

#include <bits/stdc++.h>            // A bit different from the code but for now, I am going with it.
using namespace std;

class Generic_Rubiks_Cube {
public:

    // Define a Rubik's Cube i.e., What make it that ?
    // enum is used to declare an option set, kind of like a datatype, means it can only return any of the value that is present in it.

    enum class FACE {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };

    enum class COLOR {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };

    // Define the operation i.e., Now that you have defined the basic characteristic of that entity, What can you do with it ?

    enum class MOVE {
        F, FPRIME, F2,
        B, BPRIME, B2,
        R, RPRIME, R2,
        L, LPRIME, L2,
        U, UPRIME, U2,
        D, DPRIME, D2
    };

    // Now, if you are going to print it, you will need to know the color at each cell i.e., of those 6x3x3 ( Face x Row x Column )
    // const as it is a getter, it a good practice, since getter doesn't change anything of that class object, using const make it clear to the compiler.
    /*
     What does [[nodiscard]] mean?
     It tells the compiler:
     "If someone calls this function and ignores its return value, warn them."
    This is helpful when the return value matters, like in:
     Getters (like getColor(...))
     Functions returning error codes or states
     Anything where ignoring the result is likely a bug

    Use [[nodiscard]] when:
     The return value is meaningful and should not be ignored
     Especially on getter functions
     You want to catch careless mistakes early

     If you're using C++17 or later, [[nodiscard]] is fully supported.
     For C++11/14, this attribute may not compile unless your compiler adds it as an extension.
     */

    [[nodiscard]] virtual COLOR getColor(FACE face, unsigned row, unsigned column) const = 0;

    // When you print, you are not going to print the entire color just the letter of it.
    // static means that the function belongs to the class, not to any particular object (instance) of that class.
    /*
        It doesn't rely on any particular cube object.
        Functions like this are just "helpers" or "converters".
        Making them static makes it clear they don’t depend on the object’s state.
     */
    /*
    You cannot write static string getMove(MOVE ind) const = 0; because:
    static functions don’t belong to an object, so they can’t be const or virtual.
    You use static when the function is a utility that doesn't depend on instance data.
    Use virtual ... const = 0 only for functions that vary by object and need to be overridden.
     */
    //You make getColorLetter static because it just converts a COLOR to a char, and doesn't need any object-specific data. It makes your code cleaner, and avoids unnecessary object creation.

    static char getColorLetter(COLOR color);

    // Now, to check if the cube is solved.

    [[nodiscard]] virtual bool isSolved() const = 0;

    // Now, you need to return the move when you do as well, and we will have to know all.

    static string getMove(MOVE mov);

    // Printing of cube.
    // We didn't declare the print function virtual because we want to make printing done by itself and not the derived classes that was also the reason why we choose to create the helper function getColor, so that the derived classes can give the color of the Face x Row x Column that we desire, and we can solely do the printing through the base class and not need to complicate our thinking to bother about the printing for each model that we will create.

    void print() const;

    // Now, to implement the random shuffle that Randomly shuffle the cube with 'times' moves and returns the moves performed.

    vector<MOVE> randomShuffle(unsigned times);

    // Now, making the moves on the cube.
    // These are not made virtual as we want the models that we are going to make to implement how they are doing a certain move but not to make the move themselves as it will be done by the solvers and solver don't bother about how they are making a move, they will just only be concern about what moves to make to solve the cube.

    Generic_Rubiks_Cube &move(MOVE mov);

    Generic_Rubiks_Cube &invert(MOVE mov);

    virtual Generic_Rubiks_Cube &f() = 0;

    virtual Generic_Rubiks_Cube &fPrime() = 0;

    virtual Generic_Rubiks_Cube &f2() = 0;

    virtual Generic_Rubiks_Cube &b() = 0;

    virtual Generic_Rubiks_Cube &bPrime() = 0;

    virtual Generic_Rubiks_Cube &b2() = 0;

    virtual Generic_Rubiks_Cube &u() = 0;

    virtual Generic_Rubiks_Cube &uPrime() = 0;

    virtual Generic_Rubiks_Cube &u2() = 0;

    virtual Generic_Rubiks_Cube &d() = 0;

    virtual Generic_Rubiks_Cube &dPrime() = 0;

    virtual Generic_Rubiks_Cube &d2() = 0;

    virtual Generic_Rubiks_Cube &l() = 0;

    virtual Generic_Rubiks_Cube &lPrime() = 0;

    virtual Generic_Rubiks_Cube &l2() = 0;

    virtual Generic_Rubiks_Cube &r() = 0;

    virtual Generic_Rubiks_Cube &rPrime() = 0;

    virtual Generic_Rubiks_Cube &r2() = 0;

    // The next 3 functions are used for the implementation of the Corner Pattern Database, you will know about them and there work when you reach that part.
    // I have reached it, so these functions are implemented and the first one of them is a helper function.

    [[nodiscard]] string getCornerColorString(uint8_t index) const;

    [[nodiscard]] uint8_t getCornerIndex(uint8_t index) const;

    [[nodiscard]] uint8_t getCornerOrientation(uint8_t index) const;

virtual ~Generic_Rubiks_Cube() = default;

};



#endif //GENERIC_RUBIKS_CUBE_H
