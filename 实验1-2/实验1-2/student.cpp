#include <iostream>
#include "student.h"
using namespace std;
void Student::display(){//在类外定义display类函数
	cout << "实验1-2，学生信息输出：" << endl;
	cout << "num：" << num << endl;
	cout << "name：" << name << endl;
	cout << "sex：" << sex << endl;
}
void Student::set_value() {
	cout << "实验1-2，学生赋初值：（学号，名字，性别）" << endl;
	cin >> num;
	cin >> name;
	cin >> sex;
}
