#pragma once
//1.	������
//��д�������ѧ���Ļ�����Ϣ��
//Ҫ��
//��1������רҵ��Specialty��ʹ���������˽�����ݳ�Ա��רҵ����sname��ѧ��score�����岢ʵ�ָ���Ĵ������Ĺ��캯���Լ����г�Ա������ʾרҵ������ѧ�ֵĺ���showSp����
//��2������ѧ����Student��ʹ���������˽�����ݳ�Ա������name������ age��רҵsp, ���岢ʵ�ָ���Ĺ��캯���Լ����г�Ա��������ʾ�����������רҵ�ĺ���showStu����
//��3����main�����ж�������ƽ��в��ԡ�
#include <string>
#include "Specialty.h"
//using namespace std;

class Student {
private:
	string name;
	int age;
	Specialty sp;
public:
	Student(string n, int a, string sn, int s) :name(n), age(a), sp(sn, s) {};
	void showStu();
};