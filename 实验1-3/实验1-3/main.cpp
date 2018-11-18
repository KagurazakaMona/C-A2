#include <iostream>
#include "cube.h"
using namespace std;

int main() {
	cube box[3];
	int i;
	for (i = 0; i < 3; i++) {
		box[i].input();
	}
	for (i = 0; i < 3; i++) {
		box[i].display_Volue();
	}
	system("pause");
	return 0;
}