#pragma once
#include <iostream>
#include <string>

using namespace std;

// --- СОБЫТИЯ ---
const int evNothing = 0;
const int evMessage = 100;
const int cmAdd = 1;
const int cmDel = 2;
const int cmShow = 3;
const int cmShowOne = 4;
const int cmMake = 5;
const int cmQuit = 101;

struct TEvent {
    int what;
    union {
        int command;
        struct {
            int message;
            int a;
        };
    };
};

// --- БАЗОВЫЙ КЛАСС ---
class Object {
public:
    Object() {}
    virtual ~Object() {}
    virtual void Show() = 0;
    virtual void Input() = 0;
    virtual void HandleEvent(const TEvent& e) = 0;
};

// --- КЛАССЫ PERSON И STUDENT ---
class Person : public Object {
protected:
    string name;
    int age;
public:
    Person() { name = ""; age = 0; }
    Person(string n, int a) { name = n; age = a; }
    void Show() override { cout << "Name: " << name << ", Age: " << age << endl; }
    void Input() override {
        cout << "Enter name: "; cin >> name;
        cout << "Enter age: "; cin >> age;
    }
    void HandleEvent(const TEvent& e) override {
        if (e.what == evMessage && e.command == cmShow) Show();
    }
};

class Student : public Person {
    float rating;
public:
    Student() : Person() { rating = 0.0; }
    void Show() override {
        cout << "STUDENT -> Name: " << name << ", Age: " << age << ", Rating: " << rating << endl;
    }
    void Input() override {
        Person::Input();
        cout << "Enter rating: "; cin >> rating;
    }
    void HandleEvent(const TEvent& e) override {
        if (e.what == evMessage && e.command == cmShow) Show();
    }
};

// --- КОНТЕЙНЕР ДЕРЕВО ---
struct Node {
    Object* data;
    Node* left, * right;
    int id;
};

class Tree {
protected:
    Node* root;
    int size;
    int current_id;

    void Clear(Node* t) {
        if (t) {
            Clear(t->left);
            Clear(t->right);
            delete t->data;
            delete t;
        }
    }

    void Print(Node* t) {
        if (t) {
            t->data->Show();
            Print(t->left);
            Print(t->right);
        }
    }

    Node* Insert(Node* t, Object* obj) {
        if (!t) {
            t = new Node{ obj, nullptr, nullptr, ++current_id };
            return t;
        }
        t->left = Insert(t->left, obj); // Упрощенное добавление в одну ветку
        return t;
    }

public:
    Tree() : root(nullptr), size(0), current_id(0) {}
    virtual ~Tree() { Clear(root); }

    void Add() {
        int type;
        cout << "1.Person, 2.Student: "; cin >> type;
        Object* obj = (type == 1) ? (Object*)new Person : (Object*)new Student;
        obj->Input();
        root = Insert(root, obj);
        size++;
    }

    Object* Find(Node* t, int id) {
        if (!t) return nullptr;
        if (t->id == id) return t->data;
        return Find(t->left, id); // поиск в глубину
    }
    // Публичный метод
    void ShowOne(int id) {
        Object* obj = Find(root, id);
        if (obj) obj->Show();
        else cout << "Object not found" << endl;
    }

    void Del() { Clear(root); root = nullptr; size = 0; current_id = 0; }
    void Show() { if (!root) cout << "Empty" << endl; else Print(root); }
};

// --- ДИАЛОГ ---
class Dialog : public Tree {
protected:
    int EndState;
public:
    Dialog() : Tree(), EndState(0) {}
    void GetEvent(TEvent& event) {
        string s; cout << "> "; cin >> s;
        char code = s[0];
        if (string("m+-sq?").find(code) != string::npos) {
            event.what = evMessage;
            switch (code) {
            case 'm': event.command = cmMake; break;
            case '+': event.command = cmAdd; break;
            case '-': event.command = cmDel; break;
            case 's': event.command = cmShow; break;
            case 'q': event.command = cmQuit; break;
            case '?': event.command = cmShowOne; break;
            }
            if (s.length() > 1) event.a = stoi(s.substr(1));
        }
        else event.what = evNothing;
    }

    int Execute() {
        TEvent event;
        do {
            GetEvent(event);
            HandleEvent(event);
        } while (EndState == 0);
        return 0;
    }

    void HandleEvent(TEvent& event) {
        if (event.what == evMessage) {
            switch (event.command) {
            case cmMake: for (int i = 0; i < event.a; ++i) Add(); break;
            case cmAdd: Add(); break;
            case cmDel: Del(); break;
            case cmShow: Show(); break;
            case cmQuit: EndState = 1; break;
            case cmShowOne: ShowOne(event.a); break;
            }
            event.what = evNothing;
        }
    }
};