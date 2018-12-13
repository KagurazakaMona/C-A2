#pragma once
#include<string>
#include<vector>
#include"user.h"
#include"book.h"
#include"library.h"
using namespace std;

class student:public user {
private:
	int borrownumber;
	vector<string> borrowbooksisbn;
	void Menu();
	void BorrowBook();
	void ReturnBook();
	void ShowMyInformation();
public:
	friend class admin;
	friend class superadmin;
	student();
	student(string inputusername, string inputpassword, string na);
	student(string inputusername, string inputpassword, string na, string bisbn[3], int bnumber);
	void ShowInformation();
	int GetBorroenumber();
	vector<string> GetBorrowbooksisbn();
};