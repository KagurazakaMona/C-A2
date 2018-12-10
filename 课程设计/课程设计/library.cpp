#include"library.h"
#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：library::library()
.					作用：图书馆程序入口。
.					输入值：None
.					类型：None
.					返回值：None

*//////////////////////////////////////////////////////////////////////////////
library::library() {
	Menu();
}

/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：library::AdminSignUp()
.					作用：管理员账户注册。
.					输入值：新用户名，新密码
.					类型：void
.					返回值：None

*//////////////////////////////////////////////////////////////////////////////
void library::AdminSignUp(string newname, string newusername, string newpassword) {
	adminlist.push_back(admin(newname, newusername, newpassword));
}

/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：library::Menu()
.					作用：图书馆程序登录菜单。
.					输入值：None
.					类型：void
.					返回值：None

*//////////////////////////////////////////////////////////////////////////////
void library::Menu() {
	while (1) {
		HANDLE hOut;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);//  获取输出流的句柄
		SetConsoleTextAttribute(hOut,
			FOREGROUND_RED |        // 文字色_红色
			BACKGROUND_BLUE | BACKGROUND_GREEN/* | BACKGROUND_RED*/);      // 背景色_蓝绿色
		cout << "                                        " << endl;
		cout << "**********   图书馆管理系统   **********" << endl;
		cout << "                                        " << endl;
		SetConsoleTextAttribute(hOut,
			BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);//文字色_黑色，背景白色
		cout << "菜单：" << endl;
		cout << "1.登录管理员账号" << endl;
		cout << "2.登录学生账号" << endl;
		cout << "请输入选择序号：";
		int choose;
		cin >> choose;
		switch (choose) {
		case(1):AdminLogin(); break;
		case(2):StudentLogin(); break;
		default:
			break;
		}
		WriteFile();
	}
}

/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：library::WriteFile()
.					作用：写入文件。
.					输入值：None
.					类型：void
.					返回值：None

*//////////////////////////////////////////////////////////////////////////////
void library::WriteFile() {
	ofstream outfile;
	outfile.open("MonaLibrary.csv", ios::out | ios::trunc);
	for (auto i : booklist) {
		/*outfile << "book,";
		outfile << i.GetIsbn() <<','<< i.GetName() << ',' << i.GetLocation() << ',' << i.GetNowquantity() << ',' << i.GetTotalquantity() << endl;*/
	}
	for (auto i : adminlist) {
		outfile << "admin,";
		outfile << i.GetName() << ',' << i.GetUsername() << ',' << i.GetPassword() << endl;
	}
	for (auto i : studentlist) {
		outfile << "student,";
		outfile << i.GetName() << ',' << i.GetUsername() << ',' << i.GetSex() << ',' << i.GetBorroenumber() << ',';
		for (auto j : i.GetBorrowbooksisbn()) {
			outfile << j << ',';
		}
		outfile << endl;
	}
	outfile.close();
}

/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：library::AdminSignUp()
.					作用：学生账户注册。
.					输入值：新用户名，新密码，名字，性别
.					类型：void
.					返回值：None

*//////////////////////////////////////////////////////////////////////////////
void library::StudentSignUp(string newusername, string newpassword, string name, string se) {
	studentlist.push_back(student(newusername, newpassword, name, se));
}

/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：library::AdminLogin()
.					作用：管理员账户登录。
.					输入值：None
.					类型：void
.					返回值：None

*//////////////////////////////////////////////////////////////////////////////
void library::AdminLogin(){
	string username;
	string password;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);//  获取输出流的句柄
	SetConsoleTextAttribute(hOut,
		FOREGROUND_RED |        // 文字色_红色
		BACKGROUND_BLUE | BACKGROUND_GREEN/* | BACKGROUND_RED*/);      // 背景色_蓝绿色
	cout << "                    " << endl;
	cout << "     管理员登录     " << endl;
	cout << "                    " << endl;
	SetConsoleTextAttribute(hOut,
		BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);//文字色_黑色，背景白色
	cout << "用户名："; cin >> username;
	cout << "密码（注意！密码将以明文出现）："; cin >> password;
	if (username == "root") {
		root.login(password);
	}
	else {
		for (auto users : adminlist) {
			if (username == users.GetUsername()) {
				users.login(password);
			}
		}
	}
}

/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：library::StudentLogin()
.					作用：学生账户登录。
.					输入值：None
.					类型：void
.					返回值：None

*//////////////////////////////////////////////////////////////////////////////
void library::StudentLogin() {
	string username;
	string password;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);//  获取输出流的句柄
	SetConsoleTextAttribute(hOut,
		FOREGROUND_RED |        // 文字色_红色
		BACKGROUND_BLUE | BACKGROUND_GREEN/* | BACKGROUND_RED*/);      // 背景色_蓝绿色
	cout << "                    " << endl;
	cout << "      学生登录      " << endl;
	cout << "                    " << endl;
	SetConsoleTextAttribute(hOut,
		BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);//文字色_黑色，背景白色
	cout << "用户名："; cin >> username;
	cout << "密码（注意！密码将以明文出现）："; cin >> password;
	for (auto users : studentlist) {
		if (username == users.GetUsername()) {
			users.login(password);
		}
	}
}
