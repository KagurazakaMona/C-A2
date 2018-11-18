#pragma once
#include<iostream>
#include<iomanip>
using namespace std;

static const int M = 2;
static const int N = 3;

class MatrixAdd {
private:
	int a[M][N];
public:
	MatrixAdd() {};
	MatrixAdd(int x[M][N]);
	MatrixAdd operator+(MatrixAdd &b);
	//void operator=(MatrixAdd &b);
	friend istream &operator>>(istream &is, MatrixAdd &c);
	friend ostream &operator<<(ostream &os, MatrixAdd c);
};