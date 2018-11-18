#pragma once
//2.�̳�
//��д����������Բ����Բ׶�ı�����������
//Ҫ��
//��1������һ������Բ�����ٺ���һ�����ݳ�Ա���뾶��
//��2���������������ࣺ��Բ����Բ׶��������������������ĳ�Ա���������������
//��3������������������Բ����Բ׶�ĺ������
//Բ׶�ı������ʽ��
//s = �� * r*l + ����r�� ^ 2
//(l��Բ׶��ĸ�ߣ�l = ��(h ^ 2 + r ^ 2))(h��Բ׶�ĸ�)

#include <cmath>;
using namespace std;
const double PI = 3.14;

//Բ��
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

//Բ��
class yuanzhu:public round {
private:
	double height;
public:
	yuanzhu(double r, double h) :round(r), height(h) {};
	double surface();
	double volume();
};

//Բ׶
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

//��
class ball :public round {
public:
	ball(double r) :round(r) {};
	double surface();
	double volume();
};