#include "library.h"
vector<admin> library::adminlist;
vector<student> library::studentlist;
vector<book> library::booklist;

/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：主函数main()
.					作用：程序入口。
.					输入值：五
.					类型：int
.					返回值：正确运行为“0”。

*//////////////////////////////////////////////////////////////////////////////
int main() {
	system("mode con cols=120 lines=260");//改变宽高
	new library;
	return 0;
}