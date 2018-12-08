#include "Auto.h"
#include <iostream>

void Car::display()
{
	cout << "该小客车的信息如下：" << endl;
	cout << "车牌号：" << carid << endl;
	cout << "车轮数：" << wheelquantity << endl;
	cout << "核载人数：" << peoplenumber << endl;
}

void Truck::display()
{
	cout << "该大货车的信息如下：" << endl;
	cout << "车牌号：" << carid << endl;
	cout << "车轮数：" << wheelquantity << endl;
	cout << "核载吨数：" << tons << endl;
}
