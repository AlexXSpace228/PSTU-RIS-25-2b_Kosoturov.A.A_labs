#include <iostream>
#include "ClassTRIAD.h"
#include "Class_TIME.h"
#include <iomanip>
#include <clocale>

void printObject(TRIAD& t) {
    std::cout << "  Объект: " << t << '\n';
}

TRIAD createDefault() {
    return TRIAD(0, 0, 0);
}

void separator(const std::string& title) {
    std::cout << "\n" << std::string(60, '=') << '\n';
    std::cout << "  " << title << '\n';
    std::cout << std::string(60, '=') << '\n';
}

void section(const std::string& title) {
    std::cout << "\n>>> " << title << '\n';
    std::cout << std::string(50, '-') << '\n';
}

int main() {
    setlocale(LC_ALL, "RU");
    std::cout << "\n";
    std::cout << "ДЕМОНСТРАЦИЯ КЛАССА TRIAD\n\n\n";

    std::cout << "1. КОНСТРУКТОРЫ";

    TRIAD t1(10, 20, 30);
    std::cout << "Конструктор с параметрами:  t1(10, 20, 30) = " << t1 << '\n';

    TRIAD t2;
    std::cout << "Конструктор без параметров: t2() = " << t2 << '\n';

    TRIAD t3(t1);
    std::cout << "Конструктор копирования:    t3(t1) = " << t3 << '\n';

    std::cout << "2. СЕЛЕКТОРЫ (ГЕТТЕРЫ)";

    std::cout << "t1.getFirst()  = " << t1.getFirst() << '\n';
    std::cout << "t1.getSecond() = " << t1.getSecond() << '\n';
    std::cout << "t1.getThird()  = " << t1.getThird() << '\n';

    std::cout << "\nМОДИФИКАТОРЫ (СЕТТЕРЫ)\n\n";

    std::cout << "До: t2 = " << t2 << '\n';
    t2.setFirst(100);
    t2.setSecond(200);
    t2.setThird(300);
    std::cout << "После setFirst(100), setSecond(200), setThird(300):\n";
    std::cout << "  t2 = " << t2 << '\n';

    std::cout << "\nОПЕРАТОР ПРИСВАИВАНИЯ (=)\n\n";

    TRIAD t4 = t1;
    std::cout << "t4 = t1\n";
    std::cout << "  t1 = " << t1 << '\n';
    std::cout << "  t4 = " << t4 << '\n';

    t4 = t2;
    std::cout << "t4 = t2\n";
    std::cout << "  t4 = " << t4 << '\n';

    t4 = t4;
    std::cout << "t4 = t4 (самоприсваивание, работает корректно)\n";
    std::cout << "  t4 = " << t4 << '\n';

    std::cout << "\nВИРТУАЛЬНЫЕ МЕТОДЫ +1\n\n";

    TRIAD t5(5, 10, 15);
    std::cout << "t5 = " << t5 << '\n';
    t5.plus_first_one();
    std::cout << "После plus_first_one():  " << t5 << '\n';
    t5.plus_second_one();
    std::cout << "После plus_second_one(): " << t5 << '\n';
    t5.plus_third_one();
    std::cout << "После plus_third_one():  " << t5 << '\n';

    std::cout << "\nПОДСТАНОВКИ\n\n";

    std::cout << "Функция printObject() ожидает TRIAD&:\n";
    TRIAD base_obj(7, 8, 9);
    std::cout << "  TRIAD object: ";
    printObject(base_obj);

    TRIAD default_obj = createDefault();
    std::cout << "  Объект из createDefault(): " << default_obj << '\n';

    std::cout << "\n\nДЕМОНСТРАЦИЯ КЛАССА TIME\n\n\n";

    std::cout << "КОНСТРУКТОРЫ TIME\n\n";

    TIME tm1(23, 59, 58);
    std::cout << "Конструктор с параметрами: TIME(23, 59, 58) = " << tm1 << '\n';

    TIME tm2;
    std::cout << "Конструктор без параметров: TIME() = " << tm2 << '\n';

    TIME tm3(tm1);
    std::cout << "Конструктор копирования:    TIME(tm1) = " << tm3 << '\n';

    std::cout << "СЕЛЕКТОРЫ TIME (наследованные)";

    std::cout << "tm1.getFirst()  (часы)   = " << tm1.getFirst() << '\n';
    std::cout << "tm1.getSecond() (минуты) = " << tm1.getSecond() << '\n';
    std::cout << "tm1.getThird()  (секунды) = " << tm1.getThird() << '\n';

    std::cout << "\nМОДИФИКАТОРЫ TIME (наследованные)\n\n";

    std::cout << "До: " << tm2 << '\n';
    tm2.setFirst(14);
    tm2.setSecond(30);
    tm2.setThird(45);
    std::cout << "После setFirst(14), setSecond(30), setThird(45):\n";
    std::cout << "  " << tm2 << '\n';

    std::cout << "\nПЕРЕОПРЕДЕЛЁННЫЕ МЕТОДЫ +1 С ЛОГИКОЙ ПЕРЕПОЛНЕНИЯ\n\n";

    TIME tm4(23, 59, 58);
    std::cout << "Начало: " << tm4 << '\n';

    std::cout << "plus_third_one(): ";
    tm4.plus_third_one();
    std::cout << tm4 << '\n';

    std::cout << "plus_third_one(): ";
    tm4.plus_third_one();
    std::cout << tm4 << " (переполнение минут)\n";

    std::cout << "plus_third_one(): ";
    tm4.plus_third_one();
    std::cout << tm4 << " (переполнение часов, новые сутки!)\n";

    std::cout << "\nМЕТОДЫ УВЕЛИЧЕНИЯ НА N СЕКУНД/МИНУТ\n\n";

    TIME tm5(10, 30, 0);
    std::cout << "Начало: " << tm5 << '\n';

    tm5.plusSECONDS(90);
    std::cout << "После plusSECONDS(90): " << tm5 << '\n';

    tm5.plusMINUTES(45);
    std::cout << "После plusMINUTES(45):  " << tm5 << '\n';

    tm5.plusHOURS(3);
    std::cout << "После plusHOURS(3):     " << tm5 << '\n';

    std::cout << "\nСЛОЖНЫЙ ПРИМЕР: ПЕРЕХОД ЧЕРЕЗ СУТКИ\n\n";

    TIME tm6(23, 58, 30);
    std::cout << "Начало дня: " << tm6 << '\n';
    std::cout << "Добавляем 3 минуты и 45 секунд...\n";
    tm6.plusMINUTES(3);
    tm6.plusSECONDS(45);
    std::cout << "Результат: " << tm6 << " (новые сутки!)\n";

    std::cout << "\nПРИНЦИП ПОДСТАНОВКИ: TIME ВМЕСТО TRIAD\n\n";

    TIME tm_obj(15, 45, 30);
    std::cout << "Функция printObject() ожидает TRIAD&,\n";
    std::cout << "но мы передаём TIME:\n";
    std::cout << "  TIME object: ";
    printObject(tm_obj);

    std::cout << "Функция createDefault() возвращает TRIAD,\n";
    std::cout << "но TIME тоже является TRIAD:\n";
    TRIAD time_as_triad = createDefault();
    std::cout << "  " << time_as_triad << " (TRIAD)\n";

    std::cout << "\nПРИСВАИВАНИЕ И КОПИРОВАНИЕ TIME\n\n";

    TIME tm7(12, 0, 0);
    TIME tm8 = tm7;
    std::cout << "TIME tm7(12, 0, 0)\n";
    std::cout << "TIME tm8 = tm7\n";
    std::cout << "  tm7 = " << tm7 << '\n';
    std::cout << "  tm8 = " << tm8 << '\n';

    tm7 = TIME(20, 30, 45);
    std::cout << "tm7 = TIME(20, 30, 45)\n";
    std::cout << "  tm7 = " << tm7 << '\n';
    std::cout << "  tm8 = " << tm8 << " (tm8 не изменился)\n";


    return 0;
}