#pragma once
#include <iostream>
#include <cstdlib>

class A {
private:
	double first; // оклад
	int second; // количество отработанных дней
public:
	// конструктор
	A() = default;

	void Read() {
		double f;
		int s;
		do {
			std::cout << "Введите оклад и дни: ";
			std::cin >> f >> s;
		} while (!Init(f, s)); // Повторяем, пока не введут корректно
	}

	bool Init(double f, int s) {
		if (f < 0.0 || s < 0) {
			return false;
		}
		first = f;
		second = s;
		return true;
	}

	void Show() const{
		std::cout << "============= КЛАСС А =============\n";
		std::cout << "оклад: " << first << '\n';
		std::cout << "количество отработанных дней : " << second << '\n';
	}

	int summa(int day_in_month) const {
		if (day_in_month == 0) return 0;
		return first / day_in_month  * second;
	}
};

A make_A(double f, int s) {
	A obj;
	if (!obj.Init(f, s)) {
		std::cout << "Ошибка: неверные параметры для создания объекта!" << std::endl;
		exit(1);
	}
	return obj;
}