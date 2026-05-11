#include "Dialog.h"
#include <locale>
#include <windows.h>

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    Dialog d;
    d.Execute();

    return 0;
}