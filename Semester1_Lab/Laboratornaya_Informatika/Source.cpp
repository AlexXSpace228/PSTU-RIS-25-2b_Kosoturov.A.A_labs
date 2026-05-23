#include <iostream>
#include <clocale>
#include <cmath>

const double epsilon = 1e-6;			//точность

double f(double x) {
	return x - (1 / (3 + sin(3.6 * x)));
}

int main() {
	double a, b, c;
	a = 0;
	b = 0.85;
	while (b - a > epsilon) {
		c = (a + b) / 2;
		if (f(a) * f(c) < 0) {
			b = c;						//a-----c-----b -> a-----b(c)--<--!!! -> a--c--b 
		}
		else {
			a = c;						//a-----c-----b -> !!!-->--a(c)-----b -> a--c--b
		}
	}
	std::cout << (a + b) / 2 << std::endl;
	return 0;
}