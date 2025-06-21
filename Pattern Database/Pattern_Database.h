//
// Created by akshi on 20-06-2025.                          11 - Completed - 8
//

#ifndef PATTERN_DATABASE_H
#define PATTERN_DATABASE_H

// For now, what I think it is for is mainly for data-handling when dealing with all those patterns that we are going to implement in the future.
// Basically, an interactive interface between those patterns and their data storage.

#include "../Cube Models/Generic_Rubiks_Cube.h"
#include "../Database/Database Constructor/Nibble_Array.h"

class Pattern_Database {

private:

    Nibble_Array database;
    size_t size_;
    size_t num_items;

    //Creating various constructors ( Purpose not too clear )

    Pattern_Database();

public:

    Pattern_Database(size_t size);

    Pattern_Database(size_t size, uint8_t initial_value);

    // Based on a cube configuration to return its heuristic values, it's the function that the different database patterns are going to implement.

    virtual uint32_t getDatabaseIndex(const Generic_Rubiks_Cube & cube) const = 0;

    // Database data setter and getter function.

    virtual bool setNumMoves(uint32_t index, uint8_t num_moves);

    [[nodiscard]] virtual uint8_t getNumMoves(uint32_t index) const;

    virtual bool setNumMoves(Generic_Rubiks_Cube & cube, uint8_t num_moves);

    [[nodiscard]] virtual uint8_t getNumMoves(Generic_Rubiks_Cube & cube) const;

    // Basic functions to retrieve the private members.

    [[nodiscard]] virtual size_t getSize() const;

    [[nodiscard]] virtual size_t getNumItems() const;

    [[nodiscard]] virtual bool isFull() const;

    // Functions implementation for adding and retrieving data from a file.

    virtual void toFile(const string &file_path) const;

    virtual bool fromFile(const string &file_path);

    // Functions implemented so that the patterns can directly implement the basic needs or the basic operation they might want to do on the database.

    [[nodiscard]] virtual vector<uint8_t> inflate() const;

    virtual void reset();

    virtual ~Pattern_Database() = default;

};



#endif //PATTERN_DATABASE_H
