#include <stdexcept>
#include "stack.h"

Stack::Stack() : capacity(10), size(0) {
    data = new int[capacity];
}
Stack& Stack::operator<< (int value) {
    if (size == capacity) {
        capacity *= 2;
        int* newData = new int[capacity];
        for(int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[size++] = value;
    return *this;
}

Stack& Stack::operator>>(int& toSave) {
    if (size > 0) {
        toSave = data[--size];
    return *this;
    }
    throw std::out_of_range("Stack is empty! :(");
}
Stack& Stack::operator= (const Stack& other){
    if (this != &other) {
            capacity = other.capacity;
            size = other.size;
            delete[] data;
            int* newData = new int[capacity];
            for(int i = 0; i < size; i++) {
                newData[i] = other.data[i];
            }
            data = newData;
        }
    return *this;
    }

int Stack::operator[](int index) const {
    if (index >= 0 && index < size) {
    return data[index];
    }
    throw std::out_of_range("Index is out of range :'(");
}
bool Stack::operator<(const Stack& other) const {
    return size < other.size;
}
bool Stack::operator==(const Stack& other) const {
    return size == other.size;
}
bool Stack::isEmpty() const {
    return !size;
    };
Stack::~Stack() {
    delete[] data;
}