#pragma once
#include <iostream>
#include "ClassTRIAD.h"
#include <iomanip>

class TIME : public TRIAD {
public:
	TIME(int a1, int a2, int a3) : TRIAD(a1, a2, a3) {};
	TIME() : TRIAD(0, 0, 0) {};
	TIME(const TIME& other) : TRIAD(other) {};

	void plus_first_one() override {
		first++;
		if (first >= 24) { first = 0; }
	}
	void plus_second_one() override {
		second++;
		if (second >= 60) { second = 0; plus_first_one(); }
	}
	void plus_third_one() override {
		third++;
		if (third >= 60) { third = 0; plus_second_one(); }
	}

	void plusHOURS(int p) {
		first = (first + p) % 24;
	}

	void plusMINUTES(int p) {
		int total = second + p;
		second = total % 60;
		plusHOURS(total / 60);
	}

	void plusSECONDS(int p) {
		int total = third + p;
		third = total % 60;
		plusMINUTES(total / 60);
	}
	/*
	friend std::ostream& operator<<(std::ostream& out, const TIME& t) {
		out << ((t.first) / 10) << ((t.first) % 10) << ':';
		out << ((t.second) / 10) << ((t.second) % 10) << ':';
		out << ((t.third) / 10) << ((t.third) % 10);
		return out;
	}
	*/
	friend std::ostream& operator<<(std::ostream& out, const TIME& t) {
		out << std::setfill('0')
			<< std::setw(2) << t.first << ':'
			<< std::setw(2) << t.second << ':'
			<< std::setw(2) << t.third;
		return out;
	}

	~TIME() {};
};

