//
// Created by akshi on 20-06-2025.                          12 - Completed - 9
//

#include "Pattern_Database.h"

Pattern_Database::Pattern_Database(const size_t size): database(size,0xFF), size_(size), num_items(0) {}

Pattern_Database::Pattern_Database(const size_t size, const uint8_t initial_value): database(size,initial_value), size_(size), num_items(0) {}

// If the index is already set, it does nothing and returns false
// Else it sets ind and returns true

bool Pattern_Database::setNumMoves(const uint32_t index, const uint8_t num_moves) {
    const uint8_t old_moves = this->getNumMoves(index);

    if (old_moves == 0xF) {
        ++this->num_items;
    }

    if (num_moves < old_moves) {
        this->database.set(index, num_moves);
        return true;
    }
    return false;
}

uint8_t Pattern_Database::getNumMoves(const uint32_t index) const {
    return this->database.get(index);
}

bool Pattern_Database::setNumMoves(Generic_Rubiks_Cube &cube, const uint8_t num_moves) {
    return this->setNumMoves(this->getDatabaseIndex(cube), num_moves);
}

uint8_t Pattern_Database::getNumMoves(Generic_Rubiks_Cube &cube) const {
    return this->getNumMoves(this->getDatabaseIndex(cube));
}

size_t Pattern_Database::getSize() const {
    return this->size_;
}

size_t Pattern_Database::getNumItems() const {
    return this->num_items;
}

bool Pattern_Database::isFull() const {
    return this->num_items == this->size_;
}

void Pattern_Database::toFile(const string &file_path) const {
    ofstream writer(file_path, ios::out | ios::binary | ios::trunc);

    if (!writer.is_open()) {
        throw runtime_error("Could not open file " + file_path + " to write.");                // Changed for Fun
    }

    writer.write(
        reinterpret_cast<const char *>(this->database.data()),
        this->database.storageSize()
        );

    writer.close();

}

// Returns true of database is loaded successfully
// else return false

bool Pattern_Database::fromFile(const string &file_path) {
    ifstream reader(file_path, ios::in | ios::ate);

    if (!reader.is_open()) {
        return false;
    }

    size_t file_size = reader.tellg();

    if (file_size != this->database.storageSize()) {
        reader.close();
        throw "Database corrupt! Failed to open the Reader";
    }

    reader.seekg(0, ios::beg);
    reader.read(
        reinterpret_cast<char *>(this->database.data()),
        this->database.storageSize()
        );

    reader.close();
    this->num_items = this->size_;
    return true;

}

vector<uint8_t> Pattern_Database::inflate() const {
    vector<uint8_t> inflated;
    this->database.inflate(inflated);
    return inflated;
}

void Pattern_Database::reset() {
    if (this->num_items != 0) {
        this->database.reset(0xFF);
        this->num_items = 0;
    }
}
