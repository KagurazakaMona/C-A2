//2.继承
//编写程序计算出球、圆柱和圆锥的表面积和体积。
//要求：
//（1）定义一个基类圆，至少含有一个数据成员：半径；
//（2）定义基类的派生类：球、圆柱、圆锥，都含有求表面积和体积的成员函数和输出函数；
//（3）定义主函数，求球、圆柱、圆锥的和体积。
//圆锥的表面积公式：
//s = π * r*l + 〖πr〗 ^ 2
//(l是圆锥的母线：l = √(h ^ 2 + r ^ 2))(h是圆锥的高)

#include<iostream>
#include"header_All.h"

//圆柱
double yuanzhu::surface() {
	double a = dimianji * 2;
	double b = zhouchang * height;
	return a + b;
}

double yuanzhu::volume() {
	return dimianji * height;
}

//圆锥
double yuanzui::surface() {
	double a = muxian * radius * PI;
	return a + dimianji;
}

double yuanzui::volume() {
	return 1.000 / 3.000 * dimianji * height;
}

//球
double ball::surface() {
	return 4.000 * dimianji;
}

double ball::volume() {
	return 4.000 / 3.000 * dimianji * radius;
}