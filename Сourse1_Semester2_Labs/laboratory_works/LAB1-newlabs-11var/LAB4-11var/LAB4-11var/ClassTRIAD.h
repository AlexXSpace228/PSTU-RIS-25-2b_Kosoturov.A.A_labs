#pragma once
#include <iostream>

class TRIAD {
protected:
	int first;
	int second;
	int third;
public:
	//конструкторы
	TRIAD(int a1, int a2, int a3) {
		first = a1;
		second = a2;
		third = a3;
	}
	TRIAD() {
		first = 0;
		second = 0;
		third = 0;
	}
	TRIAD(const TRIAD& other) {
		first = other.first;
		second = other.second;
		third = other.third;
	}

	// селекторы (геттеры)
	int getFirst()  const { return first; }
	int getSecond() const { return second; }
	int getThird()  const { return third; }

	// модификаторы (сеттеры)
	void setFirst(int a) { first = a; }
	void setSecond(int a) { second = a; }
	void setThird(int a) { third = a; }

	TRIAD& operator = (const TRIAD& T) {
		if (&T == this) return *this;
		first = T.first;
		second = T.second;
		third = T.third;
		return *this;
	}
	friend std::istream& operator>>(std::istream& in, TRIAD& p) {
		std::cout << "\nВведите поле first: ";
		in >> p.first;
		std::cout << "\nВведите поле second: ";
		in >> p.second;
		std::cout << "\nВведите поле third: ";
		in >> p.third;
		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, const  TRIAD& p) {
		out << p.first << '|';
		out << p.second << '|';
		out << p.third;
		return out;
	}

	virtual void plus_first_one() {
		first++;
	}

	virtual void plus_second_one() {
		second++;
	}

	virtual void plus_third_one() {
		third++;
	}

	virtual ~TRIAD() {};
};
