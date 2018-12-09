#include "library.h"
#include <iostream>
#include <string>
#include <windows.h>//颜色
#include <stdio.h>//颜色
#include <stdlib.h>//颜色

using namespace std;

library::library() { 

}

void library::mainmenu()
{
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
	switch (choose)
	{
	case(1):AdminLogin(); break;
	case(2):StudentLogin(); break;
	default:
		break;
	}
}

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
	SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);//文字色_黑色，背景白色
	cout << "用户名："; cin >> username;
	cout << "密码（注意！密码将以明文出现）："; cin >> password;
	if (username == root.GetUsername()) {
		root.login(password);
	}
	else {
		for (auto user : admins) {
			if (username == user.GetUsername()) {
				user.login(password);
			}
		}
	}
}

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
	SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);//文字色_黑色，背景白色
	cout << "用户名："; cin >> username;
	cout << "密码（注意！密码将以明文出现）："; cin >> password;
	for (auto user : students) {
		if (username == user.GetUsername()) {
			user.login(password);
		}
	}
}
