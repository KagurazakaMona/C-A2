#include "admin.h"
#include "library.h"
#include<string>
#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：admin::Menu()
.					作用：管理员主菜单。
.					输入值：None
.					类型：void
.					返回值：None

*//////////////////////////////////////////////////////////////////////////////
void admin::Menu() {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);//  获取输出流的句柄
	SetConsoleTextAttribute(hOut,
		FOREGROUND_RED |        // 文字色_红色
		BACKGROUND_BLUE | BACKGROUND_GREEN/* | BACKGROUND_RED*/);      // 背景色_蓝绿色
	cout << "                                        " << endl;
	cout << "**********   图书馆管理系统   **********" << endl;
	cout << "***            管理员面板            ***" << endl;
	SetConsoleTextAttribute(hOut,
		BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);//文字色_黑色，背景白色
	cout << "菜单：" << endl;
	cout << "1.注册学生账号" << endl;
	cout << "2.柜台还书" << endl;
	cout << "3.图书检索" << endl;
	cout << "4.删除学生账号" << endl;
	cout << "请输入选择序号：";
	int choose;
	cin >> choose;
	switch (choose) {
	case(1):; break;
	default:
		break;
	}
}

/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：admin::StudentSignUp()
.					作用：注册学生账号输入信息界面。
.					输入值：None
.					类型：void
.					返回值：None

*//////////////////////////////////////////////////////////////////////////////
void admin::StudentSignUp() {
	while (1) {
		string temp1, temp2;
		string number;
		string name;
		string sex;
		cout << "请输入新注册的学生姓名：";
		cin >> name;
		cout << "请输入新注册的学生学号：";
		cin >> number;
		cout << "请输入新注册的性别：";
		cin >> sex;
		cout << "请输入新注册学生的密码：";
		cin >> temp1;
		cout << "请再次输入新注册学生的密码：";
		cin >> temp2;
		if (temp1 == temp2) {
			library::StudentSignUp(number, temp2, name, sex);
			break;
		}
		else {
			cout << "两次输入的密码不同，请重试！" << endl;
		}
	}
}

/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：admin::ListStudent()
.					作用：输出学生细心。
.					输入值：None
.					类型：void
.					返回值：None

*//////////////////////////////////////////////////////////////////////////////
void admin::ListStudents() {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);//  获取输出流的句柄
	SetConsoleTextAttribute(hOut,
		FOREGROUND_RED |        // 文字色_红色
		BACKGROUND_BLUE | BACKGROUND_GREEN/* | BACKGROUND_RED*/);      // 背景色_蓝绿色
	int num = 1;
	if (!library::studentlist.empty()) {
		cout << setw(3) << "序号" << setw(10) << "学号（登录名）" << setw(10) << "性别" << setw(10) << "现借书数量" << endl;
		SetConsoleTextAttribute(hOut,
			BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);//文字色_黑色，背景白色
		for (auto i : library::studentlist) {
			cout << setw(3) << num++ << setw(10) << i.GetUsername() << setw(10) << i.GetSex() << i.GetBorroenumber() << endl;
		}
	}
	else {
		cout << "没有管理员！" << endl;
		SetConsoleTextAttribute(hOut,
			BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);//文字色_黑色，背景白色
	}
}

superadmin::superadmin() {
	username = "root";
	password = "470026648";
}

void superadmin::Menu() {
	while (1) {
		HANDLE hOut;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);//  获取输出流的句柄
		SetConsoleTextAttribute(hOut,
			FOREGROUND_RED |        // 文字色_红色
			BACKGROUND_BLUE | BACKGROUND_GREEN/* | BACKGROUND_RED*/);      // 背景色_蓝绿色
		cout << "**********   图书馆管理系统   **********" << endl;
		cout << "***          超级管理员面板          ***" << endl;
		cout << "                                        " << endl;
		SetConsoleTextAttribute(hOut,
			BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);//文字色_黑色，背景白色
		cout << "菜单：" << endl;
		cout << "1.注册学生账号" << endl;
		cout << "2.柜台还书" << endl;
		cout << "3.图书检索" << endl;
		cout << "4.删除学生账号" << endl;
		cout << "5.注册管理员账号" << endl;
		cout << "6.列出管理员账号与密码" << endl;
		cout << "0.退出" << endl;
		cout << "请输入选择序号：";
		int choose;
		cin >> choose;
		switch (choose) {
		case(1):admin::StudenSignUp(); break;
		case(2):; break;
		case(3):; break;
		case(4):; break;
		case(5):AdminSignUp(); break;
		case(6):ListAdmins(); break;
		case(0):goto exit; break;
		default:
			break;
		}
	}
exit:;
}

void superadmin::AdminSignUp() {
	while (1) {
		string temp1, temp2;
		string tempusername;
		cout << "请输入新注册的管理员真实姓名：";
		cin >> name;
		cout << "请输入新注册的管理员用户名：";
		cin >> tempusername;
		cout << "请输入新注册的管理员密码：";
		cin >> temp1;
		cout << "请再次输入新注册的管理员密码：";
		cin >> temp2;
		if (temp1 == temp2) {
			library::AdminSignUp(name, tempusername, temp2);
			break;
		}
		else {
			cout << "两次输入的密码不同，请重试！" << endl;
		}
	}
}

void superadmin::ListAdmins() {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);//  获取输出流的句柄
	SetConsoleTextAttribute(hOut,
		FOREGROUND_RED |        // 文字色_红色
		BACKGROUND_BLUE | BACKGROUND_GREEN/* | BACKGROUND_RED*/);      // 背景色_蓝绿色
	int num = 1;
	if (!library::adminlist.empty()) {
		cout << "本图书馆管理员信息如下：" << endl;
		cout << setw(5) << "序号" << setw(20) << "姓名" << setw(20) << "用户名" << setw(20) << "密码" << endl;
		SetConsoleTextAttribute(hOut,
			BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);//文字色_黑色，背景白色
		for (auto i : library::adminlist) {
			cout << setw(5) << num++ << setw(20) << setw(20) << i.GetName << setw(20) << i.GetUsername() << setw(20) << i.GetPassword() << endl;
		}
	}
	else {
		cout << "没有管理员！" << endl;
		SetConsoleTextAttribute(hOut,
			BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);//文字色_黑色，背景白色
	}
}
