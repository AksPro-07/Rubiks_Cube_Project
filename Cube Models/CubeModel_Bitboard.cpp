//
// Created by akshi on 21-06-2025.                          23 - Completed - 23
//

#include "CubeModel_Bitboard.h"

CubeModel_Bitboard::COLOR CubeModel_Bitboard::getColor(FACE face, unsigned row, unsigned col) const {
        int idx = arr[row][col];
        if (idx == 8) return static_cast<COLOR>(static_cast<int>(face));

        uint64_t side = bitboard[static_cast<int>(face)];
        uint64_t color = (side >> (8 * idx)) & one_8;

        int bit_pos = 0;
        while (color != 0) {
            color = color >> 1;
            bit_pos++;
        }
        return static_cast<COLOR>(bit_pos - 1);
    }

    bool CubeModel_Bitboard::isSolved() const {
        for (int i = 0; i < 6; i++) {
            if (solved_side_config[i] != bitboard[i]) return false;
        }
        return true;
    }

    Generic_Rubiks_Cube &CubeModel_Bitboard::u() {
        this->rotateFace(0);
        uint64_t temp = bitboard[2] & one_24;
        bitboard[2] = (bitboard[2] & ~one_24) | (bitboard[3] & one_24);
        bitboard[3] = (bitboard[3] & ~one_24) | (bitboard[4] & one_24);
        bitboard[4] = (bitboard[4] & ~one_24) | (bitboard[1] & one_24);
        bitboard[1] = (bitboard[1] & ~one_24) | temp;

        return *this;
    }

    Generic_Rubiks_Cube &CubeModel_Bitboard::uPrime() {
        this->u();
        this->u();
        this->u();

        return *this;
    };

    Generic_Rubiks_Cube &CubeModel_Bitboard::u2() {
        this->u();
        this->u();

        return *this;
    };

    Generic_Rubiks_Cube &CubeModel_Bitboard::l() {
        this->rotateFace(1);
        uint64_t clr1 = (bitboard[2] & (one_8 << (8 * 0))) >> (8 * 0);
        uint64_t clr2 = (bitboard[2] & (one_8 << (8 * 6))) >> (8 * 6);
        uint64_t clr3 = (bitboard[2] & (one_8 << (8 * 7))) >> (8 * 7);

        this->rotateSide(2, 0, 7, 6, 0, 0, 7, 6);
        this->rotateSide(0, 0, 7, 6, 4, 4, 3, 2);
        this->rotateSide(4, 4, 3, 2, 5, 0, 7, 6);

        bitboard[5] = (bitboard[5] & ~(one_8 << (8 * 0))) | (clr1 << (8 * 0));
        bitboard[5] = (bitboard[5] & ~(one_8 << (8 * 6))) | (clr2 << (8 * 6));
        bitboard[5] = (bitboard[5] & ~(one_8 << (8 * 7))) | (clr3 << (8 * 7));

        return *this;

    };

    Generic_Rubiks_Cube &CubeModel_Bitboard::lPrime() {
        this->l();
        this->l();
        this->l();

        return *this;
    };

    Generic_Rubiks_Cube &CubeModel_Bitboard::l2() {
        this->l();
        this->l();

        return *this;
    };

    Generic_Rubiks_Cube &CubeModel_Bitboard::f() {
        this->rotateFace(2);

        uint64_t clr1 = (bitboard[0] & (one_8 << (8 * 4))) >> (8 * 4);
        uint64_t clr2 = (bitboard[0] & (one_8 << (8 * 5))) >> (8 * 5);
        uint64_t clr3 = (bitboard[0] & (one_8 << (8 * 6))) >> (8 * 6);

        this->rotateSide(0, 4, 5, 6, 1, 2, 3, 4);
        this->rotateSide(1, 2, 3, 4, 5, 0, 1, 2);
        this->rotateSide(5, 0, 1, 2, 3, 6, 7, 0);

        bitboard[3] = (bitboard[3] & ~(one_8 << (8 * 6))) | (clr1 << (8 * 6));
        bitboard[3] = (bitboard[3] & ~(one_8 << (8 * 7))) | (clr2 << (8 * 7));
        bitboard[3] = (bitboard[3] & ~(one_8 << (8 * 0))) | (clr3 << (8 * 0));

        return *this;
    };

    Generic_Rubiks_Cube &CubeModel_Bitboard::fPrime() {
        this->f();
        this->f();
        this->f();
        return *this;
    };

    Generic_Rubiks_Cube &CubeModel_Bitboard::f2() {
        this->f();
        this->f();

        return *this;
    };

    Generic_Rubiks_Cube &CubeModel_Bitboard::r() {
        this->rotateFace(3);
        uint64_t clr1 = (bitboard[0] & (one_8 << (8 * 2))) >> (8 * 2);
        uint64_t clr2 = (bitboard[0] & (one_8 << (8 * 3))) >> (8 * 3);
        uint64_t clr3 = (bitboard[0] & (one_8 << (8 * 4))) >> (8 * 4);

        this->rotateSide(0, 2, 3, 4, 2, 2, 3, 4);
        this->rotateSide(2, 2, 3, 4, 5, 2, 3, 4);
        this->rotateSide(5, 2, 3, 4, 4, 7, 6, 0);

        bitboard[4] = (bitboard[4] & ~(one_8 << (8 * 7))) | (clr1 << (8 * 7));
        bitboard[4] = (bitboard[4] & ~(one_8 << (8 * 6))) | (clr2 << (8 * 6));
        bitboard[4] = (bitboard[4] & ~(one_8 << (8 * 0))) | (clr3 << (8 * 0));

        return *this;
    };

    Generic_Rubiks_Cube &CubeModel_Bitboard::rPrime() {
        this->r();
        this->r();
        this->r();

        return *this;
    };

    Generic_Rubiks_Cube &CubeModel_Bitboard::r2() {
        this->r();
        this->r();

        return *this;
    };

    Generic_Rubiks_Cube &CubeModel_Bitboard::b() {
        this->rotateFace(4);

        uint64_t clr1 = (bitboard[0] & (one_8 << (8 * 0))) >> (8 * 0);
        uint64_t clr2 = (bitboard[0] & (one_8 << (8 * 1))) >> (8 * 1);
        uint64_t clr3 = (bitboard[0] & (one_8 << (8 * 2))) >> (8 * 2);

        this->rotateSide(0, 0, 1, 2, 3, 2, 3, 4);
        this->rotateSide(3, 2, 3, 4, 5, 4, 5, 6);
        this->rotateSide(5, 4, 5, 6, 1, 6, 7, 0);

        bitboard[1] = (bitboard[1] & ~(one_8 << (8 * 6))) | (clr1 << (8 * 6));
        bitboard[1] = (bitboard[1] & ~(one_8 << (8 * 7))) | (clr2 << (8 * 7));
        bitboard[1] = (bitboard[1] & ~(one_8 << (8 * 0))) | (clr3 << (8 * 0));

        return *this;
    };

    Generic_Rubiks_Cube &CubeModel_Bitboard::bPrime() {
        this->b();
        this->b();
        this->b();

        return *this;
    };

    Generic_Rubiks_Cube &CubeModel_Bitboard::b2() {
        this->b();
        this->b();

        return *this;
    };

    Generic_Rubiks_Cube &CubeModel_Bitboard::d() {
        this->rotateFace(5);

        uint64_t clr1 = (bitboard[2] & (one_8 << (8 * 4))) >> (8 * 4);
        uint64_t clr2 = (bitboard[2] & (one_8 << (8 * 5))) >> (8 * 5);
        uint64_t clr3 = (bitboard[2] & (one_8 << (8 * 6))) >> (8 * 6);

        this->rotateSide(2, 4, 5, 6, 1, 4, 5, 6);
        this->rotateSide(1, 4, 5, 6, 4, 4, 5, 6);
        this->rotateSide(4, 4, 5, 6, 3, 4, 5, 6);

        bitboard[3] = (bitboard[3] & ~(one_8 << (8 * 4))) | (clr1 << (8 * 4));
        bitboard[3] = (bitboard[3] & ~(one_8 << (8 * 5))) | (clr2 << (8 * 5));
        bitboard[3] = (bitboard[3] & ~(one_8 << (8 * 6))) | (clr3 << (8 * 6));

        return *this;
    };

    Generic_Rubiks_Cube &CubeModel_Bitboard::dPrime() {
        this->d();
        this->d();
        this->d();

        return *this;
    };

    Generic_Rubiks_Cube &CubeModel_Bitboard::d2() {
        this->d();
        this->d();

        return *this;
    }

    bool CubeModel_Bitboard::operator==(const CubeModel_Bitboard &r1) const {
        for (int i = 0; i < 6; i++) {
            if (bitboard[i] != r1.bitboard[i]) return false;
        }
        return true;
    }

    CubeModel_Bitboard &CubeModel_Bitboard::operator=(const CubeModel_Bitboard &r1) {
        for (int i = 0; i < 6; i++) {
            bitboard[i] = r1.bitboard[i];
        }
        return *this;
    }


    uint64_t CubeModel_Bitboard::getCorners() const {
        uint64_t ret = 0;
        string top_front_right = "";
        top_front_right += getColorLetter(getColor(FACE::UP, 2, 2));
        top_front_right += getColorLetter(getColor(FACE::FRONT, 0, 2));
        top_front_right += getColorLetter(getColor(FACE::RIGHT, 0, 0));

        string top_front_left = "";
        top_front_left += getColorLetter(getColor(FACE::UP, 2, 0));
        top_front_left += getColorLetter(getColor(FACE::FRONT, 0, 0));
        top_front_left += getColorLetter(getColor(FACE::LEFT, 0, 2));

        string top_back_left = "";
        top_back_left += getColorLetter(getColor(FACE::UP, 0, 0));
        top_back_left += getColorLetter(getColor(FACE::BACK, 0, 2));
        top_back_left += getColorLetter(getColor(FACE::LEFT, 0, 0));

        string top_back_right = "";
        top_back_right += getColorLetter(getColor(FACE::UP, 0, 2));
        top_back_right += getColorLetter(getColor(FACE::BACK, 0, 0));
        top_back_right += getColorLetter(getColor(FACE::RIGHT, 0, 2));

        string bottom_front_right = "";
        bottom_front_right += getColorLetter(getColor(FACE::DOWN, 0, 2));
        bottom_front_right += getColorLetter(getColor(FACE::FRONT, 2, 2));
        bottom_front_right += getColorLetter(getColor(FACE::RIGHT, 2, 0));

        string bottom_front_left = "";
        bottom_front_left += getColorLetter(getColor(FACE::DOWN, 0, 0));
        bottom_front_left += getColorLetter(getColor(FACE::FRONT, 2, 0));
        bottom_front_left += getColorLetter(getColor(FACE::LEFT, 2, 2));

        string bottom_back_right = "";
        bottom_back_right += getColorLetter(getColor(FACE::DOWN, 2, 2));
        bottom_back_right += getColorLetter(getColor(FACE::BACK, 2, 0));
        bottom_back_right += getColorLetter(getColor(FACE::RIGHT, 2, 2));

        string bottom_back_left = "";
        bottom_back_left += getColorLetter(getColor(FACE::DOWN, 2, 0));
        bottom_back_left += getColorLetter(getColor(FACE::BACK, 2, 2));
        bottom_back_left += getColorLetter(getColor(FACE::LEFT, 2, 0));

        ret |= get5bitCorner(top_front_right);
        ret = ret << 5;

        ret |= get5bitCorner(top_front_left);
        ret = ret << 5;

        ret |= get5bitCorner(top_back_right);
        ret = ret << 5;

        ret |= get5bitCorner(top_back_left);
        ret = ret << 5;

        ret |= get5bitCorner(bottom_front_right);
        ret = ret << 5;

        ret |= get5bitCorner(bottom_front_left);
        ret = ret << 5;

        ret |= get5bitCorner(bottom_back_right);
        ret = ret << 5;

        ret |= get5bitCorner(bottom_back_left);
        ret = ret << 5;

//        Following was used for Testing / Printing

//        cout << top_front_right << " "; print5bitbin(get5bitCorner(top_front_right )); cout  << "\n";
//        cout << top_front_left << " "; print5bitbin(get5bitCorner(top_front_left )); cout << "\n";
//        cout << top_back_right << " "; print5bitbin(get5bitCorner(top_back_right )); cout << "\n";
//        cout << top_back_left  << " "; print5bitbin(get5bitCorner(top_back_left  )); cout << "\n";
//        cout << bottom_front_right  << " "; print5bitbin(get5bitCorner(bottom_front_right  )); cout << "\n";
//        cout << bottom_front_left << " "; print5bitbin(get5bitCorner(bottom_front_left )); cout << "\n";
//        cout << bottom_back_right << " "; print5bitbin(get5bitCorner(bottom_back_right )); cout << "\n";
//        cout << bottom_back_left << " "; print5bitbin(get5bitCorner(bottom_back_left )); cout << "\n";

        return ret;
    }
