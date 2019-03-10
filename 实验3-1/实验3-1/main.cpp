#include <iostream>
#include"bulk.h"
using namespace std;
int main() {
	bulk b[5] = {
		bulk(2.3, 4.5, 6.7) ,
		bulk(1.5, 3.4),
		bulk(10.5)
	};
	b[4].get_value();
	int i;
	for (i = 0; i < 5; i++) {
		cout << "第 " << i + 1 << " 个";
		b[i].output();
	}
	system("pause");
	return 0;
}