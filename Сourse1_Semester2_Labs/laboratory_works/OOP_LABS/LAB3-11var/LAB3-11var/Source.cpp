#include <iostream>
#include "class_Money.h"

int main() {
    setlocale(LC_ALL, "RU");

    // ===== Конструкторы
    Money m1;
    Money m2(100, 50);
    Money m3(m2);

    std::cout << "m1: " << m1 << "\n";
    std::cout << "m2: " << m2 << "\n";
    std::cout << "m3 (копия m2): " << m3 << "\n\n";

    // ===== Сеттеры
    m1.setRoubles(200);
    m1.setPeny(75);

    std::cout << "m1 после set: " << m1 << "\n\n";

    // ===== Геттеры
    std::cout << "m1 рубли: " << m1.GetRUB() << "\n";
    std::cout << "m1 копейки: " << m1.GetP() << "\n\n";

    // ===== Ввод
    Money m4;
    std::cin >> m4;
    std::cout << "Введённое значение: " << m4 << "\n\n";

    // ===== Присваивание
    m4 = m2;
    std::cout << "m4 после присваивания m2: " << m4 << "\n\n";

    // ===== Префиксный ++
    std::cout << "m2 до ++: " << m2 << "\n";
    ++m2;
    std::cout << "m2 после ++: " << m2 << "\n\n";

    // ===== Постфиксный ++
    std::cout << "m2 до m2++: " << m2 << "\n";
    Money temp = m2++;
    std::cout << "вернулось (старое значение): " << temp << "\n";
    std::cout << "m2 после m2++: " << m2 << "\n\n";

    // ===== Сравнение
    std::cout << "m2: " << m2 << " | m3: " << m3 << "\n";

    if (m2 > m3)
        std::cout << "m2 > m3\n";
    else if (m2 < m3)
        std::cout << "m2 < m3\n";
    else
        std::cout << "m2 == m3\n";

    return 0;
}