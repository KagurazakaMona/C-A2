#pragma once
#include"user.h"
#include<string>
using namespace std;

class admin:public user {
protected:
	void Menu();
	void StudentSignUp();
	void ListStudents();
public:
	admin() {};
	admin(string inputname, string inputusername, string inputpassword) :user(inputname, inputusername,inputpassword) {}
};

class superadmin:public admin { 
private:
	void Menu();
	void AdminSignUp();
	void ListAdmins();
public:
	superadmin();
	superadmin(string inputusername, string inputpassword) :admin(inputusername, inputusername, inputpassword) {}
};