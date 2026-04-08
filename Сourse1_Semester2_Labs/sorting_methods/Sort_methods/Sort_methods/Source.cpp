#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ctime>
#include <clocale>
#include <limits>

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
static void VSort(std::vector <int>& m, int N) {
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

void Distribution(std::string path1, std::string path2, std::string main_path) {
    std::ofstream f1, f2;
    std::ifstream mainf;
    std::string temp, cur;
    int itemp, icur;
    f1.open(path1);
    f2.open(path2);
    mainf.open(main_path);
    if (!f1.is_open() || !f2.is_open()) { std::cout << "Error" << std::endl; }
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
    Distribution(path1, path2, main_path);
    std::ifstream f1, f2;
    std::ofstream mainf;
    std::string temp1, temp2;
    int itemp1, itemp2;
    f1.open(path1);
    f2.open(path2);
    mainf.open(main_path);
    if (!f1.is_open() || !f2.is_open()) { std::cout << "Error" << std::endl; }
    else {
        int i = 0, j = 0;
        while (!(f1.eof())) {
            f1 >> temp1;
            f2 >> temp2;
            if (temp2 == "") return;
            while (temp1 != "/" || temp2 != "/") {
                if (temp1 == "/") {
                    mainf << temp2 << "\n";
                    f2 >> temp2;
                }
                else if (temp2 == "/") {
                    mainf << temp1 << "\n";
                    f1 >> temp1;
                }
                else {
                    itemp1 = stoi(temp1);
                    itemp2 = stoi(temp2);
                    if (itemp1 <= itemp2) {
                        mainf << temp1 << "\n";
                        f1 >> temp1;
                    }
                    else {
                        mainf << temp2 << "\n";
                        f2 >> temp2;
                    }
                }
            }
        }
    }
    f1.close();
    f2.close();
    mainf.close();
    Merge(path1, path2, main_path);
}

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
    system("color E0");

    int len;
    std::vector <int> mass;

    int a;
    do {
        std::cout << "======= Методы сортировки =======\n\t1 - Вставкой\n\t2 - Пузырьком\n\t3 - Выбором\n\t4 - Хоара\n\t5 - Шелл\n\t6 - Ломуто\n\t0 - выход\n=================================\n";
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
            VSort(mass, len);
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
        default:
            break;
        }
    } while (a != 0);
    return 0;
}