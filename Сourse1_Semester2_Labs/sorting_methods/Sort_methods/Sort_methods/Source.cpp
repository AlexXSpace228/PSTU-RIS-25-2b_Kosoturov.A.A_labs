#include <iostream>
#include <cstdlib>


void PrintMass(int* m, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << m[i] << ' ';
    }
    std::cout << '\n';
}

void VstavkaSORT(int* mass, const int& n) {
    for (int i = 1; i < n; ++i) {
        int t = mass[i];
        int j = i - 1;
        while (j >= 0 && mass[j] > t) {
            mass[j + 1] = mass[j];
            --j;
        }
        mass[j + 1] = t;
    }
}

void bubbleSorter(int* m, const int& n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (m[j] > m[j + 1]) {
                int temp = m[j];
                m[j] = m[j + 1];
                m[j + 1] = temp;
            }
        }
    }
}

void VSort(int* m, int N) {
    for (int k = 0; k < N; k++) {

        int min = m[k];
        int j = 0;
        for (int i = k + 1; i < N; i++) {
            if (m[i] < min) {
                min = m[i];
                j = i;
            }
        }

        if (min != m[k]) {
            int Pint = m[k];
            m[k] = min;
            m[j] = Pint;
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");


    int mass[100];
    int n;


    std::cout << "Введите размер массива: ";
    std::cin >> n;
    std::cout << "Введите массив: \n";
    for (int i = 0; i < n; i++) {
        std::cin >> mass[i];
    }
    bubbleSorter(mass, n);
    std::cout << "Отсортированный массив: \n";
    PrintMass(mass, n);
    return 0;
}