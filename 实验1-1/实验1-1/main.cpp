#include <iostream>
using namespace std;
class Time{//定义Time类
private:
	int hour;
	int minute;
	int sec;
public:
	void input() {
		cout << "实验1-1时间输入：(时分秒）" << endl;
		cin >> hour >> minute >> sec;
	}
	void display() {
		cout << "实验1-1时间输出：(时分秒）" << endl;
		cout << hour << "：" << minute << "：" << sec << endl;
	}
};
int main(){
	Time tl;
	tl.input();
	tl.display();
	system("pause");
	return 0;
}
