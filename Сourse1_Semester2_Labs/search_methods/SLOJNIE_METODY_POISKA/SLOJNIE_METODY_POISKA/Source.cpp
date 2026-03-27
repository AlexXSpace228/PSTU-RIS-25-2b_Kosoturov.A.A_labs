#include <iostream>
#include <string>
#include <clocale>
#include <limits>
#include <vector>
#define NOMINMAX
#include <windows.h>

int maxx(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int LINEsearch(int* arr, int size, int key) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == key) {
			return i;
		}
	}
	return -1;
}

int BINsearch(int* arr, int n, int key)
{
	bool flag = false;
	int l = 0;
	int r = n - 1;
	int mid = -1;

	while ((l <= r) && (!flag))
	{
		mid = (l + r) / 2;

		if (arr[mid] == key)
			flag = true;
		else if (arr[mid] > key)
			r = mid - 1;
		else
			l = mid + 1;
	}

	return (flag) ? mid : -1;
}
int interpolsearch(int* arr, int size, int key)
{
	int left = 0;
	int right = size - 1;

	while (left <= right && key >= arr[left] && key <= arr[right])
	{
		if (arr[left] == arr[right]) {
			if (arr[left] == key) return left;
			else return -1;
		}

		int mid = left + ((key - arr[left]) * (right - left)) / (arr[right] - arr[left]);

		if (mid < left || mid > right)
			break;

		if (arr[mid] < key)
			left = mid + 1;
		else if (arr[mid] > key)
			right = mid - 1;
		else
			return mid;
	}

	return -1;
}

int STRINGsearchKEY(std::string str, std::string substr)
{
	int strl = str.size();
	int substrl = substr.size();
	int res = -1;

	if (strl != 0 && substrl != 0)
	{
		for (int i = 0; i <= strl - substrl; i++)
		{
			bool match = true;
			for (int j = 0; j < substrl; j++)
			{
				if (substr[j] != str[i + j])
				{
					match = false;
					break;
				}
			}

			if (match)
			{
				res = i;
				break;
			}
		}
	}
	return res;
}

int boyerMooreSearch(std::string text, std::string pattern) {

	int textLen = text.length();
	const int patternLen = pattern.length();
	if (textLen == 0 || patternLen == 0) return -1;
	if (patternLen > textLen) return -1;
	int CharTable[256];
	std::vector<int> goodSuffix(patternLen);

	for (int i = 0; i < 256; i++) {
		CharTable[i] = patternLen;
	}
	for (int i = 0; i < patternLen - 1; i++) {
		CharTable[(unsigned char)pattern[i]] = patternLen - 1 - i;
	}

	int pos = patternLen - 1;

	while (pos < textLen) {
		int j = patternLen - 1;
		int k = pos;

		while (j >= 0 && text[k] == pattern[j]) {
			k--;
			j--;
		}

		if (j < 0) {
			return k + 1;
		}
		else {
			int badCharShift = CharTable[(unsigned char)text[k]];
			int goodSuffixShift = goodSuffix[j];
			pos += maxx(badCharShift, goodSuffixShift);
		}
	}

	return -1;
}

int horspoolSearch(std::string text, std::string pattern) {
	int textLen = text.length();
	int patternLen = pattern.length();

	if (patternLen == 0 || textLen == 0 || patternLen > textLen) {
		return -1;
	}

	int shiftTable[256];

	for (int i = 0; i < 256; i++) {
		shiftTable[i] = patternLen;
	}

	for (int i = 0; i < patternLen - 1; i++) {
		shiftTable[(unsigned char)pattern[i]] = patternLen - 1 - i;
	}

	int pos = 0;

	while (pos <= textLen - patternLen) {
		int j = patternLen - 1;
		while (j >= 0 && pattern[j] == text[pos + j]) {
			j--;
		}

		if (j == -1) {
			return pos;
		}
		unsigned char lastCharInWindow = (unsigned char)text[pos + patternLen - 1];
		pos += shiftTable[lastCharInWindow];
	}

	return -1;
}

void PrintMass(int* m, int l) {
	for (int i = 0; i < l; i++) {
		std::cout << m[i] << ' ';
	}
	std::cout << std::endl;
}

void SORTARR(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int k = i; k < size - 1; k++) {
			if (arr[i] > arr[k + 1]) {
				int temp = arr[i];
				arr[i] = arr[k + 1];
				arr[k + 1] = temp;
			}
		}
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int a;
	const int LEN = 15;
	std::string S;
	std::string key;
	int ARR[LEN]{9,12,0,0,1,10,10,5,6,9,1,1,3,5,9};
	int ARRforSort[LEN]{ 9,12,0,0,1,10,10,5,6,9,1,1,3,5,9 };
	SORTARR(ARRforSort, LEN);
	int ky;
	do {
		std::cout << "=================================\n1 - Линейный\n2 - Бинарный\n3 - Интерполяционный\n4 - Прямой поиск подстроки в строке\n5 - Алгоритм Бойера-Мура\n6 - Алгоритм Бойера-Мура-Хорспула\n=================================\n";
		if (!(std::cin >> a)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Ошибка: нужно ввести число\n";
			continue;
		}
		switch (a)
		{
		case 1:
			std::cout << "\nВведите число (ключ поиска) int: ";
			if (!(std::cin >> ky)) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Ошибка: нужно ввести число\n";
				continue;
			}

			std::cout << "Индекс элемента: " << LINEsearch(ARR, LEN, ky) << " в списке: ";

			PrintMass(ARR, LEN);

			break;
		case 2:
			std::cout << "\nВведите число (ключ поиска) int: ";
			if (!(std::cin >> ky)) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Ошибка: нужно ввести число\n";
				continue;
			}
			std::cout << "Для работы список должен быть отсортирован!\n";
			std::cout << "Индекс элемента: " << BINsearch(ARRforSort, LEN, ky) << " в списке: ";

			PrintMass(ARR, LEN);

			break;
		case 3:
			std::cout << "\nВведите число (ключ поиска) int: ";
			if (!(std::cin >> ky)) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Ошибка: нужно ввести число\n";
				continue;
			}

			std::cout << "Для работы список должен быть отсортирован!\n";
			std::cout << "Индекс элемента: " << interpolsearch(ARRforSort, LEN, ky) << " в списке: ";

			PrintMass(ARRforSort, LEN);

			break;
		case 4:
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Введите строку: ";
			getline(std::cin, S);

			std::cout << "Введите ключ для поиска: ";
			getline(std::cin, key);

			std::cout << "Индекс ключа в строке: " << STRINGsearchKEY(S, key) << std::endl;
			break;
		case 5:
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Введите строку: ";
			getline(std::cin, S);

			std::cout << "Введите ключ для поиска: ";
			getline(std::cin, key);

			std::cout << "Индекс ключа в строке: " << boyerMooreSearch(S, key) << std::endl;
			break;
		case 6:
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Введите строку: ";
			getline(std::cin, S);

			std::cout << "Введите ключ для поиска: ";
			getline(std::cin, key);

			std::cout << "Индекс ключа в строке: " << horspoolSearch(S, key) << std::endl;
			break;
		default:
			break;
		}
	} while (a != 0);

	return 0;
}