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
	while (1) {
		HANDLE hOut;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);//  获取输出流的句柄
		SetConsoleTextAttribute(hOut,
			FOREGROUND_RED |        // 文字色_红色
			BACKGROUND_BLUE | BACKGROUND_GREEN/* | BACKGROUND_RED*/);      // 背景色_蓝绿色
		cout << "**********   图书馆管理系统   **********" << endl;
		cout << "***            管理员面板            ***" << endl;
		cout << "                                        " << endl;
		SetConsoleTextAttribute(hOut,
			BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);//文字色_黑色，背景白色
		cout << "菜单：" << endl;
		cout << "1.注册学生账号" << endl;
		cout << "2.柜台还书" << endl;
		cout << "3.图书检索" << endl;
		cout << "4.列出学生列表" << endl;
		cout << "5.删除学生账号" << endl;
		cout << "6.添加新书籍" << endl;
		cout << "0.退出" << endl;
		cout << "请输入选择序号：";
		int choose;
		cin >> choose;
		switch (choose) {
		case(1):StudentSignUp(); library::WriteFile(); break;
		case(2):ReturnBook(); library::WriteFile(); break;
		case(3):ListBook(); break;
		case(4):ListStudents(); break;
		case(5):DeleteStudent(); library::WriteFile(); break;
		case(6):BookSignUp(); library::WriteFile(); break;
		case(0):goto exit; break;
		default:
			break;
		}
	}
exit:;
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
		cout << "请输入新注册的学生姓名：";
		cin >> name;
		cout << "请输入新注册的学生学号：";
		cin >> number;
		cout << "请输入新注册学生的密码：";
		cin >> temp1;
		cout << "请再次输入新注册学生的密码：";
		cin >> temp2;
		if (temp1 == temp2) {
			library::StudentSignUp(number, temp2, name);
			break;
		}
		else {
			cout << "两次输入的密码不同，请重试！" << endl;
		}
	}
}

void admin::BookSignUp() {
	string location;
	int quantity;
	string isbn;
	string name;
	cout << "请输入新书名：";
	cin >> name;
	cout << "请输入新书ISBN：";
	cin >> isbn;
	cout << "请输入新书位置：";
	cin >> location;
	cout << "请输入新书数量：";
	cin >> quantity;
	library::BookSignUp(isbn, name, location, quantity);
	cout << "录入完成！" << endl;
}

/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：admin::ListStudent()
.					作用：输出学生信息。
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
		cout << setw(5) << "序号" << setw(20) << "学号（登录名）" << setw(20) << "姓名" << setw(15) << "现借书数量" <<
			setw(20) << "借书1.ISBN" << setw(20) << "借书2.ISBN" << setw(20) << "借书3.ISBN" << endl;
		SetConsoleTextAttribute(hOut,
			BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);//文字色_黑色，背景白色
		for (auto i : library::studentlist) {
			cout << setw(5) << num++;
			i.ShowInformation();
		}
	}
	else {
		cout << "没有学生！" << endl;
		SetConsoleTextAttribute(hOut,
			BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);//文字色_黑色，背景白色
	}
	system("pause");
}

/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：admin::DeleteStudent()
.					作用：删除学生信息。
.					输入值：None
.					类型：void
.					返回值：None

*//////////////////////////////////////////////////////////////////////////////
void admin::DeleteStudent() {
	string getusername;
	ListStudents();
	cout << "请输入要删除的用户名：";
	cin >> getusername;
	int i = 0;
	if (!library::studentlist.empty()) {
		bool havestudent = 0;
		for (auto users : library::studentlist) {
			if (getusername == users.GetUsername()) {
				library::studentlist.erase(library::studentlist.begin() + i);
				havestudent = 1;
			}
			i++;
		}
		if (!havestudent) {
			cout << "未查询到该学生，即将返回主菜单！" << endl;
		}
	}
	else {
		cout << "学生列表为空！" << endl;
	}
}

void admin::ReturnBook() {
	string studentnum;
	cout << "请输入学生学号：";
	cin >> studentnum;
	for (auto &students : library::studentlist) {
		if (students.GetUsername() == studentnum) {
			cout << students.name << "学生账号目前的信息如下：" << endl;
			students.ShowMyInformation();
			if (students.borrownumber) {
				cout << "请输入你要还书的ISBN：";
				string returnisbn;
				cin >> returnisbn;
				for (auto &i : students.borrowbooksisbn) {
					if (i == returnisbn) {
						for (auto &j : library::booklist) {
							if (j.GetIsbn() == returnisbn) {
								j.nowquantity++;
							}
						}
						i = "EMPTY";
						students.borrownumber--;
						cout << "还书成功！3秒后返回主菜单......" << endl;
						Sleep(3000);
					}
					else {
						cout << "该同学尚未借阅改书，请检查。" << endl;
					}
				}
			}
			else {
				cout << "该同学的账号无借书记录，请加强阅读哦喵~~~" << endl;
			}
			break;
		}
	}
}

superadmin::superadmin() {
	username = "root";
	password = "470026648";
}


/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：superadmin::Menu()
.					作用：超级管理员菜单。
.					输入值：None
.					类型：void
.					返回值：None

*//////////////////////////////////////////////////////////////////////////////
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
		cout << "3.列出所有图书" << endl;
		cout << "4.注册管理员账号" << endl;
		cout << "5.添加新书籍" << endl;
		cout << "6.列出学生账号列表" << endl;
		cout << "7.列出管理员账号与密码" << endl;
		cout << "8.删除学生账号" << endl;
		cout << "9.删除管理员账号" << endl;
		cout << "0.退出" << endl;
		cout << "请输入选择序号：";
		int choose;
		cin >> choose;
		switch (choose) {
		case(1):StudentSignUp(); library::WriteFile(); break;
		case(2):; break;
		case(3):ListBook(); break;
		case(4):AdminSignUp(); library::WriteFile(); break;
		case(5):BookSignUp(); library::WriteFile(); break;
		case(6):ListStudents(); break;
		case(7):ListAdmins(); break;
		case(8):DeleteStudent(); library::WriteFile(); break;
		case(9):DeleteAdmin(); library::WriteFile(); break;
		case(0):goto exit; break;
		default:
			cout << "输入错误！请重试。" << endl;
			Sleep(3000);
			break;
		}
	}
exit:;
}

/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：superadmin::AdminSignUp()
.					作用：注册新的管理员账户。
.					输入值：None
.					类型：void
.					返回值：None

*//////////////////////////////////////////////////////////////////////////////
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

/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：superadmin::ListAdmin()
.					作用：列出所有管理员账户的用户名与密码。
.					输入值：None
.					类型：void
.					返回值：None

*//////////////////////////////////////////////////////////////////////////////
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
			cout << setw(5) << num++ << setw(20) << i.GetName() << setw(20) << i.GetUsername() << setw(20) << i.GetPassword() << endl;
		}
	}
	else {
		cout << "没有管理员！" << endl;
		SetConsoleTextAttribute(hOut,
			BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);//文字色_黑色，背景白色
	}
}

/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：superadmin::DeleteAdmin()
.					作用：删除管理员账户。
.					输入值：None
.					类型：void
.					返回值：None

*//////////////////////////////////////////////////////////////////////////////
void superadmin::DeleteAdmin() {
	string getusername;
	ListAdmins();
	cout << "请输入要删除的用户名：";
	cin >> getusername;
	int i = 0;
	if (!library::adminlist.empty()) {
		for (auto &users : library::adminlist) {
			if (getusername == users.GetUsername()) {
				library::adminlist.erase(library::adminlist.begin() + i);
			}
			i++;
		}
	}
	else {
		cout << "管理员列表为空！" << endl;
	}
}
