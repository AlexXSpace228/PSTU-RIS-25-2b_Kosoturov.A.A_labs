#pragma once
#include <iostream>
class Money {
private:
	long roubles;
	int peny;
public:
	// ======================= конструкторы
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

	// ======================= сетеры
	void setRoubles(long R) {
		roubles = R;
	}
	void setPeny(int P) {
		if (P > 0)
			peny = P;
		else
			peny = 0;
	}

	// ======================= гетеры
	long GetRUB() const{
		return roubles;
	}
	int GetP() const{
		return peny;
	}

	// ======================= <<

	friend std::istream& operator>>(std::istream& in, Money& p) {
		std::cout << "\nВведите рубли: ";
		in >> p.roubles;
		std::cout << "\nВведите копейки: ";
		in >> p.peny;
		return in;
	}

	// ======================= >>

	friend std::ostream& operator<<(std::ostream& out, const Money& m) {
		out << m.roubles << ",";
		out << m.peny/10 << m.peny % 10;
		return out;
	}

	// ======================= =
	Money& operator = (const Money& p) {
		if (&p == this) return*this;
		roubles = p.roubles;
		peny = p.peny;
		return *this;
	}
	// ======================= ++
	Money& operator++() {
		peny++;
		if (peny >= 100) {
			peny -= 100;
			roubles++;
		}
		return *this;
	}

	Money operator++(int) {
		Money temp(*this);

		peny++;
		if (peny >= 100) {
			peny -= 100;
			roubles++;
		}

		return temp;
	}
	// ======================= < >
	bool operator<(const Money& other) const {
		long thisTotal = roubles * 100 + peny;
		long otherTotal = other.roubles * 100 + other.peny;
		return thisTotal < otherTotal;
	}
	bool operator>(const Money& other) const {
		long thisTotal = roubles * 100 + peny;
		long otherTotal = other.roubles * 100 + other.peny;
		return thisTotal > otherTotal;
	}

	~Money() {};
};