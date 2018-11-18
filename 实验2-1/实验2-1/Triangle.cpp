#include <iostream>
#include <cmath>
#include "Triangle.h"
using namespace std;

void Triangle::showMessage(){
	cout << "三角形的三边长分别为：" << a << ' ' << b << ' ' << c << endl;
	cout << "该三角形的周长为" << perimeter() << "，面积为：" << area() << endl << endl;
}

double Triangle::area() {
	double p, s;
	p = (a + b + c) / 2;
	s = sqrt(p*(p - a)*(p - b)*(p - c));
	return s;
}

double Triangle::perimeter() {
	return a + b + c;
}