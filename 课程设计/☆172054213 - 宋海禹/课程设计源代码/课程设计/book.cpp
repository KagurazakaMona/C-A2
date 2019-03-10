#include "book.h"
#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
using namespace std;

string book::GetIsbn() {
	return isbn;
}
string book::GetName() {
	return name;
}
string book::GetLocation() {
	return location;
}
int book::GetNowquantity() {
	return nowquantity;
}
int book::GetTotalquantity() {
	return totalquantity;
}

/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：book::ListInformation()
.					作用：输出书籍信息。

*//////////////////////////////////////////////////////////////////////////////
void book::ListInformation() {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);//  获取输出流的句柄
	SetConsoleTextAttribute(hOut,
		FOREGROUND_RED |        // 文字色_红色
		BACKGROUND_BLUE | BACKGROUND_GREEN/* | BACKGROUND_RED*/);      // 背景色_蓝绿色
	cout << setw(5) << "序号" << setw(30) << "书名" << setw(20) << "ISBN" << setw(20) << "位置" << setw(15) << "总数" << setw(15) << "在馆数" << endl;
	SetConsoleTextAttribute(hOut,
		BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);//文字色_黑色，背景白色
	cout << setw(5) << '1' << setw(30) << GetName() << setw(20) << GetIsbn() << setw(20) << GetLocation() << setw(15) << GetTotalquantity()
		<< setw(15) << GetNowquantity() << endl;
}
