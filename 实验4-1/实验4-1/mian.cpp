#pragma once
#include <string>
#include <iostream>
using namespace std;

class Emp {
private:
	int num, wage;
	string name;
	string sex;
	static int count, totalwage;
public:
	Emp(int n, string na, string s, int w) :num(n), wage(w), name(na), sex(s) { }
	void ShowBase() {
		cout << num << name << sex << wage << endl;
	}
	static void ShowStatic() {

	}
};