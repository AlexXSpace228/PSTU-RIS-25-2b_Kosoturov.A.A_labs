#include <iostream>
#include <string>
#include "Class_Automobile.h"

using namespace std;

AUTOMOBILE make_auto() {
    string mark, model;
    int cost;
    cout << "Введите марку: ";
    cin >> mark;
    cout << "Введите модель: ";
    cin >> model;
    cout << "Введите стоимость: ";
    cin >> cost;

    AUTOMOBILE a(mark, model, cost);
    return a;
}

void AUTOMOBILE::show() {
    std::cout << "Марка: " << mark << " | Модель: " << model << " | Цена: " << cost << std::endl;
}

void print_auto(AUTOMOBILE a) {
    a.show();
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "конструктора без параметров" << endl;
    AUTOMOBILE a1;
    a1.show();

    cout << "\nконструктор с параметрами" << endl;
    AUTOMOBILE a2("Toyota", "Camry", 3000000);
    a2.show();

    cout << "\nконструктор копирования" << endl;
    AUTOMOBILE a3 = a2;
    a3.setmodel("Corolla");
    a3.setcost(2500000);
    a3.show();

    cout << "\nВывод объекта с передачей" << endl;
    print_auto(a3);

    cout << "\nСоздание объекта" << endl;
    a1 = make_auto();
    a1.show();

    return 0;
}