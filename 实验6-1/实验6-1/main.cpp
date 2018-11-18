#include <iostream>
#include"class_All.h"
using namespace std;

void Point::poi_Display() {
	//cout << "计算任务1：" << endl;
	cout << "(" << x << "," << y << ")" << endl;
}

double Circle::cal_Area() {
	area = PI * r * r;
	return area;
}

void Circle::cri_Display() {
	//cout << "计算任务2：" << endl;
	cout << "圆的圆心坐标为：";
	poi_Display();
	cout << "圆的半径是：" << r << endl;
	cout << "圆的面积是" << cal_Area() << endl;
}

double Cylinder::cal_Area() {
	area = PI * r * r * 2;
	return area;
}

double Cylinder::cal_Volume() {
	volume = area * h;
	return volume;
}

void Cylinder::cyl_Display() {
	cout << "圆柱体的圆心平面坐标为：";
	poi_Display();
	cout << "圆柱的底面半径为：" << r << endl;
	cout << "圆柱的表面积为：" << cal_Area() << endl;
	cout << "圆柱的体积为：" << cal_Volume() << endl;
}

void Cylinder::OpenJudge() {
	cout << cal_Area() << " " << cal_Volume() << endl;
}

int main() {
	double a, b, c, d;
	cout << "请输入圆心坐标：";
	cin >> a >> b;
	Point point(a, b);
	point.poi_Display();
	cout << "请输入圆心坐标、圆形半径：";
	cin >> a >> b >> c;
	Circle circle(a, b, c);
	circle.cri_Display();
	cout << "请输入圆心坐标、圆柱体底面半径、圆柱体高：";
	cin >> a >> b >> c >> d;
	Cylinder cylinder(a, b, c, d);
	cylinder.cyl_Display();
	system("pause");
	////以下内容为OpenJudge使用
	//cin >> a >> b;
	//Cylinder OpenJudge(a, b);
	//OpenJudge.OpenJudge();
	////结束
	return 0;
}