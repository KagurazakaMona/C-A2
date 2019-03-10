#pragma once
#include<string>
using namespace std;

class user {
protected:
	string username;
	string password;
	string name;
	virtual void Menu() = 0;
	void ListBook();
	void ChangePassword();
public:
	user() {}
	user(string inputname, string inputusername, string inputpassword) :name(inputname), username(inputusername), password(inputpassword) {}
	void login(string getpassword);
	string GetUsername();
	string GetPassword();
	string GetName();
};