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
}

string user::GetUsername() {
	return username;
}
