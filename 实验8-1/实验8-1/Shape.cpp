#include "Shape.h"
#include <cmath>
double Circle::area() 
{
	return r * r * PI;
}

double Rectangle::area()
{
	return a * b;
}

double Triangle::area()
{
	double p = (a + b + c) / 2;
	return sqrt(p*(p - a)*(p - b)*(p - c));
}
