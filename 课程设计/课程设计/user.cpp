#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
#include "user.h"
#include "library.h"
#include "book.h"
using namespace std;

void user::login(string getpassword) {
	if (getpassword == password) {
		cout << "登录成功！" << endl;
		Sleep(1000);
		Menu();
	}
	else {
		cout << "用户名或密码错误！" << endl;
		cout << "登录失败！" << endl;
		Sleep(3000);
	}
}

string user::GetUsername() {
	return username;
}

string user::GetPassword() {
	return password;
}

string user::GetName() {
	return name;
}

void user::ListBook() {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);//  获取输出流的句柄
	SetConsoleTextAttribute(hOut,
		FOREGROUND_RED |        // 文字色_红色
		BACKGROUND_BLUE | BACKGROUND_GREEN/* | BACKGROUND_RED*/);      // 背景色_蓝绿色
	int num = 1;
	if (!library::booklist.empty()) {
		cout << "本图书馆图书信息如下：" << endl;
		cout << setw(5) << "序号" << setw(30) << "书名" << setw(20) << "ISBN" << setw(20) << "位置" << setw(15) << "总数" << setw(15) << "在馆数" << endl;
		SetConsoleTextAttribute(hOut,
			BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);//文字色_黑色，背景白色
		for (auto i : library::booklist) {
			cout << setw(5) << num++ << setw(30) << i.GetName() << setw(20) << i.GetIsbn() << setw(20) << i.GetLocation() << setw(15) << i.GetTotalquantity()
				<< setw(15) << i.GetNowquantity() << endl;
		}
		cout << "请输入要检索的书（书名）（搜索任意字符跳过）：";
		string search;
		cin >> search;
		bool havebook = 0;
		for (auto books : library::booklist) {
			if (search == books.GetName()) {
				havebook = 1;
				books.ListInformation();
				break;
			}
		}
		if (!havebook) {
			cout << "用户跳过搜索或信息未查询到！" << endl;
		}
	}
	else {
		cout << "没有图书！" << endl;
		SetConsoleTextAttribute(hOut,
			BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);//文字色_黑色，背景白色
	}
}

void user::ChangePassword() {
	while (1) {
		getchar();
		string temp1, temp2;
		cout << "请确认要修改密码的用户名是：" << username << endl;
		cout << "确认请输入Y（区分大小写），按任意键退出。" << endl;
		if (getchar() == 'Y') {
			cout << "请输入新密码：";
			cin >> temp1;
			cout << "请再次输入新密码：";
			cin >> temp2;
			if (temp1 == temp2) {
				password = temp2;
				cout << "密码修改成功！（三秒后返回菜单）" << endl;
				Sleep(3000);
				break;
			}
			else {
				cout << "两次输入的密码不同，请重试！" << endl;
			}
		}
		else {
			cout << "取消修改密码！" << endl;
			break;
		}
	}
}
