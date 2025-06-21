//
// Created by akshi on 20-06-2025.                          10 - Completed - 7
//

#include "Nibble_Array.h"

Nibble_Array::Nibble_Array(const size_t size_, const uint8_t value) : size(size_), data_array(size/2+1,value) {}

uint8_t Nibble_Array::get(const size_t index) const {
    const size_t idx = index/2;
    assert(index <= this->size);
    const uint8_t value = this->data_array.at(idx);

    // 0-based indexing for the data stored so we are returning according to that.
    if (index % 2 == 0) {           // return first 4 digits
        return value >> 4;
    } else {                        // return last 4 digits
        return value & 0x0F;
    }
}

void Nibble_Array::set(const size_t index, const uint8_t value) {
    const size_t idx = index/2;
    assert(index <= this->size);
    const uint8_t current_value = this->data_array.at(idx);

    if (index % 2 == 0) {
        this->data_array.at(idx) = (current_value & 0x0F) | (value << 4)  ;
    } else {
        this->data_array.at(idx) = (current_value & 0xF0) | (value & 0x0F);
    }
}

uint8_t *Nibble_Array::data() {
    return this->data_array.data();
}

const uint8_t *Nibble_Array::data() const {
    return this->data_array.data();
}

size_t Nibble_Array::storageSize() const {
    return this->data_array.size();
}

void Nibble_Array::inflate(vector<uint8_t> &new_data_array) const {
    new_data_array.resize(this->size);

    for (unsigned i = 0; i < this->size; i++) {
        new_data_array.push_back(this->get(i));
    }
}

void Nibble_Array::reset(const uint8_t value) {
    ranges::fill(this->data_array, value);            // direct fill requires starting and ending range filling by .begin() and .end(), but ranges::fill does it directly.
}
