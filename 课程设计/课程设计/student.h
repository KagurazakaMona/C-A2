#pragma once
#include<string>
#include<vector>
#include"user.h"
#include"book.h"
using namespace std;

class student:public user {
private:
	string sex;
	int borrownumber;
	vector<string> borrowbooksisbn;
	void Menu();
	void SignUp();
public:
	student();
	student(string inputusername, string inputpassword, string na, string se) :user(na, inputusername, inputpassword), sex(se) {
		borrownumber = 0;
		vector<string> borrowbooksisbn(10);
	}
	void ShowInformation();
	string GetSex();
	int GetBorroenumber();
	vector<string> GetBorrowbooksisbn();
};