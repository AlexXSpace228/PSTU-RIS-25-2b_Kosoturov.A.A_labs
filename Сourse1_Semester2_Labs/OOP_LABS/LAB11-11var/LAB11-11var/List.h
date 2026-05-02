#pragma once
#include <iostream>
#include <list>
using namespace std;

template<class T>
class MyList {
    list<T> data; // Используем STL список!

public:
    MyList(int n = 0) {
        T x;
        for (int i = 0; i < n; i++) {
            cout << "Введите элемент [" << i + 1 << " из " << n << "]:\n";
            cin >> x;
            data.push_back(x);
        }
    }

    void print(const char* msg = "") {
        cout << "--- " << msg << " ---\nСодержимое: ";
        if (data.empty()) {
            cout << "Пусто\n\n";
            return;
        }
        for (auto it = data.begin(); it != data.end(); ++it) {
            cout << *it << " | ";
        }
        cout << "\n\n";
    }

    T srednee() {
        if (data.empty()) return T();
        auto it = data.begin();
        T s = *it;
        ++it;
        for (; it != data.end(); ++it) {
            s = s + *it;
        }
        return s / data.size();
    }

    void add_begin(T x) {
        data.push_front(x); // Встроенный метод STL списка
    }

    void delete_key(T key) {
        for (auto it = data.begin(); it != data.end(); ) {
            if (*it == key) {
                it = data.erase(it);
            }
            else {
                ++it;
            }
        }
    }

    T min_val() {
        auto it = data.begin();
        T m = *it;
        for (; it != data.end(); ++it) {
            if (*it < m) m = *it;
        }
        return m;
    }

    void subtract_min() {
        if (data.empty()) return;
        T m = min_val();
        for (auto it = data.begin(); it != data.end(); ++it) {
            *it = *it - m;
        }
    }
};