#include "Money.h"

// Нормализация (если копеек больше 99 или меньше 0)
void Money::normalize() {
    if (kop >= 100) {
        rub += kop / 100;
        kop %= 100;
    }
    else if (kop < 0) {
        long diff = (-kop) / 100 + 1;
        rub -= diff;
        kop += diff * 100;
    }
}

Money::Money() {
    rub = 0;
    kop = 0;
}

Money::Money(long r, int k) {
    rub = r;
    kop = k;
    normalize();
}

Money::Money(const Money& p) {
    rub = p.rub;
    kop = p.kop;
}

Money::~Money() {}

Money& Money::operator=(const Money& p) {
    if (this == &p) return *this;
    rub = p.rub;
    kop = p.kop;
    return *this;
}

// Операции сравнения
bool Money::operator<(const Money& other) const {
    if (rub < other.rub) return true;
    if (rub == other.rub && kop < other.kop) return true;
    return false;
}

bool Money::operator>(const Money& other) const {
    if (rub > other.rub) return true;
    if (rub == other.rub && kop > other.kop) return true;
    return false;
}

bool Money::operator==(const Money& other) const {
    return (rub == other.rub && kop == other.kop);
}

// Префиксный инкремент (++m)
Money& Money::operator++() {
    kop++;
    normalize();
    return *this;
}

// Постфиксный инкремент (m++)
Money Money::operator++(int) {
    Money temp(*this);
    kop++;
    normalize();
    return temp;
}

// Уменьшение в заданное количество раз
Money Money::operator/(int divisor) const {
    long total_kopecks = rub * 100 + kop;
    total_kopecks /= divisor;
    return Money(total_kopecks / 100, total_kopecks % 100);
}

// Вывод в консоль (дробная часть через запятую)
ostream& operator<<(ostream& out, const Money& p) {
    out << p.rub << ",";
    if (p.kop < 10) out << "0"; // чтобы копейки выводились как ,05 а не ,5
    out << p.kop;
    return out;
}

// Ввод с консоли
istream& operator>>(istream& in, Money& p) {
    cout << "Рубли: "; in >> p.rub;
    cout << "Копейки: "; in >> p.kop;
    p.normalize();
    return in;
}

// Вывод в файл (через пробел, чтобы легко читать)
fstream& operator<<(fstream& fout, const Money& p) {
    fout << p.rub << " " << p.kop << "\n";
    return fout;
}

// Ввод из файла
fstream& operator>>(fstream& fin, Money& p) {
    fin >> p.rub >> p.kop;
    return fin;
}