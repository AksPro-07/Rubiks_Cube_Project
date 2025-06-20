//
// Created by akshi on 17-06-2025.                          2 - Completed - 11
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
        case MOVE::F : return this->f();
        case MOVE::FPRIME : return this->fPrime();
        case MOVE::F2 : return this->f2();
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
        case MOVE::F : return this->fPrime();
        case MOVE::FPRIME : return this->f();
        case MOVE::F2 : return this->f2();
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
        for (unsigned i = 0; i < 8; i++) cout<<" ";
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
        for (unsigned i = 0; i < 8; i++) cout<<" ";
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


//Helper function that returns string of corner used to determine the orientation and index of a particular piece.

string Generic_Rubiks_Cube::getCornerColorString(uint8_t index) const {
    string corner_color;

    switch (index) {
//           UFR
        case 0:
            corner_color += getColorLetter(getColor(FACE::UP, 2, 2));
            corner_color += getColorLetter(getColor(FACE::FRONT, 0, 2));
            corner_color += getColorLetter(getColor(FACE::RIGHT, 0, 0));
            break;

//            UFL
        case 1:
            corner_color += getColorLetter(getColor(FACE::UP, 2, 0));
            corner_color += getColorLetter(getColor(FACE::FRONT, 0, 0));
            corner_color += getColorLetter(getColor(FACE::LEFT, 0, 2));
            break;

//            UBL
        case 2:
            corner_color += getColorLetter(getColor(FACE::UP, 0, 0));
            corner_color += getColorLetter(getColor(FACE::BACK, 0, 2));
            corner_color += getColorLetter(getColor(FACE::LEFT, 0, 0));
            break;

//            UBR
        case 3:
            corner_color += getColorLetter(getColor(FACE::UP, 0, 2));
            corner_color += getColorLetter(getColor(FACE::BACK, 0, 0));
            corner_color += getColorLetter(getColor(FACE::RIGHT, 0, 2));
            break;

//            DFR
        case 4:
            corner_color += getColorLetter(getColor(FACE::DOWN, 0, 2));
            corner_color += getColorLetter(getColor(FACE::FRONT, 2, 2));
            corner_color += getColorLetter(getColor(FACE::RIGHT, 2, 0));
            break;

//            DFL
        case 5:
            corner_color += getColorLetter(getColor(FACE::DOWN, 0, 0));
            corner_color += getColorLetter(getColor(FACE::FRONT, 2, 0));
            corner_color += getColorLetter(getColor(FACE::LEFT, 2, 2));
            break;

//            DBR
        case 6:
            corner_color += getColorLetter(getColor(FACE::DOWN, 2, 2));
            corner_color += getColorLetter(getColor(FACE::BACK, 2, 0));
            corner_color += getColorLetter(getColor(FACE::RIGHT, 2, 2));
            break;

//            DBL
        case 7:
            corner_color += getColorLetter(getColor(FACE::DOWN, 2, 0));
            corner_color += getColorLetter(getColor(FACE::BACK, 2, 2));
            corner_color += getColorLetter(getColor(FACE::LEFT, 2, 0));
            break;
    }
    return corner_color;
}

uint8_t Generic_Rubiks_Cube::getCornerIndex(const uint8_t index) const {
    string corner = getCornerColorString(index);

    uint8_t ret = 0;
    for (auto c: corner) {
        if (c != 'W' && c != 'Y') continue;
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
    return ret;
}

uint8_t Generic_Rubiks_Cube::getCornerOrientation(const uint8_t index) const {
    string corner = getCornerColorString(index);

    string actual_str = "";

    for (auto c: corner) {
        if (c != 'W' && c != 'Y') continue;
        actual_str.push_back(c);
    }

    if (corner[1] == actual_str[0]) {
        return 1;
    } else if (corner[2] == actual_str[0]) {
        return 2;
    } else return 0;
}

// uint8_t Generic_Rubiks_Cube::getCornerIndex(const uint8_t index) const {
//
//     string corner_color = getCornerColorString(index);
//     uint8_t value = 0;
//
//     for (auto c: corner_color) {
//
//         if (c == 'Y') value |= (1 << 2);
//
//         if (c == 'O') value |= (1 << 1);
//
//         if (c == 'G') value |= (1 << 0);
//
//     }
//
//     if (value > 7) throw std::runtime_error("Invalid invert corner in cube. Input corner string: " + corner_color);
//
//     return value;
//
// }
//
//
// uint8_t Generic_Rubiks_Cube::getCornerOrientation(const uint8_t index) const {
//     string corner_color = getCornerColorString(index);
//
//     for (unsigned i = 0; i < 3; i++) {
//         if (corner_color[i] == 'Y' || corner_color[i] == 'W' ) return (i);
//     }
//     throw std::runtime_error("Invalid invert corner in cube. Input corner string: " + corner_color);
//
// }