#include <iostream>
#include "People.h"
using namespace std;
//#define DEBUG
void f1(People &one)//�������Ը��ƹ��캯��
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
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	//cout << Gender[1] << Gender[0] << endl;
	cout << "����һ������" << endl;
	int date = 20150101;
	cout << "����һ����" << endl;
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