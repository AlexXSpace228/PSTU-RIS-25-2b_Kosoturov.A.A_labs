#pragma once
#include <iostream>
using namespace std;

class Object {
public:
    virtual void Input() = 0;
    virtual void Show() = 0;
    virtual ~Object() {}
};