#include <iostream>
#include <clocale>
#include <vector>
#include "Class_A.h"

int main() {
	setlocale(LC_ALL, "RU");

	A something1;
	A* something2 = new A;
	std::vector <A> Array_Of_A{};

	something1 = make_A(50000.0, 15);
	something2->Read();

	double day_in_month_now = 30;

	something1.Show();
	std::cout << "Оклад 1: " << something1.summa(day_in_month_now) << '\n';
	something2->Show();
	std::cout << "Оклад 2: " << something2->summa(day_in_month_now) << '\n';

	int LEN;
	std::cout << "=====Массив данных класса А=====\n";
	std::cout << "Сколько элементов нужно ввести: ";
	std::cin >> LEN;

	for (int i = 0; i < LEN; i++) {
		A something;
		something.Read();
		Array_Of_A.push_back(something);
	}

	for (int i = 0; i < LEN; i++) {
		Array_Of_A[i].Show();
		std::cout << "Оклад " << (i+1) << ": " << Array_Of_A[i].summa(day_in_month_now) << '\n';
	}

	return 0;
}