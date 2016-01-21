#include <iostream>
#include "People.h"
using namespace std;
//#define DEBUG
void f1(People &one)//用来测试复制构造函数
{
	one.ShowPeople();
}
void f2(People one)
{
	one.ShowPeople();
}
int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	//cout << Gender[1] << Gender[0] << endl;
	cout << "建立一个日期" << endl;
	int date = 20150101;
	cout << "建立一个人" << endl;
	People You(10081, 0, "123456789012345678", 20150311);
	cout << "You.ShowPeople()" << endl;
	You.ShowPeople();
	cout << "f1:" << endl;
	f1(You);
	cout << "f2:" << endl;
	f2(You);
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}