#include "MatrixAdd.h"

MatrixAdd::MatrixAdd(int x[M][N]) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = x[i][j];
		}
	}
}

MatrixAdd MatrixAdd::operator+(MatrixAdd &b){
	MatrixAdd temp = b;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			temp.a[i][j] = b.a[i][j] + a[i][j];
		}
	}
	return temp;
}

//void MatrixAdd::operator=(MatrixAdd  &b){
//	for (int i = 0; i < M; i++) {
//		for (int j = 0; j < N; j++) {
//			a[i][j] = b.a[i][j];
//		}
//	}
//}

istream & operator>>(istream & is, MatrixAdd &c){
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> c.a[i][j];
		}
	}
	return is;
}

ostream & operator<<(ostream & os, MatrixAdd c){
	for (int i = 0; i < M; i++) {
		cout << '|';
		for (int j = 0; j < N; j++) {
			cout << setw(3) << c.a[i][j];
		}
		cout << "   |" << endl;
	}
	return os;
}
