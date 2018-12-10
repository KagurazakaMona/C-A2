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
	vector<book> borrowbooks;
	void Menu();
	void SignUp();
public:
	student();
	student(string inputusername, string inputpassword, string na, string se) :user(na, inputusername, inputpassword), sex(se) {
		borrownumber = 0;
		vector<book> borrowbooks(10);
	}
	string GetSex();
	int GetBorroenumber();
};