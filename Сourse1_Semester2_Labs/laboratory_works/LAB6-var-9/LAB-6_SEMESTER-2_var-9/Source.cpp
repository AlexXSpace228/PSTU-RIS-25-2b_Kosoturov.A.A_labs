#include <iostream>
#include <clocale>
#include <string>

using namespace std;

//true - если элемент (element) есть в списке запрещенных символов (BME)
//size - размер списка запрещенных символов
bool BADElement_Check(char* BME, int size, char element) {
    for (int i = 0; i < size; i++) {
        if (BME[i] == element) {
            return true;
        }
    }
    return false;
}

void DellNumbers(string& str) {
    char Numbers[10]{ '0','1', '2', '3', '4', '5', '6', '7', '8', '9' };
    int index = 0;
    while (index < str.length()) {

        bool fl = false;
        int start = index;
        int lenw = 0;

        while (index < str.length() && str[index] != ' ') {
            if (BADElement_Check(Numbers, 10, str[index]) && !fl) {
                fl = false;
            }
            else {
                fl = true;
            }
            lenw++;
            index++;
        }

        // само удаление
        if (!fl) {
            str.erase(start, lenw + 1);
            index -= (lenw + 1);
        }

        index++;
    }
}

void DellBadElement(string& str) {
    char masSim[65] = {
    '_', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
    'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
    't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C',
    'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
    'X', 'Y', 'Z', '$', ' ', '0','1', '2', '3', '4',
    '5', '6', '7', '8', '9'
    };
    int index = 0;
    while (index < str.length()) {
        if (!BADElement_Check(masSim, 65, str[index])) {
            str.erase(index, 1);
        }
        else {
            index++;
        }
    }
}

void DellDubleSpace(string& str) {
    int index = 1;
    while (index < str.length()) {
        if (str[index] == ' ' && str[index - 1] == ' ') {
            str.erase(index, 1);
        }
        else {
            index++;
        }
    }
}

//"№ sdr;) -34 9sd№ 943- 355 34 sdf f34a 555 sA4Q@$5#$%#% 0 0 9( ( ( (

int main() {

    setlocale(LC_ALL, "RU");
    system("chcp 1251");
    system("cls");
    
    cout << "Введите строку: ";

    string str;
    getline(cin, str);
    //str = str + ' ';

    int len = str.length();

    DellNumbers(str);

    cout << "Удаление слов состоящих только из цифр: " << str << '\n';

    DellBadElement(str);

    cout << "Удаление Запрещенных символов: " << str << '\n';

    DellDubleSpace(str);

    cout << "Удаление повторяющихся пробелов: " << str << '\n';

    DellNumbers(str);

    cout << "Повторное удаление слов состоящих только из цифр: " << str << '\n';

    return 0;
}