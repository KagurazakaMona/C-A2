#pragma once
#include"user.h"
#include<string>
using namespace std;

class admin:public user {
public:
	admin();
	admin(string inputusername, string inputpassword) :user(inputusername,inputpassword) {}
	void SignUp();
};

class superadmin:public admin { };