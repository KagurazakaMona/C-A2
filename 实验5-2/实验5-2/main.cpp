//2.�̳�
//��д����������Բ����Բ׶�ı�����������
//Ҫ��
//��1������һ������Բ�����ٺ���һ�����ݳ�Ա���뾶��
//��2���������������ࣺ��Բ����Բ׶��������������������ĳ�Ա���������������
//��3������������������Բ����Բ׶�ĺ������
//Բ׶�ı������ʽ��
//s = �� * r*l + ����r�� ^ 2
//(l��Բ׶��ĸ�ߣ�l = ��(h ^ 2 + r ^ 2))(h��Բ׶�ĸ�)

#include <iostream>
#include "header_All.h"
using namespace std;

int main() {
	double a, b, c;
	cout << "��������İ뾶��";
	cin >> a;
	ball BALL(a);
	cout << "��ı�����ǣ�" << BALL.surface() << endl;
	cout << "�������ǣ�" << BALL.volume() << endl;
	cout << "������Բ���ĵ���뾶��";
	cin >> a;
	cout << "������Բ���ĸߣ�";
	cin >> b;
	yuanzhu YZ(a, b);
	cout << "Բ���ı�����ǣ�" << YZ.surface() << endl;
	cout << "Բ��������ǣ�" << YZ.volume() << endl;
	cout << "������Բ׶�ĵ���뾶��";
	cin >> a;
	cout << "������Բ׶�ĸߣ�";
	cin >> b;
	yuanzui YZui(a, b);
	cout << "Բ׶�ı�����ǣ�" << YZui.surface() << endl;
	cout << "Բ׶������ǣ�" << YZui.volume() << endl;
	system("pause");
	return 0;
}