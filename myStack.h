#pragma once
#include <stdexcept>
#include <iostream>

template <typename T>
class Stack {
public:
    Stack() : capacity(10), size(0) {
        data = new T[capacity];
    }

    Stack& operator<<(T value) {
        if (size == capacity) {
            capacity *= 2;
            T* newData = new T[capacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size++] = value;
        return *this;
    }

    Stack& operator>>(T& toSave) {
        if (size > 0) {
            toSave = data[--size];
            return *this;
        }
        throw std::out_of_range("Stack is empty! :(");
    }

    Stack& operator=(const Stack& other) {
        if (this != &other) {
            capacity = other.capacity;
            size = other.size;
            delete[] data;
            T* newData = new T[capacity];
            for (int i = 0; i < size; i++) {
                newData[i] = other.data[i];
            }
            data = newData;
        }
        return *this;
    }

    T operator[](int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        }
        throw std::out_of_range("Index is out of range :'(");
    }

    bool operator<(const Stack& other) const {
        return size < other.size;
    }

    bool operator==(const Stack& other) const {
        return size == other.size;
    }

    bool isEmpty() const {
        return !size;
    }

    ~Stack() {
        delete[] data;
    }

private:
    int capacity;
    int size;
    T* data;
};