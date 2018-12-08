#include<iostream>
#include"Shape.h"
using namespace std;
int main() {
	Circle cricle(10);
	Rectangle rectangle(5,10);
	Triangle triangle(3,4,5);
	cout << "圆的面积是：" << cricle.area() << endl;
	cout << "矩形的面积是：" << rectangle.area() << endl;
	cout << "三角形的面积是：" << triangle.area() << endl;
	system("pause");
	return 0;
}