#pragma once
#include <string>

class AUTOMOBILE {
private:
	std::string mark;
	std::string model;
	int cost;
public:
	AUTOMOBILE(std::string ma, std::string mo, int c) {
		mark = ma;
		model = mo;
		cost = c;
	}
	AUTOMOBILE() {
		mark = "Default";
		model = "Default";
		cost = 0;
	}
	AUTOMOBILE(const AUTOMOBILE& other) {
		mark = other.mark;
		model = other.model;
		cost = other.cost;
	}
	void show();

	//сетеры
	void setmark(std::string MARK) {
		mark = MARK;
	}
	void setmodel(std::string MODEL) {
		model = MODEL;
	}
	void setcost(int COST) {
		cost = COST;
	}

	~AUTOMOBILE() {}
};
