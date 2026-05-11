#pragma once
#include "Object.h"
#include <string>

class Person : public Object {
protected:
    string name;
    int age;

public:
    Person();
    Person(string n, int a);
    Person(const Person& p);

    Person& operator=(const Person& p);

    void Input() override;
    void Show() override;

    string GetName() const;
    int GetAge() const;

    void SetName(string n);
    void SetAge(int a);

    virtual ~Person();
};