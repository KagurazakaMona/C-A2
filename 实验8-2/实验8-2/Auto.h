#pragma once
#include<string>
using namespace std;

class Auto {
protected:
	string carid;
	int wheelquantity;
public:
	Auto() {}
	Auto(string incarid, int inwhellquantity) :carid(incarid), wheelquantity(inwhellquantity) {}
	virtual void display() = 0;
};

class Car :public Auto {
private:
	int peoplenumber;
public:
	Car(string incarid, int inwhellquantity, int inpeoplenumble) :peoplenumber(inpeoplenumble), Auto(incarid, inwhellquantity) {}
	void display();
};

class Truck :public Auto {
private:
	double tons;
public:
	Truck(string incarid, int inwhellquantity, double intons):tons(intons), Auto(incarid, inwhellquantity) {}
	void display();
};