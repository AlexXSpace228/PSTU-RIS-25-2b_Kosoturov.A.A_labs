#include "List.h"

// Конструктор по умолчанию
List::List() : size(0), head(nullptr), tail(nullptr) {}

// Конструктор с параметром (создает список из s нулей)
List::List(int s) : size(0), head(nullptr), tail(nullptr) {
    if (s < 0) throw IndexError1();
    for (int i = 0; i < s; i++) {
        push_back(0);
    }
}

// Конструктор копирования
List::List(const List& other) : size(0), head(nullptr), tail(nullptr) {
    Node* curr = other.head;
    while (curr) {
        push_back(curr->data);
        curr = curr->next;
    }
}

// Деструктор
List::~List() {
    Node* curr = head;
    while (curr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

// Оператор присваивания
const List& List::operator=(const List& other) {
    if (this == &other) return *this;

    // Очистка текущего списка
    Node* curr = head;
    while (curr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = tail = nullptr;
    size = 0;

    // Копирование
    curr = other.head;
    while (curr) {
        push_back(curr->data);
        curr = curr->next;
    }
    return *this;
}

// Метод добавления в конец
void List::push_back(int val) {
    Node* newNode = new Node(val, nullptr, tail);
    if (tail) tail->next = newNode;
    else head = newNode;
    tail = newNode;
    size++;
}

// Оператор []: доступ по индексу (от начала)
int& List::operator[](int i) {
    if (i < 0) throw IndexError1();
    if (i >= size) throw IndexError2();

    Node* curr = head;
    for (int count = 0; count < i; count++) {
        curr = curr->next;
    }
    return curr->data;
}

// Оператор int(): размер списка
List::operator int() const {
    return size;
}

// Оператор +: сложение списков a[i] + b[i]
List List::operator+(const List& b) {
    if (this->size != b.size) {
        throw ListSizeMismatch(); // Исключение: размеры не совпадают
    }
    List temp;
    Node* curr1 = this->head;
    Node* curr2 = b.head;

    while (curr1 && curr2) {
        temp.push_back(curr1->data + curr2->data);
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return temp;
}

// Оператор -: переход влево на n элементов (от хвоста)
int& List::operator-(int n) {
    if (n < 0) throw IndexError1();
    if (n >= size) throw IndexError2();

    Node* curr = tail;
    for (int i = 0; i < n; i++) {
        curr = curr->prev; // Идем влево по двусвязному списку
    }
    return curr->data;
}

// Вывод
ostream& operator<<(ostream& out, const List& lst) {
    if (lst.size == 0) {
        out << "Empty\n";
    }
    else {
        Node* curr = lst.head;
        while (curr) {
            out << curr->data << " ";
            curr = curr->next;
        }
        out << endl;
    }
    return out;
}

// Ввод
istream& operator>>(istream& in, List& lst) {
    Node* curr = lst.head;
    while (curr) {
        cout << "> ";
        in >> curr->data;
        curr = curr->next;
    }
    return in;
}