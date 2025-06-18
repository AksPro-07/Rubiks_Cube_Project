//
// Created by akshi on 17-06-2025.                  2
//

#include "Generic_Rubiks_Cube.h"

// It's where we implement all the member functions of the base class that are not going to get derived from the derived classes as they aren't virtual.

char Generic_Rubiks_Cube::getColorLetter(COLOR color) {
    switch (color) {
        case COLOR::RED : return 'R';
        case COLOR::GREEN : return 'G';
        case COLOR::BLUE : return 'B';
        case COLOR::WHITE : return 'W';
        case COLOR::ORANGE : return 'O';
        case COLOR::YELLOW : return 'Y';
        default: return '?';           // Just for safety, so not to get a UB ( Unidentified Behavior )
    }
}


string Generic_Rubiks_Cube::getMove(MOVE mov) {
    switch (mov) {
        case MOVE::L : return "L";
        case MOVE::LPRIME : return  "L'";
        case MOVE::L2 : return  "L2";
        case MOVE::R : return "R";
        case MOVE::RPRIME : return  "R'";
        case MOVE::R2 : return  "R2";
        case MOVE::U : return "U";
        case MOVE::UPRIME : return  "U'";
        case MOVE::U2 : return  "U2";
        case MOVE::D : return "D";
        case MOVE::DPRIME : return  "D'";
        case MOVE::D2 : return  "D2";
        case MOVE::F : return "F";
        case MOVE::FPRIME : return  "F'";
        case MOVE::F2 : return  "F2";
        case MOVE::B : return "B";
        case MOVE::BPRIME : return  "B'";
        case MOVE::B2 : return  "B2";
        default: return "?";
    }
}


Generic_Rubiks_Cube& Generic_Rubiks_Cube::move(MOVE mov) {
    switch (mov) {
        case MOVE::L : return this->l();
        case MOVE::LPRIME : return this->lPrime();
        case MOVE::L2 : return this->l2();
        case MOVE::R : return this->r();
        case MOVE::RPRIME : return this->rPrime();
        case MOVE::R2 : return this->r2();
        case MOVE::U : return this->u();
        case MOVE::UPRIME : return this->uPrime();
        case MOVE::U2 : return this->u2();
        case MOVE::D : return this->d();
        case MOVE::DPRIME : return this->dPrime();
        case MOVE::D2 : return this->d2();
        case MOVE::F : return this->l();
        case MOVE::FPRIME : return this->lPrime();
        case MOVE::F2 : return this->l2();
        case MOVE::B : return this->b();
        case MOVE::BPRIME : return this->bPrime();
        case MOVE::B2 : return this->b2();
    }
    throw std::runtime_error("Invalid move in cube.");
}


Generic_Rubiks_Cube& Generic_Rubiks_Cube::invert(MOVE mov) {
    switch (mov) {
        case MOVE::L : return this->lPrime();
        case MOVE::LPRIME : return this->l();
        case MOVE::L2 : return this->l2();
        case MOVE::R : return this->rPrime();
        case MOVE::RPRIME : return this->r();
        case MOVE::R2 : return this->r2();
        case MOVE::U : return this->uPrime();
        case MOVE::UPRIME : return this->u();
        case MOVE::U2 : return this->u2();
        case MOVE::D : return this->dPrime();
        case MOVE::DPRIME : return this->d();
        case MOVE::D2 : return this->d2();
        case MOVE::F : return this->lPrime();
        case MOVE::FPRIME : return this->l();
        case MOVE::F2 : return this->l2();
        case MOVE::B : return this->bPrime();
        case MOVE::BPRIME : return this->b();
        case MOVE::B2 : return this->b2();
    }
    throw std::runtime_error("Invalid invert move in cube.");
}

// I am printing it in the planar representation format.

void Generic_Rubiks_Cube::print() const{

    cout << "Generic Rubik's Cube:\n\n";

    for (unsigned row = 0; row < 3; row++) {
        for (unsigned i = 0; i < 7; i++) cout<<" ";
        for (unsigned col = 0; col < 3; col++) {
            cout<<getColorLetter(getColor(FACE::UP, row, col))<<' ';
        }
        cout<<"\n";
    }

    cout<<"\n";

    for (unsigned row = 0; row < 3; row++) {

        for (unsigned col = 0; col < 3; col++) {
            cout<<getColorLetter(getColor(FACE::LEFT, row, col))<<' ';
        }
        cout<<"  ";

        for (unsigned col = 0; col < 3; col++) {
            cout<<getColorLetter(getColor(FACE::FRONT, row, col))<<' ';
        }
        cout<<"  ";

        for (unsigned col = 0; col < 3; col++) {
            cout<<getColorLetter(getColor(FACE::RIGHT, row, col))<<' ';
        }
        cout<<"  ";

        for (unsigned col = 0; col < 3; col++) {
            cout<<getColorLetter(getColor(FACE::BACK, row, col))<<' ';
        }

        cout<<"\n";

    }

    cout<<"\n";

    for (unsigned row = 0; row < 3; row++) {
        for (unsigned i = 0; i < 7; i++) cout<<" ";
        for (unsigned col = 0; col < 3; col++) {
            cout<<getColorLetter(getColor(FACE::DOWN, row, col))<<' ';
        }
        cout<<"\n";
    }

    cout<<"\n";
}

// Each enum value corresponds internally to an int:     MOVE::U = 0   MOVE::Ui =  …   MOVE::B2 = 17
// static_cast<MOVE>(select_move) - This is saying:  "Take this int value (select_move), and cast it into the MOVE enum."
//  select_move = 5;
//  static_cast<MOVE>(select_move);  // → MOVE::D2

vector<Generic_Rubiks_Cube::MOVE> Generic_Rubiks_Cube::randomShuffle(unsigned times) {
    vector<MOVE> moves_performed;
    srand(time(nullptr));                                   // Modern C++ (clear intent)
    for (unsigned i = 0; i < times; i++) {
        unsigned select_move = rand() % 18;
        moves_performed.push_back(static_cast<MOVE>(select_move));
        this->move(static_cast<MOVE>(select_move));
    }
    return moves_performed;
}

// Pending ...
