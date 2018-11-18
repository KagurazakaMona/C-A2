#include <iostream>
using namespace std;
class Date {
public:
	Date(int, int, int);//修改代码，把这一行去掉
	Date(int, int);//修改代码，把这一行去掉
	Date(int);//修改代码，把这一行去掉
	Date();//修改代码，把这一行去掉
	Date(int = 1, int = 1, int = 2005);
	void display();
private:
	int month;
	int day;
	int year;
};

Date::Date(int m, int d, int y) : month(m), day(d), year(y) {  };

Date::Date(int m, int d) :month(m), day(d) {
	year = 2005;
}

Date::Date(int m) : month(m) {
	year = 2005;
	day = 1;
}

Date::Date() {
	month = 1;
	day = 1;
	year = 2005;
}

void Date::display() {
	cout << month << "/" << day << "/" << year << endl;
}

int main() {
	Date d1(10, 13, 2005);
	Date d2(12, 30);
	Date d3(10);
	Date d4;
	d1.display();
	d2.display();
	d3.display();
	d4.display();
	system("pause");
	return 0;
}