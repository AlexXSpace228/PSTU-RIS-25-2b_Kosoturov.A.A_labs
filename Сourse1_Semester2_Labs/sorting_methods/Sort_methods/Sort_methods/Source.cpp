#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ctime>
#include <clocale>
#include <limits>
#include "Header.h"

void PrintMass(int* m, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << m[i] << ' ';
    }
}

void PrintMASSVector(const std::vector <int>& M) {
    for (size_t i = 0; i < M.size(); i++) {
        std::cout << M[i] << ' ';
        std::cout << ' ';
    }
    std::cout << '\n';
}

void GenerateFile(const std::string& path, int n) {
    std::ofstream f(path);
    for (int i = 0; i < n; i++) {
        f << rand() % 1000 << "\n";
    }
    f.close();
}

// =====1======
static void VstavkaSORT(std::vector <int>& mass, const int& n) {
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

// =====2======
static void bubbleSorter(std::vector <int>& m, const int& n) {
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

// =====3======
static void ViborSort(std::vector <int>& m, int N) {
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

// =====4======
static int partitionHoare(std::vector <int>& arr, int low, int high) {
    int pivot = arr[low + (high - low) / 2];
    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        do { i++; } while (arr[i] < pivot);

        do { j--; } while (arr[j] > pivot);

        if (i >= j) return j;

        std::swap(arr[i], arr[j]);
    }
}

static void quickSortHoare(std::vector <int>& arr, int low, int high)
{
    if (low < high)
    {
        int pI = partitionHoare(arr, low, high);

        quickSortHoare(arr, low, pI);
        quickSortHoare(arr, pI + 1, high);
    }
}
// =====5======
static void shellSort(std::vector <int>& arr, int size) {

    for (int step = size / 2; step > 0; step /= 2) {
        for (int i = step; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= step && arr[j - step] > temp; j -= step) {
                arr[j] = arr[j - step];
            }
            arr[j] = temp;
        }
    }
}
// =====6======
static int partitionLomuto(std::vector <int>& arr, int low, int high) {
    int pI = high;
    int pivot = arr[pI];
    for (int j = low; j < pI; j++) {
        if (arr[j] > pivot) {
            std::swap(arr[pI - 1], arr[j]);
            std::swap(arr[pI], arr[pI - 1]);

            pI--;
            j--;
        }
    }
    return pI;
}

// =====7======

void Distribution(std::string path1, std::string path2, std::string main_path) {
    std::ofstream f1, f2;
    std::ifstream mainf;
    std::string temp, cur;
    int itemp, icur;
    f1.open(path1);
    f2.open(path2);
    mainf.open(main_path);
    if (!f1.is_open() || !f2.is_open()) {
        std::cout << "Error" << std::endl;
    }
    else {
        bool firstfile = true;
        mainf >> cur;
        while (!mainf.eof()) {
            if (firstfile) {
                f1 << cur << '\n';
                temp = cur;
                mainf >> cur;
                if (mainf.eof()) {
                    f1 << '/' << '\n';
                    return;
                }
                itemp = stoi(temp);
                icur = stoi(cur);
                while (itemp <= icur) {
                    if (mainf.eof()) {
                        f1 << '/' << '\n';
                        return;
                    }
                    f1 << cur << '\n';
                    temp = cur;
                    mainf >> cur;
                    itemp = stoi(temp);
                    icur = stoi(cur);
                }
                f1 << '/' << '\n';
                firstfile = false;
            }
            else {
                f2 << cur << '\n';
                temp = cur;
                mainf >> cur;
                if (mainf.eof()) {
                    f2 << '/' << '\n';
                    return;
                }
                itemp = stoi(temp);
                icur = stoi(cur);
                while (itemp <= icur) {
                    if (mainf.eof()) {
                        f2 << '/' << '\n';
                    }
                    f2 << cur << '\n';
                    temp = cur;
                    mainf >> cur;
                    itemp = stoi(temp);
                    icur = stoi(cur);
                }
                f2 << '/' << '\n';
                firstfile = true;
            }
        }
    }
    f1.close();
    f2.close();
    mainf.close();
}

void Merge(std::string path1, std::string path2, std::string main_path) {
    std::ifstream f1(path1), f2(path2);
    std::ofstream mainf(main_path);

    std::string t1, t2;

    f1 >> t1;
    f2 >> t2;

    while (!f1.eof() || !f2.eof()) {

        while (t1 != "/" && t2 != "/") {
            int a = stoi(t1);
            int b = stoi(t2);

            if (a <= b) {
                mainf << a << "\n";
                if (!(f1 >> t1)) break;
            }
            else {
                mainf << b << "\n";
                if (!(f2 >> t2)) break;
            }
        }

        while (t1 != "/" && !f1.eof()) {
            mainf << t1 << "\n";
            if (!(f1 >> t1)) break;
        }

        while (t2 != "/" && !f2.eof()) {
            mainf << t2 << "\n";
            if (!(f2 >> t2)) break;
        }

        if (!f1.eof()) f1 >> t1;
        if (!f2.eof()) f2 >> t2;
    }
}

void MergeSortExternal(std::string path1, std::string path2, std::string main_path) {
    while (true) {
        Distribution(path1, path2, main_path);

        std::ifstream test(path2);
        if (test.peek() == EOF) break;

        test.close();

        Merge(path1, path2, main_path);
    }
}


// =====8======

/*
int splitFile(fstream& A, fstream& B, fstream& C, int iterations) {
    int segments = 1;
    int counter = 0;
    bool flag = true;

    A.close(); A.open("A.txt", ios::in);
    B.close(); B.open("B.txt", ios::out);
    C.close(); C.open("C.txt", ios::out);

    int current_elem;
    while (A >> current_elem) {
        if (counter == iterations) {
            counter = 0;
            flag = !flag;
            segments++;
        }

        if (flag) {
            B << current_elem << ' ';
        }
        else {
            C << current_elem << ' ';
        }
        counter++;
    }
    return segments;
}

int Merge1(fstream& A, fstream& B, fstream& C, int iterations) {
    A.close(); A.open("A.txt", ios::out);
    B.close(); B.open("B.txt", ios::in);
    C.close(); C.open("C.txt", ios::in);

    int counterB = 0, counterC = 0;
    int elementB, elementC;
    bool flagEnd = false;

    bool flagB = static_cast<bool>(B >> elementB);
    bool flagC = static_cast<bool>(C >> elementC);

    while (!flagEnd) {
        int current_elem;
        bool flag = false;

        if (!flagB && !flagC) {
            flagEnd = true;
        }
        else if (!flagB || counterB == iterations) {
            current_elem = elementC;
        }
        else if (!flagC || counterC == iterations) {
            current_elem = elementB;
            flag = true;
        }
        else {
            if (elementB < elementC) {
                current_elem = elementB;
                flag = true;
            }
            else {
                current_elem = elementC;
            }
        }

        if (!flagEnd) {
            A << current_elem << ' ';
            if (flag) {
                counterB++;
                flagB = static_cast<bool>(B >> elementB);
            }
            else {
                counterC++;
                flagC = static_cast<bool>(C >> elementC);
            }

            if (counterB == iterations && counterC == iterations) {
                counterB = 0;
                counterC = 0;
            }
        }
    }

    iterations *= 2;
    return iterations;
}*/

static void MASSINPUTRAND(std::vector <int>& arr) {
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        arr.push_back((rand())%1500);
    }
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "RU");
    //system("color E0");

    int len;
    std::vector <int> mass;

    int a;
    do {
        std::cout << "======= Методы сортировки =======\n\t1 - Вставкой\n\t2 - Пузырьком\n\t3 - Выбором\n\t4 - Хоара\n\t5 - Шелл\n\t6 - Ломуто\n\t7 - Внешняя сортировка(слиянием)\n\t0 - выход\n=================================\n";
        if (!(std::cin >> a)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка: нужно ввести число\n";
            continue;
        }
        switch (a) {
        case 1:
            MASSINPUTRAND(mass);
            len = mass.size();
            std::cout << "Изначальный массив: ";
            PrintMASSVector(mass);
            VstavkaSORT(mass, len);
            std::cout << "Отсортированный массив: ";
            PrintMASSVector(mass);
            mass.clear();
            break;
        case 2:
            MASSINPUTRAND(mass);
            len = mass.size();
            std::cout << "Изначальный массив: ";
            PrintMASSVector(mass);
            bubbleSorter(mass, len);
            std::cout << "Отсортированный массив: ";
            PrintMASSVector(mass);
            mass.clear();
            break;
        case 3:
            MASSINPUTRAND(mass);
            len = mass.size();
            std::cout << "Изначальный массив: ";
            PrintMASSVector(mass);
            ViborSort(mass, len);
            std::cout << "Отсортированный массив: ";
            PrintMASSVector(mass);
            mass.clear();
            break;
        case 4:
            MASSINPUTRAND(mass);
            len = mass.size();
            std::cout << "Изначальный массив: ";
            PrintMASSVector(mass);
            quickSortHoare(mass,0,len-1);
            std::cout << "Отсортированный массив: ";
            PrintMASSVector(mass);
            mass.clear();
            break;
        case 5:
            MASSINPUTRAND(mass);
            len = mass.size();
            std::cout << "Изначальный массив: ";
            PrintMASSVector(mass);
            shellSort(mass, len);
            std::cout << "Отсортированный массив: ";
            PrintMASSVector(mass);
            mass.clear();
            break;
        case 6:
            MASSINPUTRAND(mass);
            len = mass.size();
            std::cout << "Изначальный массив: ";
            PrintMASSVector(mass);
            partitionLomuto(mass, 0, len - 1);
            std::cout << "Отсортированный массив: ";
            PrintMASSVector(mass);
            mass.clear();
            break;
        case 7: {
            std::string main_path = "main.txt";
            std::string f1 = "f1.txt";
            std::string f2 = "f2.txt";

            int n;
            std::cout << "Введите количество элементов: ";
            std::cin >> n;

            GenerateFile(main_path, n);

            std::cout << "Исходный файл создан.\n";

            MergeSortExternal(f1, f2, main_path);

            std::cout << "Сортировка завершена. Результат в main.txt\n";
            break;
        }
        default:
            break;
        }
    } while (a != 0);
    return 0;
}