#pragma once
#include <iostream>
#include "Error.h"
using namespace std;

// Узел двусвязного списка
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int d, Node* n = nullptr, Node* p = nullptr) : data(d), next(n), prev(p) {}
};

class List {
    int size;
    Node* head;
    Node* tail;

public:
    List();
    List(int s);
    List(const List& other);
    ~List();

    const List& operator=(const List& other);

    // Перегрузка операций по заданию
    int& operator[](int i);          // Доступ по индексу
    operator int() const;            // Определение размера списка
    List operator+(const List& b);   // Сложение элементов a[i] + b[i]
    int& operator-(int n);           // Переход влево на n элементов от конца

    // Вспомогательный метод добавления в конец (для ввода)
    void push_back(int val);

    friend ostream& operator<<(ostream& out, const List& lst);
    friend istream& operator>>(istream& in, List& lst);
};