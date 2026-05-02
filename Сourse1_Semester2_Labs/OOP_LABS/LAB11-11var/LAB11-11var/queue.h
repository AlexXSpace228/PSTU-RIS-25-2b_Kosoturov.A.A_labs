#pragma once
#include <iostream>
using namespace std;

template<class T>
class Queue {
    T* data;
    int size;

public:
    Queue(int n = 0) {
        size = n;
        data = new T[size];
        for (int i = 0; i < size; i++)
            cin >> data[i];
    }

    ~Queue() { delete[] data; }

    bool empty() { return size == 0; }

    T front() { return data[0]; }

    void pop() {
        if (size == 0) return;

        T* tmp = new T[size - 1];
        for (int i = 1; i < size; i++)
            tmp[i - 1] = data[i];

        delete[] data;
        data = tmp;
        size--;
    }

    void push(T x) {
        T* tmp = new T[size + 1];
        for (int i = 0; i < size; i++)
            tmp[i] = data[i];

        tmp[size] = x;

        delete[] data;
        data = tmp;
        size++;
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << endl;
    }
};