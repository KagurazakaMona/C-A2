#pragma once
//1.	类的组合
//编写程序输出学生的基本信息。
//要求：
//（1）定义专业类Specialty，使其包含两个私有数据成员：专业名字sname和学分score。定义并实现该类的带参数的构造函数以及公有成员函（显示专业姓名和学分的函数showSp）；
//（2）定义学生类Student，使其包含三个私有数据成员：名字name、年龄 age、专业sp, 定义并实现该类的构造函数以及公有成员函数（显示姓名、年龄和专业的函数showStu）；
//（3）在main函数中对上述设计进行测试。
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