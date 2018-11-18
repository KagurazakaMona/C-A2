#include <iostream>
#include "cube.h"
using namespace std;

void cube::input() {
	cout << "实验1-3，输入长方体的长宽高：（int）" << endl;
	cin >> length >> wide >> high;
}

void cube::display_Volue() {
	cout << "实验1-3，输出长方体的体积：" << endl;
	cout << cal_Volume() << endl;
}

int cube::cal_Volume() {
	return length * wide * high;
}