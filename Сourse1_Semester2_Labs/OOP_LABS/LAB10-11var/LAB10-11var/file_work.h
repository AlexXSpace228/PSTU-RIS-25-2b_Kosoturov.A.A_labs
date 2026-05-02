#pragma once
#include "Money.h"
#include <iostream>
#include <fstream>

using namespace std;

// Создание файла
int make_file(const char* f_name) {
    fstream stream(f_name, ios::out | ios::trunc); // открыть для записи
    if (!stream) return -1; // ошибка открытия файла

    int n;
    Money p;
    cout << "Сколько записей создать? ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Ввод записи " << i + 1 << ":\n";
        cin >> p;
        stream << p; // запись объекта в файловый поток
    }
    stream.close();
    return n;
}

// Чтение и печать файла
int print_file(const char* f_name) {
    fstream stream(f_name, ios::in); // открыть для чтения
    if (!stream) return -1;

    Money p;
    int i = 0;
    while (stream >> p) {
        cout << "[" << i + 1 << "] " << p << "\n";
        i++;
    }
    stream.close();
    return i;
}

// Удалить все записи больше заданного значения
int del_file(const char* f_name, Money target) {
    fstream temp("temp.txt", ios::out);
    fstream stream(f_name, ios::in);
    if (!stream) return -1;

    int count = 0;
    Money p;
    while (stream >> p) {
        if (stream.eof()) break;
        // Если запись НЕ больше заданного значения, сохраняем её
        if (!(p > target)) {
            temp << p;
        }
        else {
            count++; // счетчик удаленных
        }
    }
    stream.close();
    temp.close();

    remove(f_name);
    rename("temp.txt", f_name);
    return count; // возвращаем сколько удалили
}

// Уменьшить все записи с заданным значением в два раза
int change_file(const char* f_name, Money target) {
    fstream temp("temp.txt", ios::out);
    fstream stream(f_name, ios::in);
    if (!stream) return -1;

    int count = 0;
    Money p;
    while (stream >> p) {
        if (stream.eof()) break;
        if (p == target) {
            Money divided = p / 2; // Уменьшаем в 2 раза
            temp << divided;
            count++;
        }
        else {
            temp << p;
        }
    }
    stream.close();
    temp.close();

    remove(f_name);
    rename("temp.txt", f_name);
    return count; // возвращаем количество измененных
}

// Добавить K записей после элемента с заданным номером
int add_file(const char* f_name, int index, int K) {
    fstream temp("temp.txt", ios::out);
    fstream stream(f_name, ios::in);
    if (!stream) return -1;

    Money p;
    int i = 0;
    int added = 0;

    while (stream >> p) {
        if (stream.eof()) break;
        i++;
        temp << p; // записываем текущий элемент

        // Если достигли заданного номера, добавляем K новых элементов
        if (i == index) {
            for (int j = 0; j < K; j++) {
                Money new_money;
                cout << "Введите новую сумму (" << j + 1 << " из " << K << "):\n";
                cin >> new_money;
                temp << new_money;
                added++;
            }
        }
    }
    stream.close();
    temp.close();

    remove(f_name);
    rename("temp.txt", f_name);
    return added; // возвращаем количество добавленных
}