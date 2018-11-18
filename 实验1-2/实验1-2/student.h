#pragma once
class Student//类声明
{
public://公用成员函数原型声明
	void set_value();
	void display();
private:
	int num;
	char name[20];
	char sex;
};
