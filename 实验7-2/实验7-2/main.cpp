#include"Time.h"

int main() {
	Date a(2018, 11, 18);
	Date b(2010, 1, 1);
	Date c;
	int temp = 100;
	c = (b + temp);
	cout << "备注：加减法的天数是100天" << endl;
	cout << "加法：" << endl;
	cout << c;
	c = (b - temp);
	cout << "减法：" << endl;
	cout << c;
	cout << "日期相减：" << endl;
	cout << a << " - " << b << " = ";
	cout << a - b << endl;
	system("pause");
	return 0;
}