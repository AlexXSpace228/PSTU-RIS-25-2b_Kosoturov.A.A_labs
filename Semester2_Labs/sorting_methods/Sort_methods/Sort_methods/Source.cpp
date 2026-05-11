#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <clocale>
#include <limits>
#include "Header.h"

void PrintMass(int* m, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << m[i] << ' ';
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
static void VstavkaSORT(int* mass, const int n) {
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
static void bubbleSorter(int* m, const int n) {
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
static void ViborSort(int* m, int N) {
    for (int k = 0; k < N; k++) {
        int min = m[k];
        int j = k;
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
static int partitionHoare(int* arr, int low, int high) {
    int pivot = arr[low + (high - low) / 2];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do { i++; } while (arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);
        if (i >= j) return j;
        std::swap(arr[i], arr[j]);
    }
}

static void quickSortHoare(int* arr, int low, int high) {
    if (low < high) {
        int pI = partitionHoare(arr, low, high);
        quickSortHoare(arr, low, pI);
        quickSortHoare(arr, pI + 1, high);
    }
}

// =====5======
static void shellSort(int* arr, int size) {
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
static int partitionLomuto(int* arr, int low, int high) {
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

static void quickSortLomuto(int* arr, int low, int high) {
    if (low < high) {
        int p = partitionLomuto(arr, low, high);
        quickSortLomuto(arr, low, p - 1);
        quickSortLomuto(arr, p + 1, high);
    }
}

// =====7======
void Distribution(std::string path1, std::string path2, std::string main_path) {
    std::ofstream f1(path1), f2(path2);
    std::ifstream mainf(main_path);
    std::string temp, cur;
    int itemp, icur;

    if (!f1.is_open() || !f2.is_open()) {
        std::cout << "Error" << std::endl;
        return;
    }

    bool firstfile = true;
    if (mainf >> cur) {
        while (!mainf.eof()) {
            if (firstfile) {
                f1 << cur << '\n';
                temp = cur;
                if (!(mainf >> cur)) {
                    f1 << '/' << '\n';
                    return;
                }
                itemp = std::stoi(temp);
                icur = std::stoi(cur);
                while (itemp <= icur) {
                    f1 << cur << '\n';
                    temp = cur;
                    if (!(mainf >> cur)) {
                        f1 << '/' << '\n';
                        return;
                    }
                    itemp = std::stoi(temp);
                    icur = std::stoi(cur);
                }
                f1 << '/' << '\n';
                firstfile = false;
            }
            else {
                f2 << cur << '\n';
                temp = cur;
                if (!(mainf >> cur)) {
                    f2 << '/' << '\n';
                    return;
                }
                itemp = std::stoi(temp);
                icur = std::stoi(cur);
                while (itemp <= icur) {
                    f2 << cur << '\n';
                    temp = cur;
                    if (!(mainf >> cur)) {
                        f2 << '/' << '\n';
                        return;
                    }
                    itemp = std::stoi(temp);
                    icur = std::stoi(cur);
                }
                f2 << '/' << '\n';
                firstfile = true;
            }
        }
    }
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
int splitFile(int iterations) {
    std::ifstream A("A8.txt");
    std::ofstream B("B8.txt");
    std::ofstream C("C8.txt");

    int segments = 0;
    int counter = 0;
    bool writeToB = true;
    int current_elem;

    while (A >> current_elem) {
        if (counter == 0) segments++;

        if (writeToB) {
            B << current_elem << ' ';
        }
        else {
            C << current_elem << ' ';
        }

        counter++;
        if (counter == iterations) {
            counter = 0;
            writeToB = !writeToB;
        }
    }
    return segments;
}

int Merge1(int iterations) {
    std::ofstream A("A8.txt");
    std::ifstream B("B8.txt");
    std::ifstream C("C8.txt");

    int elementB, elementC;
    bool flagB = static_cast<bool>(B >> elementB);
    bool flagC = static_cast<bool>(C >> elementC);

    while (flagB || flagC) {
        int b_read = 0, c_read = 0;
        while (b_read < iterations && c_read < iterations && flagB && flagC) {
            if (elementB <= elementC) {
                A << elementB << ' ';
                flagB = static_cast<bool>(B >> elementB);
                b_read++;
            }
            else {
                A << elementC << ' ';
                flagC = static_cast<bool>(C >> elementC);
                c_read++;
            }
        }
        while (b_read < iterations && flagB) {
            A << elementB << ' ';
            flagB = static_cast<bool>(B >> elementB);
            b_read++;
        }
        while (c_read < iterations && flagC) {
            A << elementC << ' ';
            flagC = static_cast<bool>(C >> elementC);
            c_read++;
        }
    }

    return iterations * 2;
}

// =====9 Многофазная сортировка======
void upperFib(int n, int& a, int& b) {
    while (a + b < n) {
        int temp = a;
        a = a + b;
        b = temp;
    }
}

int countSeries(std::fstream& A) {
    A.close(); A.open("A.txt", std::ios::in);
    long long INF = 1000000000000000000LL;
    int current_elem, ret = 0;
    long long last = -INF;
    bool flagRead = static_cast<bool>(A >> current_elem);
    while (flagRead) {
        while (flagRead && current_elem >= last) {
            last = current_elem;
            flagRead = static_cast<bool>(A >> current_elem);
        }
        last = -INF;
        ret++;
    }
    return ret;
}

void splitFilePoly(std::fstream& A, std::fstream& B, std::fstream& C, int first) {
    long long INF = 1000000000000000000LL;
    int counter = 0;
    bool flag = true;
    A.close(); A.open("A.txt", std::ios::in);
    B.close(); B.open("B.txt", std::ios::out);
    C.close(); C.open("C.txt", std::ios::out);
    int current_elem;
    long long last = -INF;
    bool flagRead = static_cast<bool>(A >> current_elem);
    while (flagRead) {
        if (counter == first && first != 0) {
            first = 0;
            counter = 0;
            flag = !flag;
        }
        if (flag) {
            while (flagRead && current_elem >= last) {
                last = current_elem;
                B << current_elem << ' ';
                flagRead = static_cast<bool>(A >> current_elem);
            }
            last = -INF;
            B << '/' << ' ';
        }
        else {
            while (flagRead && current_elem >= last) {
                last = current_elem;
                C << current_elem << ' ';
                flagRead = static_cast<bool>(A >> current_elem);
            }
            last = -INF;
            C << '/' << ' ';
        }
        counter++;
    }
}

std::streampos MergePoly(std::fstream& A, std::fstream& B, std::fstream& C, std::string& big, std::string& lower, std::string& empty, int& a, int& b, int real_b, std::streampos s) {
    A.close(); B.close(); C.close();
    A.open(empty, std::ios::out);
    B.open(big, std::ios::in);
    C.open(lower, std::ios::in);
    C.seekg(s);
    std::string elementB, elementC;
    bool flagB;
    bool flagC;
    int count = 0;
    bool flagEnd = false;
    while (count < real_b && !flagEnd) {
        flagB = static_cast<bool>(B >> elementB);
        flagC = static_cast<bool>(C >> elementC);
        if (!flagB && !flagC) {
            flagEnd = true;
        }
        while ((flagB && elementB != "/") || (flagC && elementC != "/")) {
            int current_elem = 0;
            bool flag = false;
            if (!flagB || elementB == "/") {
                current_elem = std::stoi(elementC);
            }
            else if (!flagC || elementC == "/") {
                current_elem = std::stoi(elementB);
                flag = true;
            }
            else {
                if (std::stoi(elementB) < std::stoi(elementC)) {
                    current_elem = std::stoi(elementB);
                    flag = true;
                }
                else {
                    current_elem = std::stoi(elementC);
                }
            }
            if (!flagEnd) {
                A << current_elem << ' ';
                if (flag) {
                    flagB = static_cast<bool>(B >> elementB);
                }
                else {
                    flagC = static_cast<bool>(C >> elementC);
                }
            }
        }
        A << '/' << ' ';
        count++;
    }
    int temp = a;
    a = b;
    b = temp - b;
    std::string temp_name = big;
    big = empty;
    empty = lower;
    lower = temp_name;

    return B.tellg();
}


int* MASSINPUTRAND(int& n) {
    std::cout << "Введите размер массива: ";
    std::cin >> n;
    if (n <= 0) return nullptr;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1500;
    }
    return arr;
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "RU");

    int len;
    int* mass = nullptr;
    int a_menu;

    do {
        std::cout << "======= Методы сортировки =======\n"
            << "\t1 - Вставкой\n\t2 - Пузырьком\n\t3 - Выбором\n\t4 - Хоара\n"
            << "\t5 - Шелл\n\t6 - Ломуто\n\t7 - Внешняя сортировка (слиянием)\n"
            << "\t8 - Внешняя сортировка (split/merge)\n\t9 - Многофазная сортировка\n"
            << "\t0 - выход\n=================================\n";

        if (!(std::cin >> a_menu)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка: нужно ввести число\n";
            continue;
        }

        switch (a_menu) {
        case 1: {
            mass = MASSINPUTRAND(len);
            if (!mass) break;
            std::cout << "Изначальный массив: ";
            PrintMass(mass, len);
            VstavkaSORT(mass, len);
            std::cout << "Отсортированный массив: ";
            PrintMass(mass, len);
            delete[] mass;
            break;
        }
        case 2: {
            mass = MASSINPUTRAND(len);
            if (!mass) break;
            std::cout << "Изначальный массив: ";
            PrintMass(mass, len);
            bubbleSorter(mass, len);
            std::cout << "Отсортированный массив: ";
            PrintMass(mass, len);
            delete[] mass;
            break;
        }
        case 3: {
            mass = MASSINPUTRAND(len);
            if (!mass) break;
            std::cout << "Изначальный массив: ";
            PrintMass(mass, len);
            ViborSort(mass, len);
            std::cout << "Отсортированный массив: ";
            PrintMass(mass, len);
            delete[] mass;
            break;
        }
        case 4: {
            mass = MASSINPUTRAND(len);
            if (!mass) break;
            std::cout << "Изначальный массив: ";
            PrintMass(mass, len);
            quickSortHoare(mass, 0, len - 1);
            std::cout << "Отсортированный массив: ";
            PrintMass(mass, len);
            delete[] mass;
            break;
        }
        case 5: {
            mass = MASSINPUTRAND(len);
            if (!mass) break;
            std::cout << "Изначальный массив: ";
            PrintMass(mass, len);
            shellSort(mass, len);
            std::cout << "Отсортированный массив: ";
            PrintMass(mass, len);
            delete[] mass;
            break;
        }
        case 6: {
            mass = MASSINPUTRAND(len);
            if (!mass) break;
            std::cout << "Изначальный массив: ";
            PrintMass(mass, len);
            quickSortLomuto(mass, 0, len - 1);
            std::cout << "Отсортированный массив: ";
            PrintMass(mass, len);
            delete[] mass;
            break;
        }
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
        case 8: {
            int n;
            std::cout << "Введите количество элементов: ";
            std::cin >> n;

            std::ofstream A("A8.txt");
            for (int i = 0; i < n; ++i) {
                A << rand() % 101 << ' ';
            }
            A.close();

            int iterations = 1;
            int segments = 0;

            do {
                segments = splitFile(iterations);
                if (segments > 1) {
                    iterations = Merge1(iterations);
                }
            } while (segments > 1);

            std::cout << "Готово. Отсортированные данные находятся в файле A8.txt\n";
            break;
        }
        case 9: {
            int n;
            std::cout << "Введите количество элементов: ";
            std::cin >> n;
            if (n <= 0) break;

            std::fstream A, B, C;
            A.open("A.txt", std::ios::out);
            for (int i = 0; i < n; ++i) {
                int elem = rand() % 101;
                std::cout << elem << ' ';
                A << elem << ' ';
            }
            std::cout << '\n';
            A.close();

            int series = countSeries(A);
            int a = 1, b = 0;
            upperFib(series, a, b);

            int first = a - (a + b - series);
            splitFilePoly(A, B, C, first);

            std::string name1 = "B.txt", name2 = "C.txt", name3 = "A.txt";
            std::streampos s = 0;
            int real_b = -1;

            while (a != 1 || b != 0) {
                real_b = (real_b == -1 ? series - first : b);
                s = MergePoly(A, B, C, name1, name2, name3, a, b, real_b, s);
            }

            A.close(); B.close(); C.close();
            std::cout << "Многофазная сортировка завершена. Результат находится в файле " << name1 << "\n";
            break;
        }
        default:
            break;
        }
    } while (a_menu != 0);

    return 0;
}