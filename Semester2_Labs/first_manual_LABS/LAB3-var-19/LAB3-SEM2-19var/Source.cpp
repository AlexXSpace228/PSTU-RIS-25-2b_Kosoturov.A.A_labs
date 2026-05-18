#include <iostream>
#include <cmath>
using namespace std;

double TaylorByN(double x, int n) {
    double term = 1.0;
    double sum = term;

    for (int i = 1; i <= n; i++) {
        term = term * (2 * x) / i;
        sum += term;
    }

    return sum;
}

int main() {
    double a = 0.0;
    double b = 1.0;
    int k = 10;
    int n = 10;

    double h = (b - a) / k;

    cout << "x\tTaylor\tExact\n";

    for (int i = 0; i <= k; i++) {
        double x = a + i * h;

        double approx = TaylorByN(x, n);
        double exact = exp(2 * x);

        cout << x << "\t" << approx << "\t" << exact << endl;
    }

    return 0;
}