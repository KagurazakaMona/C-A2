#include <iostream>
#include <iomanip>
#include <windows.h>//颜色
#include <stdio.h>//颜色
#include <stdlib.h>//颜色
#include "student.h"
using namespace std;

void student::Menu() {
	while (1) {
		system("CLS");
		HANDLE hOut;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);//  获取输出流的句柄
		SetConsoleTextAttribute(hOut,
			FOREGROUND_RED |        // 文字色_红色
			BACKGROUND_BLUE | BACKGROUND_GREEN/* | BACKGROUND_RED*/);      // 背景色_蓝绿色
		cout << "          *************   图书馆管理系统   *************          " << endl;
		cout << "          *******            学生菜单            *******          " << endl;
		cout << "                                                   www.moeneko.top" << endl;
		SetConsoleTextAttribute(hOut,
			BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);//文字色_黑色，背景白色
		cout << "菜单：" << endl;
		cout << "1.借书" << endl;
		cout << "2.还书" << endl;
		cout << "3.图书检索" << endl;
		cout << "4.显示个人信息" << endl;
		cout << "5.修改个人密码" << endl;
		cout << "0.退出" << endl;
		cout << "请输入选择序号：";
		int choose;
		cin >> choose;
		switch (choose) {
		case(1):BorrowBook(); library::WriteFile();  break;
		case(2):ReturnBook(); library::WriteFile(); break;
		case(3):ListBook(); system("pause"); break;
		case(4):ShowMyInformation(); system("pause"); break;
		case(5):ChangePassword(); library::WriteFile(); break;
		case(0):goto exit; break;
		default:
			cout << "输入错误！请重试。" << endl;
			Sleep(3000);
			break;
		}
	}
exit:;
}

void student::BorrowBook() {
	string isbn;
	cout << "请输入待借书的ISBN：";
	cin >> isbn;
	bool havebook = 0;
	for (auto &i : library::booklist) {
		if (isbn == i.isbn) {
			havebook = 1;
			cout << "成功查询到该书！" << endl;
			cout << "你要借阅的书目信息如下：" << endl;
			i.ListInformation();
			if (borrownumber < 3 && i.GetNowquantity() > 0) {
				cout << "系统正在登记，请稍后......" << endl;
				i.nowquantity--;
				borrownumber++;
				for (auto &j : borrowbooksisbn) {
					if (j == "EMPTY") {
						j = i.GetIsbn();
						break;
					}
				}
				cout << "登记成功！注意按时还书哦喵~~" << endl;
				Sleep(3000);
			}
			else {
				cout << "你已超过借书上限或该书已借完，请检查后重试！" << endl;
				Sleep(3000);
			}
			break;
		}
	}
	if (!havebook) {
		cout << "本图书馆未收藏本书，请检查后再次借书。" << endl;
		Sleep(3000);
	}
}

void student::ReturnBook() {
	cout << name << "  同学，你账号目前的信息如下：" << endl;
	ShowMyInformation();
	bool isreturnbook = 0;
	if (borrownumber) {
		cout << "请输入你要还书的ISBN：";
		string returnisbn;
		cin >> returnisbn;
		for (auto &i : borrowbooksisbn) {
			if (i == returnisbn) {
				for (auto &j : library::booklist) {
					if (j.GetIsbn() == returnisbn) {
						j.nowquantity++;
						break;
					}
				}
				i = "EMPTY";
				borrownumber--;
				isreturnbook = 1;
				cout << "还书成功！3秒后返回主菜单......" << endl;
				Sleep(3000);
				break;
			}
		}
	}
	else {
		cout << "你的账号无借书记录，请加强阅读哦喵~~~" << endl;
		isreturnbook++;
	}
	if (!isreturnbook) {
		cout << "你尚未借阅该书，请检查。" << endl;
	}
}

void student::ShowMyInformation() {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);//  获取输出流的句柄
	SetConsoleTextAttribute(hOut,
		FOREGROUND_RED |        // 文字色_红色
		BACKGROUND_BLUE | BACKGROUND_GREEN/* | BACKGROUND_RED*/);      // 背景色_蓝绿色
	cout << setw(20) << "学号（登录名）" << setw(20) << "姓名" << setw(15) << "现借书数量" <<
		setw(20) << "借书1.ISBN" << setw(20) << "借书2.ISBN" << setw(20) << "借书3.ISBN" << endl;
	SetConsoleTextAttribute(hOut,
		BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);//文字色_黑色，背景白色
	ShowInformation();
}

student::student() {
	borrownumber = 0;
	vector<book> borrowbooks(10);
}

student::student(string inputusername, string inputpassword, string na) :user(na, inputusername, inputpassword) {
	borrownumber = 0;
	vector<string> temp(3, "EMPTY");
	borrowbooksisbn = temp;
}


int student::GetBorroenumber() {
	return borrownumber;
}

vector<string>  student::GetBorrowbooksisbn() {
	return borrowbooksisbn;
}

student::student(string inputusername, string inputpassword, string na, string bisbn[3], int bnumber) :
	user(na, inputusername, inputpassword), borrownumber(bnumber) {
	for (int i = 0; i < 3; i++) {
		borrowbooksisbn.push_back(bisbn[i]);
	}
}

/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：student::ShowInformation()
.					作用：输出学生信息。
.					输入值：None
.					类型：void 
.					20 用户名 20 名字 15 借书数 endl

*//////////////////////////////////////////////////////////////////////////////
void student::ShowInformation() {
	cout << setw(20) << username << setw(20) << name << setw(15) << borrownumber;
	for (auto i : borrowbooksisbn) {
		cout << setw(20) << i;
	}
	cout << endl;
}
