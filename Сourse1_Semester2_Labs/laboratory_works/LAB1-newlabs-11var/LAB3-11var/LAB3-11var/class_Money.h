#pragma once

class Money {
private:
	long roubles;
	int peny;
public:
	Money() {
		roubles = 0;
		peny = 0;
	}
	Money(long r, int p) {
		roubles = r;
		peny = p;
	}
	Money(const Money& other) {
		roubles = other.roubles;
		peny = other.peny;
	}

	// сетеры
	
	void setRoubles(long R) {
		roubles = R;
	}
	void setPeny(long P) {
		peny = P;
	}

	// гетеры

	long GetRUB() {
		return roubles;
	}
	int GetP() {
		return peny;
	}

	Money operator ++(int) {
		peny++;
	}
	Money operator++ (int) {
		peny++;
	}

	Money operator <(int) {
		peny++;
	}
	Money operator >(int) {
		peny++;
	}

	~Money();
};
