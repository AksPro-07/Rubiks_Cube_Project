//
// Created by akshi on 20-06-2025.                          9 - Completed - 6
//

#ifndef NIBBLE_ARRAY_H
#define NIBBLE_ARRAY_H

// We need something to store all those heuristic values for all those permutations, so we are building Nibble_Array.
// It will have index which separate the nodes ( i.e. the permutation or the cubes configuration ) from one another.
// It is implemented now for the corner cases, and since, they can be solved within 11 moves, we can store their heuristic value or the so-called distance in the 4 bits.

#include <bits/stdc++.h>
using namespace std;

class Nibble_Array {

private:

    size_t size;
    vector<uint8_t> data_array;

public:

    // Defining the basic functions.

    Nibble_Array(size_t size_, uint8_t value = 0xFF);

    [[nodiscard]] uint8_t get(size_t index) const;

    void set(size_t index, uint8_t value);

    // Defining the functions to get pointer to underlying array (Purpose not too clear now)
    //Defining both versions allows you to use .data() safely in both read-only and read-write contexts, while enforcing const-correctness.
    //using uint8_t = unsigned char;
    //You return unsigned char* or uint8_t* when working with binary/raw data — not actual text — and you want to access or manipulate the individual bytes safely.
    //Expression	            What it calls	         What it returns
    //this->data_array.data()	STL vector's .data()	Pointer to internal array
    //this->data_array.size()	STL vector's .size()	Number of elements (of type size_t)
    //You're simply exposing the underlying vector’s .data() and .size() via your class interface — not calling your own methods recursively.


    unsigned char *data();

    [[nodiscard]] const unsigned char *data() const;

    [[nodiscard]] size_t storageSize() const;

    // (Purpose not too clear now) May be it's because now we are using them and not storing and this way it's easier.
    // Move all the moves to a vector. This doubles the size, but is faster to access,
    // since there is no bitwise operation needed.

    void inflate(vector<uint8_t> &new_data_array) const;

    // Reset the array (Purpose not too clear now, but I would highly recommend for you to always implement reset functions whenever you deal with databases as such and treat it as a general good practice or something like that )

    void reset(uint8_t value = 0xFF);


};


#endif //NIBBLE_ARRAY_H
