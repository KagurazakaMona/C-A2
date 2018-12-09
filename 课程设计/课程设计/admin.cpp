#include "admin.h"
#include<string>
#include<iostream>
#include<Windows.h>
using namespace std;

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
	case(1):AdminLogin(); break;
	default:
		break;
	}
}

admin::admin(){

}





void admin::SignUp() {
	string temp1, temp2;
	cout << "请输入新注册的管理员用户名：";
	cin >> username;
	cout << "请输入新注册的管理员密码：";
	cin >> temp1;
	cout << "请再次输入新注册的管理员密码：";
	cin >> temp2;
	if (temp1 == temp2) {
		password = temp2;
	}
}

superadmin::superadmin() {
	username = "root";
	password = "470026648";
}
