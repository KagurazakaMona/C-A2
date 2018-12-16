#pragma once
#include<vector>
#include<string>
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
	void LoadFile();
public:
	friend class superadmin;
	friend class student;
	friend class admin;
	friend class book;
	friend class user;
	library();
	static void WriteFile();
	//static void AdminSignUp(string newname, string newusername, string newpassword);
	//static void StudentSignUp(string newusername, string newpassword, string name);
	//static void BookSignUp(string newisbn, string newname, string newlocation,int newquantity);
	
};
