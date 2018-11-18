#include "Time.h"

int Date::month_Day()
{
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	else if (month == 2) {
		if (year % 4 == 0) {
			return 29;
		}
		else {
			return 28;
		}
	}
	else {
		return 31;
	}
}

bool Date::operator<(Date & af)
{
	if (year < af.year) {
		return true;
	}
	else if (year == af.year) {
		if (month < af.month) {
			return true;
		}
		else if (month == af.month) {
			if (day < af.day) {
				return true;
			}
		}
	}
	return false;
}

Date Date::operator+(int days)
{
	Date temp(year, month, day);
	temp.day += days;
	while (temp.day > temp.month_Day()) {
		temp.day -= temp.month_Day();
		if (temp.month == 12) {
			temp.month -= 12;//因为待会儿还要再加上一个月，所以这里需要减到0。
			temp.year++;
		}
		temp.month++;
	}
	return temp;
}

Date Date::operator-(int days)
{
	Date temp(year, month, day);
	temp.day -= days;
	while (temp.day < 1) {
		temp.day += temp.month_Day();
		if (temp.month == 1) {
			temp.month += 12;//因为待会儿还要再减去一个月，所以这里需要加到13。
			temp.year--;
		}
		temp.month--;
	}
	return temp;
}

int Date::operator-(Date & d)
{
	Date b(year, month, day);
	Date s = d;
	if (b < s) {
		swap(b, s);
	}
	int result = 0;
	//y = year - d.year;
	//m = month - d.month;
	for (s.year; s.year < b.year; s.year++) {
		if (s.year % 4 == 0) {
			result += 366;
		}
		else {
			result += 365;
		}
	}
	for (s.month; s.month < b.month; s.month++) {
		result += s.month_Day();
	}
	result += b.day - s.day;
	return result;
}

istream & operator>>(istream & is, Date c)
{
	cin >> c.year >> c.month >> c.day;
	return is;
	// TODO: 在此处插入 return 语句
}

ostream & operator<<(ostream & os, Date &c)
{
	cout << c.year << "/" << c.month << '/' << c.day << endl;
	return os;
	// TODO: 在此处插入 return 语句
}
