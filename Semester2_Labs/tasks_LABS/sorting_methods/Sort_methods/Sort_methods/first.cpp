#pragma once
#include <fstream>
#include <string>

// =====7======

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