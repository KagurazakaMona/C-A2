#include <iostream>
#include"bulk.h"
using namespace std;

void bulk::get_value() {
	cout << "请输入长方体有关数据" << endl;
	cout << "请输入长（length）：";
	cin >> length;
	cout << "请输入宽（wide）：";
	cin >> width;
	cout << "请输入高（high）：";
	cin >> heigth;
}

void bulk::output() {
	cout << "长方体的体积是：" << length * width*heigth
		<< "     该长方体的表面积是：" 
		<< 2 * (length*width + width * heigth + length * heigth) 
		<< endl;
}
