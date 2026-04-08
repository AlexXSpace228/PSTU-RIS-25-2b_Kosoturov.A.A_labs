#include <iostream>
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