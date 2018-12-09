#pragma once
#include <string>
using namespace std;

class user {
protected:
	string username;
	string password;
	virtual void Menu() = 0;
public:
	user();
	user(string inputusername, string inputpassword) :username(inputusername), password(inputpassword) {}
	void login(string getpassword);
	string GetUsername();
	void SignUp();
};