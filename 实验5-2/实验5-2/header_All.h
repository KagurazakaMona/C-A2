#pragma once
//2.继承
//编写程序计算出球、圆柱和圆锥的表面积和体积。
//要求：
//（1）定义一个基类圆，至少含有一个数据成员：半径；
//（2）定义基类的派生类：球、圆柱、圆锥，都含有求表面积和体积的成员函数和输出函数；
//（3）定义主函数，求球、圆柱、圆锥的和体积。
//圆锥的表面积公式：
//s = π * r*l + 〖πr〗 ^ 2
//(l是圆锥的母线：l = √(h ^ 2 + r ^ 2))(h是圆锥的高)

#include <cmath>;
using namespace std;
const double PI = 3.14;

//圆形
class round {
public:
	double dimianji;
	double radius;
	double zhouchang;
	round(double r) :radius(r) {
	dimianji = pow(radius, 2) * PI;
	zhouchang = (double)2 * 3.14 * radius;
	};
};

//圆柱
class yuanzhu:public round {
private:
	double height;
public:
	yuanzhu(double r, double h) :round(r), height(h) {};
	double surface();
	double volume();
};

//圆锥
class yuanzui :public round {
private:
	double height;
	double muxian;
public:
	yuanzui(double r, double h) :round(r), height(h) {
		muxian = sqrt(pow(height, 2) + pow(radius, 2));
	};
	double surface();
	double volume();
};

//球
class ball :public round {
public:
	ball(double r) :round(r) {};
	double surface();
	double volume();
};