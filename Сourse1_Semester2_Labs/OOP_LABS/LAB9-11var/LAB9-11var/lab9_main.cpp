#include "List.h"
#include "Windows.h"
#include <iostream>
using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    try {
        cout << "--- Создание списков ---\n";
        List a(3);
        cout << "Введите 3 элемента для списка a:\n";
        cin >> a;

        List b(3);
        cout << "Введите 3 элемента для списка b:\n";
        cin >> b;

        cout << "\nСписок a: " << a;
        cout << "Список b: " << b;

        cout << "\n--- Проверка int() (Размер) ---\n";
        cout << "Размер списка a: " << int(a) << endl;

        cout << "\n--- Проверка оператора + ---\n";
        List c = a + b;
        cout << "Список c = a + b: " << c;

        cout << "\n--- Проверка оператора [] ---\n";
        cout << "a[1] = " << a[1] << endl;

        cout << "\n--- Проверка оператора - (Переход влево от конца) ---\n";
        cout << "Элемент на 1 шаг влево от конца (a - 1): " << (a - 1) << endl;

        cout << "\n--- ГЕНЕРАЦИЯ ИСКЛЮЧЕНИЙ ---\n";

        // 1. Индекс больше размера
        //cout << a[10] << endl; 

        // 2. Отрицательный шаг
        //cout << (a - (-2)) << endl;

        //3. Сложение списков разного размера
        List d(5);
        List e = a + d; 

    }
    catch (Error& e) {
        cout << "\nПЕРЕХВАТ ИСКЛЮЧЕНИЯ:\n";
        e.what();
    }

    system("pause");
    return 0;
}