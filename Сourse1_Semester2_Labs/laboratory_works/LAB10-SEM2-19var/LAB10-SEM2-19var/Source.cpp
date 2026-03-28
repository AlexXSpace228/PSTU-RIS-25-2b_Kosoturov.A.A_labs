#include <iostream>
#include <clocale>
#include <string>
using namespace std;

static string* make_array(int n) {
	string* arr = new string[n];
	cin.ignore();
	for (int i = 0; i < n; i++) {
		cout << "¬ведите строку " << i + 1 << ": ";
		getline(cin, arr[i]);
	}

	return arr;
}

static void Printarr(string* m, int n1) {
	for (int i = 0; i < n1; i++) {
		std::cout << m[i] << '\n';
	}
}

static string* Remover(string* m, int& n) {
	for (int i = 0; i < n; i++) {
		if (!m[i].empty() && m[i][0] == 'a' && m[i][m[i].size() - 1] == 'a') {
			for (int k = i; k < n-1; k++) {
				string temp = m[k];
				m[k] = m[k+1];
				m[k+1] = temp;
			}
			n--;
			i--;
		}
	}
	string* Newarr = new string[n];

	for (int i = 0; i < n; i++) {
		Newarr[i] = m[i];
	}
	delete[] m;

	return Newarr;
}

int main() {
	setlocale(LC_ALL, "RU");
;	int N;
	cout << "¬ведите размер массива строк: ";
	cin >> N;
	string* mtrx = make_array(N);
	cout << "------------------>\n";
	string* NEWmtrx = Remover(mtrx, N);
	Printarr(NEWmtrx, N);
	return 0;
}