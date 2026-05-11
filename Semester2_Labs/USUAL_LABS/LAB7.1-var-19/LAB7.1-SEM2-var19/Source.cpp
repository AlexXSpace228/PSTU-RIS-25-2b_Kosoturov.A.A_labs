#include <iostream>
#include <clocale>
#include <string>
using namespace std;

int Mnn(int* arr, int n) { //arr - массив n - его длина
	int Max = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > Max) { Max = arr[i]; }
	}
	return Max;
}

int Mnn(string s) {
	s += ' ';
	int i = 0, lenS, minL = s.length();
	while (i != s.length()) {
		lenS = 0;
		while (s[i] != ' ') {
			lenS++;
			i++;
		}
		if (lenS < minL) {
			minL = lenS;
		}
		i++;
	}
	return minL;
}

int main() {
	setlocale(LC_ALL, "RU");

	int mass[10]{ 4,5965,2,69,999,89,8,0,1,4 };

	cout << "Максимальный элемент массива: " << Mnn(mass, 10) << '\n';

	string str = "sdf eeeee sdfdf epst s pop aapappap";

	cout << "Длинна самого короткого слова: " << Mnn(str);

	return 0;
}