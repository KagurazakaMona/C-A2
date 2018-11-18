//定义一个描述员工(Employee)基本情况的类，数据成员包括编号(num)、姓名(name)、性别(sex)、工资（wage）、人数(count)、总工资(totalWage)。
//【要求】：
//1.总工资和人数为静态数据成员；
//2.构造函数由已知参数：编号(nu) 、姓名(nm) 、性别(sx)和工资(wg)进行初始化；
//3.显示基本数据函数(ShowBase)用于显示学生的编号、姓名、性别和工资；
//4.显示静态数据函数(ShowStatic)为静态成员函数，用于显示人数和总工资；
//5.在主函数中定义若干个员工对象，分别显示员工基本信息，以及显示员工人数和总工资。
//
//
//
//输入
//员工的基本信息
//输出
//员工的基本信息、员工人数和总工资
//样例输入
//101 李丽 女 5600
//102 张鹏 男 6200
//103 王俊亮 男 5780
//样例输出
//101 李丽 女 5600
//102 张鹏 男 6200
//103 王俊亮 男 5780
//员工人数为：3
//总工资为：17580

#include <iostream>
#include "Emp.h"
using namespace std;
int Employee::count = 0;
double Employee::total_Wage = 0;

int main() {
	int i;
	
	int num;
	string name;
	string sex;
	double wage;
	for (i = 0; i < 3; i++) {
		Employee a[3];
	}

	return 0;
}