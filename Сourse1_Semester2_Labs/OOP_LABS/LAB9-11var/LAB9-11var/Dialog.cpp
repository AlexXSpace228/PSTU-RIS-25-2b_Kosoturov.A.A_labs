#include "Dialog.h"
#include "Student.h"
#include <iostream>

using namespace std;

void Dialog::Execute() {
    char cmd;

    while (true) {
        cout << "\nКомманды:\n";
        cout << "m - создать группу\n";
        cout << "+ - добавить\n";
        cout << "s - показать\n";
        cout << "q - выйти\n";
        cout << "> ";

        cin >> cmd;

        if (cmd == 'q') break;

        switch (cmd) {
        case 'm': {
            int n;
            cout << "Количество: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                Student* s = new Student();
                s->Input();
                Add(s);
            }
            break;
        }

        case '+': {
            Student* s = new Student();
            s->Input();
            Add(s);
            break;
        }

        case 's':
            Show();
            break;

        default:
            cout << "Неизвестная команда\n";
        }
    }
}