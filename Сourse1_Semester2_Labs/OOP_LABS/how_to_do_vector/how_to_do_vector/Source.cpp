#include <iostream>
#include <vector>

template <typename T>

void PrintVector(std::vector <T> arr) {
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " - ";
	}
	std::cout << '\n';
}

int main() {
	setlocale(LC_ALL, "ru");

	std::vector <int> myVector; // создание массива вектор

	myVector.push_back(9); // добавление элемента в конец
	myVector.push_back(8);
	myVector.push_back(7);

	std::cout << "Количество элемментов в масиве: " << myVector.size() << '\n';

	PrintVector(myVector);

	myVector.emplace_back(30); //Тоже добавляет в конец, но объект создается сразу внутри vector.
	std::cout << "myVector emplace_back\n";
	PrintVector(myVector);

	myVector.pop_back();
	std::cout << "myVector pop_back\n";
	PrintVector(myVector);

	std::cout << "myVector erase\n";
	myVector.erase(myVector.begin()); //Удалит первый элемент.
	PrintVector(myVector);


	myVector.push_back(8);
	myVector.push_back(7);
	myVector.erase(myVector.begin(), myVector.begin()+1);//Удаление диапазона:
	PrintVector(myVector);

	if (!myVector.empty()) {
		std::cout << "Вектор не пустой\n";
	}

	if (myVector.at(0)) {
		std::cout << "по индексу 9 нет элемента\n";
	}

 	return 0;
}