#pragma once
#include <iostream>
#include <stdexcept>
struct Node
{
	int value;
	Node* next;
};

class Iterator
{
private:
	Node* current;

public:
	Iterator(Node* node) : current(node) {}

	int& operator*() { return current->value; }

	Iterator& operator++()
	{
		current = current->next;
		return *this;
	}

	bool operator!=(const Iterator& other) const
	{
		return current != other.current;
	}
};

class LIST {
private:
	Node* head;
	int size;
public:

	LIST(int s, int k);
	LIST(const LIST& a);

	~LIST();

	void pushback(int value);

	int& operator[](int inbex);
	const int& operator[](int inbex) const;

	LIST& operator=(const LIST& a);

	LIST operator+(const LIST& other) const;

	Iterator operator-(int n) const;

	operator int() const
	{
		return size;
	}

	Iterator begin() const { return Iterator(head); }
	Iterator end() const { return Iterator(nullptr); }

	friend std::ostream& operator<<(std::ostream& out, const LIST& a);
	friend std::istream& operator>>(std::istream& in, LIST& a);
};





void LIST::pushback(int value) {
	Node* newnode = new Node{ value, nullptr };
	if (!head)
		head = newnode;
	else {
		Node* cur = head;
		while (cur->next) {
			cur = cur->next;
		}
		cur->next = newnode;
	}
	size++;
}






LIST::LIST(int s, int k) {
	head = nullptr;
	size = 0;
	for (int i = 0; i < s; ++i)
		pushback(k);
}

LIST::LIST(const LIST& a)
{
	head = nullptr;
	size = 0;

	Node* cur = a.head;
	while (cur)
	{
		pushback(cur->value);
		cur = cur->next;
	}
}






LIST LIST::operator+(const LIST& other) const
{
	if (size != other.size)
		throw std::length_error("Different sizes");

	LIST result(0, 0);

	Node* a = head;
	Node* b = other.head;

	while (a && b)
	{
		result.pushback(a->value + b->value);
		a = a->next;
		b = b->next;
	}

	return result;
}

LIST& LIST::operator=(const LIST& a) {
	if (this == &a) {
		return *this;
	}
	while (head) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	head = nullptr;
	size = 0;
	Node* cur = a.head;
	while (cur) {
		pushback(cur->value);
		cur = cur->next;
	}
	return *this;
}

Iterator LIST::operator-(int n) const
{
	if (n < 0 || n >= size)
		throw std::out_of_range("Index out of range");

	Iterator it = begin();
	for (int i = 0; i < n; ++i)
		++it;

	return it;
}

const int& LIST::operator[](int index) const {
	if (index < 0 || index >= size)
		throw std::out_of_range("Index out of range");
	Node* cur = head;
	for (int i = 0; i < index; i++) {
		cur = cur->next;
	}
	return cur->value;
}

int& LIST::operator[](int index) {
	if (index < 0 || index >= size)
		throw std::out_of_range("Index out of range");
	Node* cur = head;
	for (int i = 0; i < index; i++) {
		cur = cur->next;
	}
	return cur->value;
}






std::ostream& operator<<(std::ostream& out, const LIST& a)
{
	Node* cur = a.head;
	while (cur)
	{
		out << cur->value << " ";
		cur = cur->next;
	}
	return out;
}

std::istream& operator>>(std::istream& in, LIST& a)
{
	Node* cur = a.head;
	while (cur)
	{
		in >> cur->value;
		cur = cur->next;
	}
	return in;
}




LIST::~LIST() {
	while (head) {
		Node* Temp = head;
		head = head->next;
		delete Temp;
	}
}
