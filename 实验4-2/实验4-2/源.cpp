#include<iostream>
#include<string>
using namespace std;
class Employee {
private:
	string name;
	char sex;
	int num;
	int wage;
	static int totalWage;
	static int count;
public:
	Employee() {
		cin >> name >> sex >> num >> wage;
	};
	void showBase() {
		cout << "���" << num << endl;
		cout << "����" << name << endl;
		cout << "�Ա�" << sex << endl;
		cout << "����" << wage << endl;
	}
	static void ShowStatic() {
		cout << "����" << count << endl;
		cout << "�ܹ���" << totalWage << endl;
	}
	void total() {
		count++;
		totalWage += wage;
	}
};
int Employee::totalWage = 0;
int Employee::count = 0;
int main() {
	int i;
	Employee t[3];
	for (i = 0; i < 3; i++) {
		t[i].showBase();
		t[i].total();
	}
	Employee::ShowStatic();
	system("pause");
	return 0;
}

