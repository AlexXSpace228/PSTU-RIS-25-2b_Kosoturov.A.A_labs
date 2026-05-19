#include <iostream>
#include <vector>
#include <clocale>
using namespace std;

const int N = 8;
vector<int> board(N, -1); // board[row] = column

void printBoard() {
    cout << "-----------------\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

bool safe(int row, int col) {
    for (int i = 0; i < row; i++) {
        int qcol = board[i];
        if (qcol == col || abs(qcol - col) == abs(i - row))
            return false;
    }
    return true;
}

bool solve(int row) {
    if (row == N)
        return true;

    for (int col = 0; col < N; col++) {
        if (safe(row, col)) {
            board[row] = col;
            cout << "Поставили ферзя: строка " << row << " столбец " << col << endl;
            printBoard();

            if (solve(row + 1))
                return true;

            cout << "Откат с позиции: строка " << row << " столбец " << col << endl;
            board[row] = -1;
            printBoard();
        }
    }
    return false;
}

int main() {
    setlocale(LC_ALL, "RU");
    if (solve(0))
        cout << "Решение найдено.\n";
    else
        cout << "Решение не найдено.\n";
    return 0;
}