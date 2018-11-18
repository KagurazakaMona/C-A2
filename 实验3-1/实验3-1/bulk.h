#pragma once
class bulk {
public:
	bulk(double l = 1.0, double w = 1.0, double h = 1.0) :length(l), width(w), heigth(h) {}
	void get_value();
	void output();
private:
	double length, width, heigth;
};