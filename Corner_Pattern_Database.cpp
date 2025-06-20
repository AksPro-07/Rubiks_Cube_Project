//
// Created by akshi on 20-06-2025.                          17 - Completed - 16
//

#include "Corner_Pattern_Database.h"

Corner_Pattern_Database::Corner_Pattern_Database() : Pattern_Database((99000909)){
}

Corner_Pattern_Database::Corner_Pattern_Database(const uint8_t initial_value) : Pattern_Database(99000909,initial_value){}

uint32_t Corner_Pattern_Database::getDatabaseIndex(const Generic_Rubiks_Cube &cube) const {
    array<uint8_t, 8> corner_permutation = {
        cube.getCornerIndex(0),
        cube.getCornerIndex(1),
        cube.getCornerIndex(2),
        cube.getCornerIndex(3),
        cube.getCornerIndex(4),
        cube.getCornerIndex(5),
        cube.getCornerIndex(6),
        cube.getCornerIndex(7),
    };

    uint32_t rank = this->perm_indexer.rank(corner_permutation);

    array<uint8_t, 7> corner_orientations = {
        cube.getCornerOrientation(0),
        cube.getCornerOrientation(1),
        cube.getCornerOrientation(2),
        cube.getCornerOrientation(3),
        cube.getCornerOrientation(4),
        cube.getCornerOrientation(5),
        cube.getCornerOrientation(6),
};

    const uint32_t orientation_number =
            corner_orientations[0] * 729 +
            corner_orientations[1] * 243 +
            corner_orientations[2] * 81 +
            corner_orientations[3] * 27 +
            corner_orientations[4] * 9 +
            corner_orientations[5] * 3 +
            corner_orientations[6];

    return (rank * 2187) + orientation_number;
}
