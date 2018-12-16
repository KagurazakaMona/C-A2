#include "library.h"
//以下是静态函数的定义，不可删除
vector<admin> library::adminlist;
vector<student> library::studentlist;
vector<book> library::booklist;

/*/////////////////////////////////////////////////////////////////////////////

.			函数	名称：主函数main()
.					作用：程序入口。

*//////////////////////////////////////////////////////////////////////////////
int main() {
	system("color 70");//改变颜色
	system("mode con cols=130 lines=260");//改变宽高
	new library;
	return 0;
}