//2.�̳�
//��д����������Բ����Բ׶�ı�����������
//Ҫ��
//��1������һ������Բ�����ٺ���һ�����ݳ�Ա���뾶��
//��2���������������ࣺ��Բ����Բ׶��������������������ĳ�Ա���������������
//��3������������������Բ����Բ׶�ĺ������
//Բ׶�ı������ʽ��
//s = �� * r*l + ����r�� ^ 2
//(l��Բ׶��ĸ�ߣ�l = ��(h ^ 2 + r ^ 2))(h��Բ׶�ĸ�)

#include<iostream>
#include"header_All.h"

//Բ��
double yuanzhu::surface() {
	double a = dimianji * 2;
	double b = zhouchang * height;
	return a + b;
}

double yuanzhu::volume() {
	return dimianji * height;
}

//Բ׶
double yuanzui::surface() {
	double a = muxian * radius * PI;
	return a + dimianji;
}

double yuanzui::volume() {
	return 1.000 / 3.000 * dimianji * height;
}

//��
double ball::surface() {
	return 4.000 * dimianji;
}

double ball::volume() {
	return 4.000 / 3.000 * dimianji * radius;
}