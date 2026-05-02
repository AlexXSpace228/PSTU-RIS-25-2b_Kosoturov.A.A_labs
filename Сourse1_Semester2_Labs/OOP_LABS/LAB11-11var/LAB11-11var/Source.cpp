#include <iostream>
#include <vector>
#include "queue.h"
#include "List.h"
#include "Money.h"

using namespace std;

typedef vector<float> Vec;

// ввод
Vec make_vector(int n) {
    Vec v;
    for (int i = 0; i < n; i++) {
        float x;
        cin >> x;
        v.push_back(x);
    }
    return v;
}

// вывод
void print(Vec v) {
    for (float x : v) cout << x << " ";
    cout << endl;
}

// среднее
float srednee(Vec v) {
    float s = 0;
    for (float x : v) s += x;
    return s / v.size();
}

// добавить в начало
void add_begin(Vec& v, float x) {
    v.insert(v.begin(), x);
}

// удалить по ключу
void delete_by_key(Vec& v, float key) {
    for (auto it = v.begin(); it != v.end(); ) {
        if (*it == key) it = v.erase(it);
        else ++it;
    }
}

// минимум
float get_min(Vec v) {
    float m = v[0];
    for (float x : v) if (x < m) m = x;
    return m;
}

// вычитание минимума
void subtract_min(Vec& v) {
    float m = get_min(v);
    for (float& x : v) x -= m;
}

template<class T>
class ListQ {
    Queue<T> q;

public:
    ListQ(int n) {
        T x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            q.push(x);
        }
    }

    vector<T> to_vector() {
        vector<T> v;
        Queue<T> temp = q;
        while (!temp.empty()) {
            v.push_back(temp.front());
            temp.pop();
        }
        return v;
    }

    void from_vector(vector<T> v) {
        q = Queue<T>();
        for (auto x : v) q.push(x);
    }

    void print() {
        auto v = to_vector();
        for (auto x : v) cout << x << " ";
        cout << endl;
    }

    void add_avg() {
        auto v = to_vector();

        T s = v[0];
        for (int i = 1; i < v.size(); i++)
            s = s + v[i];

        T avg = s / v.size();
        v.insert(v.begin(), avg);

        from_vector(v);
    }

    void delete_key(T key) {
        auto v = to_vector();
        vector<T> res;

        for (auto x : v)
            if (!(x == key)) res.push_back(x);

        from_vector(res);
    }

    void subtract_min() {
        auto v = to_vector();

        T m = v[0];
        for (auto x : v)
            if (x < m) m = x;

        for (auto& x : v)
            x = x - m;

        from_vector(v);
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    cout << "========================================\n";
    cout << "         РАБОТА С ФОРМАТОМ FLOAT        \n";
    cout << "========================================\n";

    int n;
    cout << "Сколько элементов (чисел) будет в списке? -> ";
    cin >> n;

    MyList<float> v(n);
    v.print("Исходный список FLOAT");

    if (n > 0) {
        float avg = v.srednee();
        cout << "[Действие]: Вычислено среднее (" << avg << ") и добавлено в начало.\n";
        v.add_begin(avg);
        v.print("После добавления среднего");

        float key;
        cout << "Введите число, которое нужно УДАЛИТЬ из списка: -> ";
        cin >> key;
        v.delete_key(key);
        v.print("После удаления по ключу");

        cout << "[Действие]: Вычитание минимального элемента из всех.\n";
        v.subtract_min();
        v.print("После вычитания минимума");
    }

    cout << "========================================\n";
    cout << "         РАБОТА С ФОРМАТОМ MONEY        \n";
    cout << "========================================\n";

    int m;
    cout << "Сколько элементов (денег) будет в списке? -> ";
    cin >> m;
    MyList<Money> vm(m);

    vm.print("Исходный список MONEY");

    if (m > 0) {
        Money avgm = vm.srednee();
        cout << "[Действие]: Вычислено среднее (" << avgm << ") и добавлено в начало.\n";
        vm.add_begin(avgm);
        vm.print("После добавления среднего");

        Money keym;
        cout << "Введите значение, которое нужно УДАЛИТЬ из списка:\n";
        cin >> keym;
        vm.delete_key(keym);
        vm.print("После удаления по ключу");

        cout << "[Действие]: Вычитание минимального элемента из всех.\n";
        vm.subtract_min();
        vm.print("После вычитания минимума");
    }

    return 0;
}