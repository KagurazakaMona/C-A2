#include <iostream>  
using namespace std;
class Student{
public:
	Student(int n = -1, double s = -1) :score(s), num(n) {}
	void display();
	double get_Score();
	int get_Num();
private:
	int num;   //学号  
	double score;   //成绩  
};

//以下是函数声明：
//max函数返回arr指向的对象数组中的最高成绩（max并不是成员函数，而是普通数）
int max(Student *arr);

int main(){
	Student stud[5] = {
		Student(101,78.5),Student(102,85.5),Student(103,100),
		Student(104,98.5),Student(105,95.5)
	};
	//输出第1、3、5个学生的信息（用循环语句）
	int i;
	Student *p = &stud[0];
	for (i = 0; i < 3; i ++) {
		p->display();
		p += 2;
	}
	//输出成绩最高者的学号  
	cout << "5个学生中成绩最高者的学号为: " << max(stud) << endl;//调用函数显示最高绩  
	system("pause");
	return 0;
}

//定义函数max，返回arr指向的对象数组中的最高成绩  //求最高成绩及对应同学的学号  
int max(Student *arr){
	int i;
	Student max;
	max = arr[0];
	for (i = 1; i < 5; i++) {
		if (arr[i].get_Score() > max.get_Score()) {
			max = arr[i];
		}
	}
	int num = max.get_Num();
	return num;
	//返回最高成绩者的学号  
}

void Student::display() {
	cout << "该学生的学号是：" << num << "     成绩是：" << score << endl;
}

double Student::get_Score() {
	return score;
}

int Student::get_Num() {
	return num;
}