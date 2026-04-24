#pragma once
#include "ClassTRIAD.h"

class Vector {
private:
    TRIAD** arr;
    int size;

public:
    Vector(int n) : size(n) {
        arr = new TRIAD * [size];
    }

    void set(int i, TRIAD* obj) {
        arr[i] = obj;
    }

    TRIAD* get(int i) {
        return arr[i];
    }

    friend std::ostream& operator<<(std::ostream& out, const Vector& v) {
        for (int i = 0; i < v.size; i++) {
            out << *(v.arr[i]) << "\n";
        }
        return out;
    }

    ~Vector() {
        for (int i = 0; i < size; i++)
            delete arr[i];
        delete[] arr;
    }
};