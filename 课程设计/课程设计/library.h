#pragma once
#include<vector>
#include"admin.h"
#include"book.h"
#include"student.h"
//#include<string>
//using namespace std;

class library {
private:
	superadmin root;
	vector<admin> admins;
	vector<student> students;
	vector<book> books;
	void AdminLogin();
	void StudentLogin();
public:
	library();
	void mainmenu();
};