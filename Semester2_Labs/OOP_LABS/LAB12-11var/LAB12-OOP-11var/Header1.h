#pragma once

#ifndef UNTITLED_ID_PAIR_H
#define UNTITLED_ID_PAIR_H
#include <iostream>
#include <fstream>

class idPair {
    int first;
    double second;
public:
    idPair();
    idPair(int first, double second);
    idPair& operator--();
    void multiply(double k);
    void subtract(double k);
    void sum(double k);
    idPair operator--(int);
    bool operator<(const idPair& other) const;
    bool operator>(const idPair& other) const;
    bool operator==(const idPair& other) const;
    bool operator!=(const idPair& other) const;
    friend std::ostream& operator<<(std::ostream& out, const idPair& t);
    friend std::istream& operator>>(std::istream& in, idPair& a);
    friend std::fstream& operator>>(std::fstream& fin, idPair& a);
    friend std::fstream& operator<<(std::fstream& fout, const idPair& a);
    [[nodiscard]] double value() const;
};

inline idPair::idPair() {
    first = 0;
    second = 0;
}

inline double idPair::value() const {
    return first + second;
}



inline idPair::idPair(int first, double second) {
    this->first = first;
    this->second = second;
}

inline idPair& idPair::operator--() {
    first--;
    return *this;
}

inline idPair idPair::operator--(int) {
    idPair temp = *this;
    second--;
    return temp;
}

inline bool idPair::operator<(const idPair& other) const {
    return (this->first + this->second) < (other.first + other.second);
}

inline bool idPair::operator>(const idPair& other) const {
    return (this->first + this->second) > (other.first + other.second);
}

inline bool idPair::operator==(const idPair& other) const {
    return (this->first + this->second) == (other.first + other.second);
}

inline bool idPair::operator!=(const idPair& other) const {
    return !(*this == other);
}

inline void idPair::multiply(double k) {
    double total = first + second;
    total *= k;
    first = static_cast<int>(total);
    second = total - first;
}

inline void idPair::sum(double k) {
    double total = first + second + k;
    //total *= k;
    first = static_cast<int>(total);
    second = total - first;
}

inline void idPair::subtract(double k) {
    double cur = first + second;
    cur -= k;
    if (cur < 0) cur = 0;
    first = static_cast<int>(cur);
    second = cur - first;
}

inline std::ostream& operator<<(std::ostream& out, const idPair& t) {
    return (out << t.first << " : " << t.second << '\n');
}

inline std::istream& operator>>(std::istream& in, idPair& a)
{
    in >> a.first >> a.second;
    return in;
}

inline std::fstream& operator>>(std::fstream& fin, idPair& a)
{
    fin >> a.first >> a.second;
    return fin;
}

inline std::fstream& operator<<(std::fstream& fout, const idPair& a)
{
    fout << a.first << '\n' << a.second << '\n';
    return fout;
}

#endif
