#pragma once

class TRIAL {
private:

	int first;
	int second;
	int third;

	//конструкторы
	TRIAL(int a1, int a2, int a3) {
		first = a1;
		second = a2;
		third = a3;
	}
	TRIAL() {
		first = 0;
		second = 0;
		third = 0;
	}
	TRIAL(const TRIAL& other) {
		first = other.first;
		second = other.second;
		third = other.third;
	}



	~TRIAL();
};