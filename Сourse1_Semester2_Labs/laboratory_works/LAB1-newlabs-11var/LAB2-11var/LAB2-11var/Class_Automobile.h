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
	//сетеры
	void setmark(std::string MARK) {
		mark = MARK;
	}
	void setmark(std::string MODEL) {
		model = MODEL;
	}
	void setmark(int COST) {
		cost = COST;
	}
	// гетеры
	std::string getmark() const{
		return mark;
	}
	std::string getmark() const{
		return model;
	}
	int getcost() const {
		return cost;
	}

	~AUTOMOBILE();
};
