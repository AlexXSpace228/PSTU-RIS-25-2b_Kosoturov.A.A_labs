
#include "lab_12_oop.h"

#include <bits/stdc++.h>

#include "../lab_3_oop/id_pair.h"
using namespace std;

set<double> task_1_subtask_3(set<double> s) {
    double max = *s.begin();
    for (auto& x : s) {
        if (x > max) {
            max = x;
        }
    }
    s.insert(max);
    return s;
}

set<double> task_1_subtask_4(set<double> s, double k1, double k2) {
    bool b = false;
    set<double> res;
    for (double it : s) {
        if (it == k1 || it == k2) {
            b = !b;
        }
        if (!b) {
            res.insert(it);
        }
    }
    return res;
}

set<double> task_1_subtask5(set<double> s) {
    double sum = 0;
    for (const double it : s) {
        sum += it;
    }
    double avg = sum / s.size();
    vector<double> tmp;
    for (double x : s) {
        tmp.push_back(x + avg);
    }
    s.clear();
    for (auto& x : tmp) {
        s.insert(x);
    }
    return s;
}

set<idPair> task_1_subtask3(set<idPair> s) {
    idPair max = *s.begin();
    for (auto& x : s) {
        if (x > max) {
            max = x;
        }
    }
    s.insert(max);
    return s;
}

set<idPair> task_1_subtask_4(set<idPair> s, idPair k1, idPair k2) {
    bool b = false;
    set<idPair> res;
    for (idPair it : s) {
        if (it == k1 || it == k2) {
            b = !b;
        }
        if (!b) {
            res.insert(it);
        }
    }
    return res;
}

set<idPair> task_1_subtask5(set<idPair> s) {
    double sum = 0;
    for (auto it : s) {
        sum += it.value();
    }
    double avg = sum / s.size();
    vector<idPair> tmp;
    for (auto x : s) {
        x.sum(avg);
        tmp.push_back(x);
    }
    s.clear();
    for (auto& x : tmp) {
        s.insert(x);
    }
    return s;
}

void print_set(const string& label, const set<double>& s) {
    cout << label << '\n';
    int i = 0;
    for (auto& x : s) {
        cout << i << ": " << x << '\n';
        i++;
    }
    cout << '\n';
}

void print_idpair_set(const string& label, const set<idPair>& s) {
    cout << label << '\n';
    int i = 0;
    for (auto& x : s) {
        cout << i << ": " << x;
        i++;
    }
    cout << '\n';
}

double set_average(const set<double>& s) {
    double sum = 0;
    for (auto& x : s) sum += x;
    return sum / s.size();
}

set<double> set_insert_at_pos(set<double> s, int pos, double val) {
    if (pos <= 0) {
        s.insert(val);
        return s;
    }
    vector<double> tmp(s.begin(), s.end());
    if (pos >= (int)tmp.size()) {
        tmp.push_back(val);
    }
    else {
        tmp.insert(tmp.begin() + pos, val);
    }
    s.clear();
    for (auto& x : tmp) s.insert(x);
    return s;
}

set<double> set_del_range(set<double> s, double k1, double k2) {
    auto it1 = s.lower_bound(k1);
    auto it2 = s.upper_bound(k2);
    s.erase(it1, it2);
    return s;
}

set<double> set_add_avg(set<double> s) {
    double avg = set_average(s);
    vector<double> tmp;
    for (auto& x : s) tmp.push_back(x + avg);
    s.clear();
    for (auto& x : tmp) s.insert(x);
    return s;
}

idPair idpair_set_average(const set<idPair>& s) {
    double sum = 0;
    for (auto& x : s) sum += x.value();
    double avg = sum / s.size();
    int f = static_cast<int>(avg);
    return idPair(f, avg - f);
}

set<idPair> idpair_set_insert_at_pos(set<idPair> s, int pos, const idPair& val) {
    if (pos <= 0) {
        s.insert(val);
        return s;
    }
    vector<idPair> tmp(s.begin(), s.end());
    if (pos >= (int)tmp.size()) {
        tmp.push_back(val);
    }
    else {
        tmp.insert(tmp.begin() + pos, val);
    }
    s.clear();
    for (auto& x : tmp) s.insert(x);
    return s;
}

set<idPair> idpair_set_del_range(set<idPair> s, const idPair& k1, const idPair& k2) {
    auto it1 = s.lower_bound(k1);
    auto it2 = s.upper_bound(k2);
    s.erase(it1, it2);
    return s;
}

set<idPair> idpair_set_add_avg(set<idPair> s) {
    double sum = 0;
    for (auto& x : s) sum += x.value();
    double avg = sum / s.size();
    vector<idPair> tmp;
    for (auto x : s) {
        x.sum(avg);
        tmp.push_back(x);
    }
    s.clear();
    for (auto& x : tmp) s.insert(x);
    return s;
}

void task1_main() {
    cout << "=== TASK 1 (set<double>) ===\n";

    set<double> s = { 3.5, 1.2, 7.8, 2.4, 5.1 };
    print_set("Initial set:", s);

    double avg = set_average(s);
    cout << "Average = " << avg << '\n';
    int pos = 2;
    s = set_insert_at_pos(s, pos, avg);
    cout << "After inserting average at position " << pos << ":\n";
    print_set("", s);

    double k1 = 2.0, k2 = 6.0;
    s = set_del_range(s, k1, k2);
    cout << "After deleting elements in [" << k1 << ", " << k2 << "]:\n";
    print_set("", s);

    cout << "After adding average to each element:\n";
    s = set_add_avg(s);
    print_set("", s);

    cout << "\n";
}

void task2_main() {
    cout << "=== TASK 2 (set<idPair>) ===\n";

    set<idPair> s;
    s.insert(idPair(1, 0.1));
    s.insert(idPair(2, 0.5));
    s.insert(idPair(3, 0.3));
    s.insert(idPair(4, 0.7));
    s.insert(idPair(5, 0.2));
    print_idpair_set("Initial set:", s);

    idPair avg = idpair_set_average(s);
    cout << "Average = " << avg;
    int pos = 2;
    s = idpair_set_insert_at_pos(s, pos, avg);
    cout << "After inserting average at position " << pos << ":\n";
    print_idpair_set("", s);

    idPair k1(1, 0.5), k2(4, 0.0);
    s = idpair_set_del_range(s, k1, k2);
    cout << "After deleting elements in [" << k1 << ", " << k2 << "]:\n";
    print_idpair_set("", s);

    cout << "After adding average to each element:\n";
    s = idpair_set_add_avg(s);
    print_idpair_set("", s);

    cout << "\n";
}

void task3_main() {
    cout << "=== TASK 3 (Container<float>) ===\n";

    Container<float> v = { 3.5f, 1.2f, 7.8f, 2.4f, 5.1f };
    cout << "Initial container:\n";
    v.Print();

    float avg = v.Srednee();
    cout << "Average = " << avg << '\n';
    int pos = 2;
    v.Add(pos, avg);
    cout << "After adding average at position " << pos << ":\n";
    v.Print();

    float k1 = 2.0f, k2 = 6.0f;
    v.Del(k1, k2);
    cout << "After deleting elements in [" << k1 << ", " << k2 << "]:\n";
    v.Print();

    cout << "After adding average to each element:\n";
    v.Delenie();
    v.Print();

    cout << "\n";
}

int main() {
    task1_main();
    task2_main();
    task3_main();
    return 0;
}
