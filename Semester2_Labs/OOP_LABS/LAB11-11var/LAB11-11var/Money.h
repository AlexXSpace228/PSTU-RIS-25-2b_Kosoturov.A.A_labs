#pragma once
#include <iostream>
using namespace std;

class Money {
    long rub;
    int kop;
public:
    Money(long r = 0, int k = 0) {
        rub = r + k / 100;
        kop = k % 100;
    }

    // Ввод/вывод с подсказками
    friend istream& operator>>(istream& in, Money& m) {
        cout << "  Рубли: ";
        in >> m.rub;
        cout << "  Копейки: ";
        in >> m.kop;
        m.rub += m.kop / 100;
        m.kop %= 100;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Money& m) {
        return out << m.rub << "," << (m.kop < 10 ? "0" : "") << m.kop << " руб.";
    }

    // Операции
    Money operator+(const Money& m) {
        return Money(rub + m.rub, kop + m.kop);
    }

    Money operator-(const Money& m) {
        long total1 = rub * 100 + kop;
        long total2 = m.rub * 100 + m.kop;
        long diff = total1 - total2;
        return Money(diff / 100, diff % 100);
    }

    Money operator/(int n) {
        long total = rub * 100 + kop;
        total /= n;
        return Money(total / 100, total % 100);
    }

    bool operator<(const Money& m) {
        return rub < m.rub || (rub == m.rub && kop < m.kop);
    }

    bool operator==(const Money& m) {
        return rub == m.rub && kop == m.kop;
    }
};