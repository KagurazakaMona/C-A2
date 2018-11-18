#pragma once
class Triangle{
public:
	double perimeter();//计算三角形的周长  
	double area();//计算并返回三角形的面积  
	void showMessage();
	//实验2-1.1
	//Triangle(double x, double y, double z) {
	//	a = x; b = y; c = z;
	//}
	//实验2-1.2，实验2-1.3
	//Triangle(double x = 1, double y = 1, double z = 1) {
	//	a = x; b = y; c = z;
	//}
	//实验2-1.4
	Triangle(double x, double y, double z) : a(x), b(y), c(z) {}
private:
	double a, b, c; //三边为私有成员数据  
};