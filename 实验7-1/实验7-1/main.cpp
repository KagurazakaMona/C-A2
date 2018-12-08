#include"MatrixAdd.h"
int main() {
	int dd[2][3] = { 1,2,3,4,5,6 };
	MatrixAdd a(dd);
	MatrixAdd b, c;
	cin >> b;
	c = a + b;
	cout << "a矩阵为：" << endl;
	cout << a << endl;
	cout << "b矩阵为：" << endl;
	cout << b << endl;
	cout << "a + b 矩阵为：" << endl;
	cout << c << endl;
	system("pause");
	return 0;
}