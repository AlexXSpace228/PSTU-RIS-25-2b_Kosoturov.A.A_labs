#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Money {
private:
    long rub; // рубли
    int kop;  // копейки

    void normalize(); // вспомогательная функция для перевода лишних копеек в рубли

public:
    Money();
    Money(long r, int k);
    Money(const Money& p);
    ~Money();

    Money& operator=(const Money& p);

    // Операции сравнения
    bool operator<(const Money& other) const;
    bool operator>(const Money& other) const;
    bool operator==(const Money& other) const; // Понадобится для поиска заданного значения

    // Добавление копеек (++)
    Money& operator++();    // Префиксная (++m)
    Money operator++(int);  // Постфиксная (m++)

    // Уменьшение в 2 раза
    Money operator/(int divisor) const;

    // Ввод/вывод в консоль
    friend ostream& operator<<(ostream& out, const Money& p);
    friend istream& operator>>(istream& in, Money& p);

    // Ввод/вывод в файловый поток
    friend fstream& operator<<(fstream& fout, const Money& p);
    friend fstream& operator>>(fstream& fin, Money& p);
};