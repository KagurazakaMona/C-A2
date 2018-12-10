#pragma once
#include<vector>
#include<string>
#include<fstream>
#include"admin.h"
#include"book.h"
#include"student.h"
using namespace std;

class library {
private:
	superadmin root;
	static vector<admin> adminlist;
	static vector<student> studentlist;
	static vector<book> booklist;
	void AdminLogin();
	void StudentLogin();
	void Menu();
	void WriteFile();
	void LoadFile();
public:
	friend class superadmin;
	friend class student;
	friend class admin;
	library();
	static void AdminSignUp(string newname, string newusername, string newpassword);
	static void StudentSignUp(string newusername, string newpassword,string name,string se);
};
