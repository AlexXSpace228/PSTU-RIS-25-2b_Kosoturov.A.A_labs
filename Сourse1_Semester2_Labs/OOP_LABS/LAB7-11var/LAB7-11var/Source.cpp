#include <iostream>
#include <string>
#include "LIST.h"
#include "moneyr.h"

using namespace std;

int main() {

	setlocale(LC_ALL, "ru");

	try {
		cout << "--------------------------------------------------" << endl;
		cout << "ЭТАП 1: ТЕСТИРОВАНИЕ СТАНДАРТНОГО ТИПА (INT)" << endl;
		cout << "--------------------------------------------------" << endl;


		LIST<int> intList1(3, 10);
		cout << "Список 1 (int): " << intList1 << endl;

		LIST<int> intList2(3, 0);
		cout << "Введите 3 целых числа для Списка 2:" << endl;
		cin >> intList2;
		cout << "Список 2 (int): " << intList2 << endl;

		LIST<int> intListSum = intList1 + intList2;
		cout << "Результат сложения (Список 1 + Список 2): " << intListSum << endl;

		cout << "Элемент Списка 1 по индексу 1: " << intList1[1] << endl;
		intList1[1] = 100; // изменение значения
		cout << "Список 1 после изменения intList1[1] = 100: " << intList1 << endl;

		cout << "Размер Списка 1: " << (int)intList1 << endl;

		LIST<int> intListCopy = intList1;
		cout << "Копия Списка 1 (констр. копир.): " << intListCopy << endl;


		cout << "\n--------------------------------------------------" << endl;
		cout << "ЭТАП 2: ТЕСТИРОВАНИЕ ПОЛЬЗОВАТЕЛЬСКОГО КЛАССА (MONEY)" << endl;
		cout << "--------------------------------------------------" << endl;

		Money m1(10, 50);
		Money m2(5, 75);

		LIST<Money> moneyList1(2, m1);
		LIST<Money> moneyList2(2, m2);

		cout << "Список Money 1: " << moneyList1 << endl;
		cout << "Список Money 2: " << moneyList2 << endl;

		LIST<Money> moneyListSum = moneyList1 + moneyList2;
		cout << "Результат сложения Money (поэлементно): " << moneyListSum << endl;

		LIST<Money> moneyListInput(1, Money(0, 0));
		cout << "\nВведите данные для одного объекта Money:" << endl;
		cin >> moneyListInput;
		cout << "Ваш список Money: " << moneyListInput << endl;

		cout << "\nПроверка итератора (вывод элементов списка Money):" << endl;
		for (auto it = moneyListSum.begin(); it != moneyListSum.end(); ++it) {
			cout << "[" << *it << "] ";
		}
		cout << endl;

		cout << "\nПроверка исключения (попытка доступа к индексу 100):" << endl;
		cout << moneyListSum[100] << endl;

	}
	catch (const std::out_of_range& e) {
		cerr << "Ошибка индекса: " << e.what() << endl;
	}
	catch (const std::length_error& e) {
		cerr << "Ошибка размера: " << e.what() << endl;
	}
	catch (const std::exception& e) {
		cerr << "Произошла ошибка: " << e.what() << endl;
	}

	return 0;
}