#pragma once
//1.	������
//��д�������ѧ���Ļ�����Ϣ��
//Ҫ��
//��1������רҵ��Specialty��ʹ���������˽�����ݳ�Ա��רҵ����sname��ѧ��score�����岢ʵ�ָ���Ĵ������Ĺ��캯���Լ����г�Ա������ʾרҵ������ѧ�ֵĺ���showSp����
//��2������ѧ����Student��ʹ���������˽�����ݳ�Ա������name������ age��רҵsp, ���岢ʵ�ָ���Ĺ��캯���Լ����г�Ա��������ʾ�����������רҵ�ĺ���showStu����
//��3����main�����ж�������ƽ��в��ԡ�
#include <string>
using namespace std;

class Specialty {
private:
	string sname;
	int score;
public:
	Specialty(string sn, int s) :sname(sn), score(s) {};
	void showSp();
};