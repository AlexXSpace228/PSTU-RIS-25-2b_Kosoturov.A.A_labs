#include "Hierarchy.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "ru");

    cout << "=== DEMO: Иерархия + Дерево + События ===" << endl;
    cout << "Команды:" << endl;
    cout << "  mN  - создать N объектов" << endl;
    cout << "  +   - добавить 1 объект" << endl;
    cout << "  -   - очистить дерево" << endl;
    cout << "  s   - показать все объекты" << endl;
    cout << "  ?N  - показать объект с id = N" << endl;
    cout << "  q   - выход" << endl;
    cout << "----------------------------------------" << endl;

    Dialog d;
    d.Execute();

    cout << "Завершение программы." << endl;
    return 0;
}