#include <iostream>
#include "ClassTRIAD.h"
#include "ClassTIME.h"
#include "ClassVector.h"
#include <clocale>

int main() {
    setlocale(LC_ALL, "RU");
    Vector v(3);

    v.set(0, new TIME(23, 59, 58));
    v.set(1, new TIME(10, 20, 30));
    v.set(2, new TIME(5, 59, 59));

    std::cout << "Исходные значения:\n";
    std::cout << v << "\n";

    std::cout << "Увеличиваем каждое время на 1 секунду:\n";

    for (int i = 0; i < 3; i++) {
        v.get(i)->plus_third_one();
    }

    std::cout << v << "\n";

    std::cout << "Добавим 125 секунд ко второму элементу:\n";

    TIME* t = dynamic_cast<TIME*>(v.get(1));
    if (t) {
        t->plusSECONDS(125);
    }

    std::cout << v << "\n";

    std::cout << "Добавим 61 минуту к первому элементу:\n";

    TIME* t2 = dynamic_cast<TIME*>(v.get(0));
    if (t2) {
        t2->plusMINUTES(61);
    }

    std::cout << v << "\n";

    return 0;
}