#include <iostream>
#include <clocale>
#include "LIST.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    LIST a(5, 1);  // [1 1 1 1 1]
    LIST b(5, 2);  // [2 2 2 2 2]

    cout << "List a: " << a << endl;
    cout << "List b: " << b << endl;

    cout << "\nВведите элементы для списка a:\n";
    cin >> a;
    cout << "Обновленный a: " << a << endl;

    cout << "\nДоступ a[2]: " << a[2] << endl;
    a[2] = 100;
    cout << "После изменения a[2]=100: " << a << endl;

    int sizeA = a;
    cout << "\nРазмер a: " << sizeA << endl;

    LIST c = a + b;
    cout << "\na + b: " << c << endl;

    cout << "\nЭлемент с индексом 3 с использованием итератора: ";
    Iterator it = a - 3;
    cout << *it << endl;

    cout << "\nИтератор a: ";
    for (Iterator i = a.begin(); i != a.end(); ++i)
        cout << *i << " ";
    cout << endl;

    LIST d = a;
    cout << "\nКопирование а (d): " << d << endl;

    LIST e(3, 0);
    e = a;
    cout << "Assigned e = a: " << e << endl;

    return 0;
}