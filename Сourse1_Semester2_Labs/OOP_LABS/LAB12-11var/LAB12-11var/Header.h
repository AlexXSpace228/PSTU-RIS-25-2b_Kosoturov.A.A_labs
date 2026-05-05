#ifndef UNTITLED_LAB_12_OOP_H
#define UNTITLED_LAB_12_OOP_H

#include <iostream>
#include <set>
#include <vector>
#include <initializer_list>

class lab_12_oop {
};


template<class T>
class Container {
    std::multiset<T> data;
public:
    Container();
    Container(std::initializer_list<T> init);
    Container(int n);
    void Insert(const T& el);
    void Print() const;
    T Srednee() const;
    void Add(int pos, const T& el);
    void Del(const T& k1, const T& k2);
    void Delenie();
};

template<class T>
Container<T>::Container() {}

template<class T>
Container<T>::Container(std::initializer_list<T> init) {
    for (auto& x : init) {
        data.insert(x);
    }
}

template<class T>
void Container<T>::Insert(const T& el) {
    data.insert(el);
}

template<class T>
Container<T>::Container(int n) {
    T a;
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        data.insert(a);
    }
}

template<class T>
void Container<T>::Print() const {
    int i = 0;
    for (auto it = data.begin(); it != data.end(); ++it, ++i) {
        std::cout << i << ": " << *it << '\n';
    }
    std::cout << '\n';
}

template<class T>
T Container<T>::Srednee() const {
    T sum = T();
    for (auto& x : data) {
        sum = sum + x;
    }
    return sum / static_cast<T>(data.size());
}

template<class T>
void Container<T>::Add(int pos, const T& el) {
    if (pos <= 0) {
        data.insert(data.begin(), el);
        return;
    }
    auto it = data.begin();
    int count = 0;
    while (it != data.end() && count < pos) {
        ++it;
        ++count;
    }
    data.insert(it, el);
}

template<class T>
void Container<T>::Del(const T& k1, const T& k2) {
    auto it1 = data.lower_bound(k1);
    auto it2 = data.upper_bound(k2);
    data.erase(it1, it2);
}

template<class T>
void Container<T>::Delenie() {
    T avg = Srednee();
    std::vector<T> tmp(data.begin(), data.end());
    data.clear();
    for (auto& x : tmp) {
        data.insert(x + avg);
    }
}

#endif //UNTITLED_LAB_12_OOP_H
