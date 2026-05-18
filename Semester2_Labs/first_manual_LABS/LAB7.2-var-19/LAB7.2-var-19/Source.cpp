#include <iostream>
#include <cstdarg>
#include <clocale>

const int R = 5;   // фиксированный радиус

bool onCircle(int x, int y) {
    return (x * x + y * y == R * R);
}

int belong(int paramCount, ...) {
    if (paramCount < 3) return 0;

    va_list args;
    va_start(args, paramCount);

    int result = 0;
    int pointCount = paramCount / 2;  // координаты идут парами

    for (int i = 0; i < pointCount; ++i) {
        int x = va_arg(args, int);
        int y = va_arg(args, int);

        if (onCircle(x, y)) {
            ++result;
        }
    }

    va_end(args);
    return result;
}

int main() {

    setlocale(LC_ALL, "RU");

    // 3 параметра: 1 точка
    int p1 = belong(3, 3, 4);
    std::cout << "Точек на окружности (3 параметра): " << p1 << std::endl;

    // 9 параметров: 4 точки
    int p2 = belong(9, 3, 4, 5, 0, -3, 4, 1, 1);
    std::cout << "Точек на окружности (9 параметров): " << p2 << std::endl;

    // 11 параметров: 5 точек
    int p3 = belong(11, 3, 4, 5, 0, -3, 4, 0, -5, 2, 2);
    std::cout << "Точек на окружности (11 параметров): " << p3 << std::endl;

    return 0;
}