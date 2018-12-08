#include <iostream>
#include "Auto.h"
using namespace std;

int main() {
	Car car("晋A 172054213	", 4, 7);
	Truck truck("晋A songhaiyu", 8, 5.5);
	car.display();
	truck.display();
	system("pause");
	return 0;
}