#include <iostream>
#include <iomanip>
#include <windows.h>//颜色
#include <stdio.h>//颜色
#include <stdlib.h>//颜色
#include "student.h"
using namespace std;

void student::Menu() {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);//  获取输出流的句柄
	SetConsoleTextAttribute(hOut,
		FOREGROUND_RED |        // 文字色_红色
		BACKGROUND_BLUE | BACKGROUND_GREEN/* | BACKGROUND_RED*/);      // 背景色_蓝绿色
	cout << "**********   图书馆管理系统   **********" << endl;
	cout << "***             学生面板             ***" << endl;
	cout << "                                        " << endl;
	SetConsoleTextAttribute(hOut,
		BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);//文字色_黑色，背景白色
	cout << "菜单：" << endl;
	cout << "1.注册学生账号" << endl;
	cout << "2.柜台还书" << endl;
	cout << "3.图书检索" << endl;
	cout << "4.删除学生账号" << endl;
	cout << "5.注册管理员账号" << endl;
	cout << "请输入选择序号：";
	int choose;
	cin >> choose;
	switch (choose) {
	case(1):; break;
	default:
		break;
	}
}

void student::SignUp() {
	string temp1, temp2;
	cout << "请输入新注册的学生用户名：";
	cin >> username;
	cout << "请输入新注册的学生密码：";
	cin >> temp1;
	cout << "请再次输入新注册的学生密码：";
	cin >> temp2;
	if (temp1 == temp2) {
		password = temp2;
	}
}

student::student() {
	borrownumber = 0;
	vector<book> borrowbooks(10);
}

string student::GetSex() {
	return sex;
}

int student::GetBorroenumber() {
	return borrownumber;
}

vector<string> student::GetBorrowbooksisbn() {
	return borrowbooksisbn;
}

/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：student::ShowInformation()
.					作用：输出学生信息。
.					输入值：None
.					类型：void 
.					20 用户名 20 名字 10 性别 20 借书数 endl

*//////////////////////////////////////////////////////////////////////////////
void student::ShowInformation() {
	cout << setw(20) << username << setw(20) << name << setw(10) << sex << setw(20) << borrownumber << endl;
}
