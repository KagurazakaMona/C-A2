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

*//////////////////////////////////////////////////////////////////////////////
library::library() {
	Menu();
}

/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：library::Menu()
.					作用：图书馆程序登录菜单。

*//////////////////////////////////////////////////////////////////////////////
void library::Menu() {
	LoadFile();
	while (1) {
		system("CLS");
		HANDLE hOut;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);//  获取输出流的句柄
		SetConsoleTextAttribute(hOut,
			FOREGROUND_RED |        // 文字色_红色
			BACKGROUND_BLUE | BACKGROUND_GREEN/* | BACKGROUND_RED*/);      // 背景色_蓝绿色
		cout << "172054213宋海禹                                                   " << endl;
		cout << "          *************   图书馆管理系统   *************          " << endl;
		cout << "                                                   www.moeneko.top" << endl;
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

*//////////////////////////////////////////////////////////////////////////////
void library::WriteFile() {
	ofstream outfile;
	outfile.open("MonaLibrary.csv", ios::out | ios::trunc);
	outfile << "DATABEGIN," << endl;
	outfile << "类型,ISBN,书名,位置,现有数量,总数," << endl;
	for (auto i : booklist) {
		outfile << "bo,";
		outfile << i.GetIsbn() <<','<< i.GetName() << ',' << i.GetLocation() << ',' << i.GetNowquantity() << ',' << i.GetTotalquantity() << ',' << endl;
	}
	outfile << "类型,名字,用户名,密码," << endl;
	for (auto i : adminlist) {
		outfile << "ad,";
		outfile << i.GetName() << ',' << i.GetUsername() << ',' << i.GetPassword() << ',' << endl;
	}
	outfile << "类型,名字,用户名,密码,借书数量,所借书籍," << endl;
	for (auto i : studentlist) {
		outfile << "st,";
		outfile << i.GetName() << ',' << i.GetUsername() << ',' << i.GetPassword() << ',' << i.GetBorrownumber() << ',';
		for (auto j : i.GetBorrowbooksisbn()) {
			outfile << j << ',';
		}
		outfile << endl;
	}
	outfile << "DATAEND,";
	outfile.close();
}

/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：library::LoadFile()
.					作用：读取文件。

*//////////////////////////////////////////////////////////////////////////////
void library::LoadFile() {
	ifstream infile;
	const int sleeptime = 30;
	infile.open("MonaLibrary.csv", ios::in);
	if (infile) {
		vector<string> temp;
		do {
			char line[256];
			infile.getline(line, 256, ',');
			temp.push_back(line);
		} while (temp[temp.size() - 1] != "\nDATAEND");
		auto tempsize = temp.size();
		for (int i = 0; i < tempsize; i++) {
			if (temp[i] == "\nbo") {
				booklist.push_back(book(temp[i + 1], temp[i + 2], temp[i + 3], stoi(temp[i + 4]), stoi(temp[i + 5])));
				cout << temp[i] << "正在读取数据" << temp[i + 1] << temp[i + 2] << temp[i + 3] << temp[i + 4] << temp[i + 5] 
					<< "，          已完成 " << 100.0 * i / tempsize << "% 请稍后......";
				Sleep(sleeptime);
				i += 5;
			}
			else if (temp[i] == "\nad") {
				adminlist.push_back(admin(temp[i + 1], temp[i + 2], temp[i + 3]));
				cout << temp[i] << "正在读取数据" << temp[i + 1] << temp[i + 2] << temp[i + 3]
					<< "，          已完成 " << 100.0 * i / tempsize << "% 请稍后......";
				Sleep(sleeptime);
				i += 3;
			}
			else if (temp[i] == "\nst") {
				string borrowisbn[3];
				for (int j = 5; j <= 7; j++) {
					borrowisbn[j - 5] = temp[i + j];
				}
				studentlist.push_back(student(temp[i + 2], temp[i + 3], temp[i + 1], borrowisbn, stoi(temp[i + 4])));
				cout << temp[i] << "正在读取数据" << temp[i + 1] << temp[i + 2] << temp[i + 3] << temp[i + 4] << temp[i + 5] << temp[i + 6] << temp[i + 7]
					<< "，          已完成 " << 100.0 * i / tempsize << "% 请稍后......";
				Sleep(sleeptime);
				i += 7;
			}
		}
		infile.close();
	}
	else {
		cout << "打开文件失败！" << endl;
		cout << "正在新建图书馆" << endl;
		Sleep(1000);
	}
}
//
///*/////////////////////////////////////////////////////////////////////////////
//
//.			函数	名称：library::AdminSignUp()
//.					作用：学生、管理员、书籍注册登记。
//
//*//////////////////////////////////////////////////////////////////////////////
//void library::StudentSignUp(string newusername, string newpassword, string name) {
//	studentlist.push_back(student(newusername, newpassword, name));
//}

//void library::AdminSignUp(string newname, string newusername, string newpassword) {
//	adminlist.push_back(admin(newname, newusername, newpassword));
//}

//void library::BookSignUp(string newisbn, string newname, string newlocation, int newquantity) {
//	booklist.push_back(book(newisbn, newname, newlocation, newquantity));
//}

/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：library::AdminLogin()
.					作用：管理员账户登录。

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
		bool haveuser = 0;
		for (auto &users : adminlist) {
			if (username == users.GetUsername()) {
				haveuser = 1;
				users.login(password);
				break;
			}
		}
		if (!haveuser) {
			cout << "用户名或密码错误！" << endl;
		}
	}
}

/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：library::StudentLogin()
.					作用：学生账户登录。

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
	bool haveuser = 0;
	for (auto &users : studentlist) {
		if (username == users.GetUsername()) {
			haveuser = 1;
			users.login(password);
			break;
		}
	}
	if (!haveuser) {
		cout << "用户名或密码错误！" << endl;
	}
}
