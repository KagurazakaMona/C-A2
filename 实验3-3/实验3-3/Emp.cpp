#include <iostream>
#include "Emp.h"
using namespace std;

Employee::Employee(int nu, string nm, string sx, double wg) {
	total(wg);
}

void Employee::total(double wg) {
	count++;
	total_Wage += wg;
}

void Employee::show_Base() {
	cout << num << " " << name << " " << sex << " " << wage << endl;
}

void Employee::show_Static() {
	cout << "员工总人数为：" << count << endl;
	cout << "总工资为：" << total_Wage << endl;
}