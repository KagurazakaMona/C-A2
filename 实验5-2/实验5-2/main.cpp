//2.继承
//编写程序计算出球、圆柱和圆锥的表面积和体积。
//要求：
//（1）定义一个基类圆，至少含有一个数据成员：半径；
//（2）定义基类的派生类：球、圆柱、圆锥，都含有求表面积和体积的成员函数和输出函数；
//（3）定义主函数，求球、圆柱、圆锥的和体积。
//圆锥的表面积公式：
//s = π * r*l + 〖πr〗 ^ 2
//(l是圆锥的母线：l = √(h ^ 2 + r ^ 2))(h是圆锥的高)

#include <iostream>
#include "header_All.h"
using namespace std;

int main() {
	double a, b, c;
	cout << "请输入球的半径：";
	cin >> a;
	ball BALL(a);
	cout << "球的表面积是：" << BALL.surface() << endl;
	cout << "球的体积是：" << BALL.volume() << endl;
	cout << "请输入圆柱的底面半径：";
	cin >> a;
	cout << "请输入圆柱的高：";
	cin >> b;
	yuanzhu YZ(a, b);
	cout << "圆柱的表面积是：" << YZ.surface() << endl;
	cout << "圆柱的体积是：" << YZ.volume() << endl;
	cout << "请输入圆锥的底面半径：";
	cin >> a;
	cout << "请输入圆锥的高：";
	cin >> b;
	yuanzui YZui(a, b);
	cout << "圆锥的表面积是：" << YZui.surface() << endl;
	cout << "圆锥的体积是：" << YZui.volume() << endl;
	system("pause");
	return 0;
}