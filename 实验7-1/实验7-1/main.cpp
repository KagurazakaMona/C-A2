#include"MatrixAdd.h"
int main() {
	int dd[2][3] = { 1,2,3,4,5,6 };
	MatrixAdd a(dd);
	MatrixAdd b, c;
	cin >> b;
	c = a + b;
	cout << c << endl;
	cout << b << endl;
	cout << a << endl;
	system("pause");
	return 0;
}