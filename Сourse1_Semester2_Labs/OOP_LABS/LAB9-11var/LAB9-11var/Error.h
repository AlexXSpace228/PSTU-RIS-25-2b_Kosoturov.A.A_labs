#pragma once
#include <string>
#include <iostream>
using namespace std;

// Базовый класс
class Error {
public:
    virtual void what() {}
};

// Ошибка, связанная с индексами
class IndexError : public Error {
protected:
    string msg;
public:
    IndexError() { msg = "Index Error\n"; }
    virtual void what() { cout << msg; }
};

// Ошибка, связанная с размером
class SizeError : public Error {
protected:
    string msg;
public:
    SizeError() { msg = "Size Error\n"; }
    virtual void what() { cout << msg; }
};

// Специфичные ошибки
class ListSizeMismatch : public SizeError {
protected:
    string msg_;
public:
    ListSizeMismatch() { msg_ = "Lists have different sizes for addition!\n"; }
    virtual void what() { cout << msg << msg_; }
};

class IndexError1 : public IndexError {
protected:
    string msg_;
public:
    IndexError1() { msg_ = "Index < 0 (Индекс меньше нуля)\n"; }
    virtual void what() { cout << msg << msg_; }
};

class IndexError2 : public IndexError {
protected:
    string msg_;
public:
    IndexError2() { msg_ = "Index >= size (Индекс выходит за пределы размера)\n"; }
    virtual void what() { cout << msg << msg_; }
};