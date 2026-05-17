#include "Money.h"
#include "file_work.h"
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian"); // Для корректного отображения кириллицы
    int k, c;
    char file_name[30];

    do {
        cout << "\n=== МЕНЮ ===";
        cout << "\n1. Создать файл";
        cout << "\n2. Вывести файл на экран";
        cout << "\n3. Удалить записи больше заданного значения";
        cout << "\n4. Уменьшить записи равные заданному значению в 2 раза";
        cout << "\n5. Добавить K записей после элемента с заданным номером";
        cout << "\n0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> c;

        switch (c) {
        case 1:
            cout << "Имя файла? "; cin >> file_name;
            k = make_file(file_name);
            if (k < 0) cout << "Ошибка создания файла!\n";
            else cout << "Записано " << k << " элементов.\n";
            break;

        case 2:
            cout << "Имя файла? "; cin >> file_name;
            k = print_file(file_name);
            if (k == 0) cout << "Файл пуст.\n";
            if (k < 0) cout << "Ошибка чтения файла!\n";
            break;

        case 3: {
            cout << "Имя файла? "; cin >> file_name;
            Money target;
            cout << "Введите значение, больше которого нужно удалить записи:\n";
            cin >> target;
            k = del_file(file_name, target);
            if (k < 0) cout << "Ошибка работы с файлом!\n";
            else cout << "Удалено " << k << " элементов.\n";
            break;
        }

        case 4: {
            cout << "Имя файла? "; cin >> file_name;
            Money target;
            cout << "Введите значение, которое нужно уменьшить в 2 раза:\n";
            cin >> target;
            k = change_file(file_name, target);
            if (k < 0) cout << "Ошибка работы с файлом!\n";
            else cout << "Изменено " << k << " элементов.\n";
            break;
        }

        case 5: {
            cout << "Имя файла? "; cin >> file_name;
            int nom, count;
            cout << "Номер элемента, после которого добавить? "; cin >> nom;
            cout << "Количество добавляемых элементов (K)? "; cin >> count;
            k = add_file(file_name, nom, count);
            if (k < 0) cout << "Ошибка работы с файлом!\n";
            else cout << "Успешно добавлено " << k << " элементов.\n";
            break;
        }
        }
    } while (c != 0);

    return 0;
}