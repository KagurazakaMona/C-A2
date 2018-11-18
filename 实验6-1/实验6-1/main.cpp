#include <iostream>
#include"class_All.h"
using namespace std;

void Point::poi_Display() {
	//cout << "��������1��" << endl;
	cout << "(" << x << "," << y << ")" << endl;
}

double Circle::cal_Area() {
	area = PI * r * r;
	return area;
}

void Circle::cri_Display() {
	//cout << "��������2��" << endl;
	cout << "Բ��Բ������Ϊ��";
	poi_Display();
	cout << "Բ�İ뾶�ǣ�" << r << endl;
	cout << "Բ�������" << cal_Area() << endl;
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
	cout << "Բ�����Բ��ƽ������Ϊ��";
	poi_Display();
	cout << "Բ���ĵ���뾶Ϊ��" << r << endl;
	cout << "Բ���ı����Ϊ��" << cal_Area() << endl;
	cout << "Բ�������Ϊ��" << cal_Volume() << endl;
}

void Cylinder::OpenJudge() {
	cout << cal_Area() << " " << cal_Volume() << endl;
}

int main() {
	double a, b, c, d;
	cout << "������Բ�����꣺";
	cin >> a >> b;
	Point point(a, b);
	point.poi_Display();
	cout << "������Բ�����ꡢԲ�ΰ뾶��";
	cin >> a >> b >> c;
	Circle circle(a, b, c);
	circle.cri_Display();
	cout << "������Բ�����ꡢԲ�������뾶��Բ����ߣ�";
	cin >> a >> b >> c >> d;
	Cylinder cylinder(a, b, c, d);
	cylinder.cyl_Display();
	system("pause");
	////��������ΪOpenJudgeʹ��
	//cin >> a >> b;
	//Cylinder OpenJudge(a, b);
	//OpenJudge.OpenJudge();
	////����
	return 0;
}