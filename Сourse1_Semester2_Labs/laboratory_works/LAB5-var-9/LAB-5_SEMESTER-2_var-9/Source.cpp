#include <iostream>
#include <clocale>
using namespace std;

void PrintMatrix(int M[20][20], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << M[i][j] << '\t';
        }
        cout << '\n';
        cout << '\n';
    }
}

void PrintMass(int* m, int l) {
    int max = -2147483648;
    for (int i = 0; i < l; i++) {
        cout << m[i] << ' ';
        if (m[i] > max) {
            max = m[i];
        }
    }
    cout << "Max: " << max << '\n';

}

int CountSummDig(int M[][20], int n) {
    int s, max = -2147483648;    //max => минимальное возможное значение int чтоб точно не было ошибок
    int mmm[20]{};              //mmm[] => Суммы элементов в матрице s - временная, сумма элеметна (строки)
    for (int i = 1; i < n; i++) {
        s = 0;
        for (int j = 0; j < i; j++) {
            s += M[i][j];
            cout << M[i][j] << '\t';
        }
        cout << '\n';
        cout << '\n';
        mmm[i-1] = s;
        if (s > max) {
            max = s;
        }
    }
    
    return max;
}

int main() {
    setlocale(LC_ALL, "RU");

    int matrix[20][20];
    int n = 1, size;
    int MaxCounter[20]{};

    cout << "Введите размер Матрицы N : ";
    cin >> n;
    cout << "Введите количество матриц : ";
    cin >> size;

    for (int k = 0; k < size; k++) {

        cout << "=================================================\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = -50 + rand() % 100;
                cout << matrix[i][j] << '\t';
            }
            cout << '\n';
            cout << '\n';
        }

        cout << "==================================================\n";

        MaxCounter[k] = CountSummDig(matrix, n);
    }
    PrintMass(MaxCounter, size);
    return 0;
}