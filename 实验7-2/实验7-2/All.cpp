#include"Time.h"

int main() {
	Date a(2018, 11, 18);
	Date b(2010, 1, 1);
	Date c;
	int temp = 100;
	c = (b + temp);
	cout << "�ӷ���" << endl;
	cout << c;
	c = (b - temp);
	cout << "������" << endl;
	cout << c;
	cout << "���������" << endl;
	cout << a - b << endl;
	system("pause");
	return 0;
}