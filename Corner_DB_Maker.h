//
// Created by akshi on 20-06-2025.                          18 - Completed - 17
//

#ifndef CORNER_DB_MAKER_H
#define CORNER_DB_MAKER_H




#include "Corner_Pattern_Database.h"
#include "CubeModel_Bitboard.h"

using namespace std;

class Corner_DB_Maker {
private:
    string fileName;
    Corner_Pattern_Database cornerDB;

public:

    Corner_DB_Maker(const string &_fileName);
    Corner_DB_Maker(const string &_fileName, uint8_t init_val);

    bool bfsAndStore();


};


#endif //CORNER_DB_MAKER_H
