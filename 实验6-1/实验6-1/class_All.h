#pragma once
#include<cmath>
double static PI = 3.14;

class Point{
protected:
	double x, y;
public:
	Point(double xx, double yy) :x(xx), y(yy) {}
	void poi_Display();
};

class Circle :public Point {
protected:
	double r;
	double area;
public:
	Circle(double x, double y, double rr) :Point(x, y), r(rr) {}
	double cal_Area();
	using Point::poi_Display;
	void cri_Display();
};

class Cylinder :public Circle {
protected:
	double h;
	double area;
	double volume;
public:
	Cylinder(double x, double y, double rr, double hh) :h(hh), Circle(x, y, rr) {}
	Cylinder(double rr, double hh) :h(hh), Circle(0, 0, rr) {}
	double cal_Area();
	double cal_Volume();
	void cyl_Display();
	void OpenJudge();
	using Point::poi_Display;
};