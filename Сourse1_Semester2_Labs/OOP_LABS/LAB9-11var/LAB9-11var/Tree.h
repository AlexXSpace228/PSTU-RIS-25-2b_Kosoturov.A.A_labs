#pragma once
#include "Object.h"

struct Node {
    Object* data;
    Node* left;
    Node* right;

    Node(Object* d) : data(d), left(nullptr), right(nullptr) {}
};

class Tree {
protected:
    Node* root;

    void Add(Node*& node, Object* obj);
    void Show(Node* node);
    void DeleteTree(Node* node);

public:
    Tree();
    ~Tree();

    void Add(Object* obj);
    void Show();
};