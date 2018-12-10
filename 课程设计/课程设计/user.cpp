#include<iostream>
#include<Windows.h>
#include "user.h"
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