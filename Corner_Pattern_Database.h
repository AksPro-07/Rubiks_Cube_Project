//
// Created by akshi on 20-06-2025.                          16 - Completed - 15
//

#ifndef CORNER_PATTERN_DATABASE_H
#define CORNER_PATTERN_DATABASE_H

#include "Generic_Rubiks_Cube.h"
#include "Pattern_Database.h"
#include "Permutation_Indexer.h"

class Corner_Pattern_Database : public Pattern_Database {

private:

    typedef Generic_Rubiks_Cube::FACE F;

    Permutation_Indexer<8> perm_indexer;

public:

    Corner_Pattern_Database();
    Corner_Pattern_Database(uint8_t initial_value);
    [[nodiscard]] uint32_t getDatabaseIndex(const Generic_Rubiks_Cube &cube) const override;

};



#endif //CORNER_PATTERN_DATABASE_H
