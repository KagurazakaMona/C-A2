#pragma once

double static PI = 3.141;

class Shape {
public:
	virtual double area() = 0;
};

class Circle :public Shape {
private:
	double r;
public:
	Circle() {}
	Circle(double rr) :r(rr) {}
	double area();
};

class Rectangle :public Shape {
private:
	double a, b;
public:
	Rectangle() {}
	Rectangle(double aa, double bb) :a(aa), b(bb) {}
	double area();
};

class Triangle:public Shape{
private:
	double a, b, c;
public:
	Triangle() {}
	Triangle(double aa, double bb, double cc) :a(aa), b(bb), c(cc) {}
	double area();
};