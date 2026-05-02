#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
struct Node
{
	T value;
	Node<T>* next;
};

template <typename T>
class Iterator {
private:
	Node<T>* current;
public:
	Iterator(Node<T>* node) : current(node) {}
	T& operator*() { return current->value; }

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

template <class T>
class LIST {
private:
	Node<T>* head;
	int size;
public:

	LIST(int s, T k);
	LIST(const LIST& a);

	~LIST();

	void pushback(T value);

	T& operator[](int index);
	const T& operator[](int index) const;

	LIST& operator=(const LIST& a);

	LIST operator+(const LIST& other) const;

	operator int() const
	{
		return size;
	}

	Iterator<T> begin() const { return Iterator<T>(head); }
	Iterator<T> end() const { return Iterator<T>(nullptr); }

	friend std::ostream& operator<<(std::ostream& out, const LIST& a) {
		Node<T>* cur = a.head;
		while (cur)
		{
			out << cur->value << " ";
			cur = cur->next;
		}
		return out;
	}
	friend std::istream& operator>>(std::istream& in, LIST& a) {
		Node<T>* cur = a.head;
		while (cur)
		{
			in >> cur->value;
			cur = cur->next;
		}
		return in;
	}
};






template <typename T>
void LIST<T>::pushback(T value) {
	Node<T>* newnode = new Node<T>{ value, nullptr };

	if (!head)
		head = newnode;
	else {
		Node<T>* cur = head;
		while (cur->next) {
			cur = cur->next;
		}
		cur->next = newnode;
	}
	size++;
}



template <class T>
LIST<T>::LIST(int s, T k) {
	head = nullptr;
	size = 0;
	for (int i = 0; i < s; ++i)
		pushback(k);
}

template <class T>
LIST<T>::LIST(const LIST& a)
{
	head = nullptr;
	size = 0;

	Node<T>* cur = a.head;
	while (cur)
	{
		pushback(cur->value);
		cur = cur->next;
	}
}





template <class T>
LIST<T> LIST<T>::operator+(const LIST& other) const
{
	if (size != other.size)
		throw std::length_error("Different sizes");

	LIST<T> result(0, T());

	Node<T>* a = head;
	Node<T>* b = other.head;

	while (a && b)
	{
		result.pushback(a->value + b->value);
		a = a->next;
		b = b->next;
	}

	return result;
}

template <class T>
LIST<T>& LIST<T>::operator=(const LIST& a) {
	if (this == &a) {
		return *this;
	}
	while (head) {
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}
	head = nullptr;
	size = 0;
	Node<T>* cur = a.head;
	while (cur) {
		pushback(cur->value);
		cur = cur->next;
	}
	return *this;
}
template <class T>
const T& LIST<T>::operator[](int index) const {
	if (index < 0 || index >= size)
		throw std::out_of_range("Index out of range");
	Node<T>* cur = head;
	for (int i = 0; i < index; i++) {
		cur = cur->next;
	}
	return cur->value;
}
template <class T>
T& LIST<T>::operator[](int index) {
	if (index < 0 || index >= size)
		throw std::out_of_range("Index out of range");
	Node<T>* cur = head;
	for (int i = 0; i < index; i++) {
		cur = cur->next;
	}
	return cur->value;
}



template <class T>
LIST<T>::~LIST() {
	while (head) {
		Node<T>* Temp = head;
		head = head->next;
		delete Temp;
	}
}
