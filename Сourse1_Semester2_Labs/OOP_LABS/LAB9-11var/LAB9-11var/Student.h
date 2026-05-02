#pragma once
#include "Person.h"

class Student : public Person {
private:
    float rating;

public:
    Student();
    Student(string n, int a, float r);

    void Input() override;
    void Show() override;

    ~Student();
};