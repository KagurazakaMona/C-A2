#pragma once
#include <iostream>
using namespace std;

class Date {
private:
	int year, month, day;
	int month_Day();
	bool operator<(Date &af);
public:
	Date() {};
	Date(int y, int m, int d) :year(y), month(m), day(d) {};
	Date operator+(int days);
	Date operator-(int days);
	int operator-(Date &b);
	friend istream &operator>>(istream &is, Date c);
	friend ostream &operator<<(ostream &os, Date &c);
};