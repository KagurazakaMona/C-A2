#pragma once
#include<string>
using namespace std;

class book {
private:
	string isbn;
	string name;
	string location;
	int nowquantity;
	int totalquantity;
public:
	friend class admin;
	friend class superadmin;
	friend class student;
	book() {}
	book(string newisbn, string newname, string newlocation, int newquantity) : 
		isbn(newisbn), name(newname), location(newlocation), nowquantity(newquantity), totalquantity(newquantity) {};
	string GetIsbn();
	string GetName();
	string GetLocation();
	int GetNowquantity();
	int GetTotalquantity();
	void ListInformation();
};