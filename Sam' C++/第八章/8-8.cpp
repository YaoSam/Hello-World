/*
*
*������	 ��������������           ����+ +
*����  ���������������ߩ��������������ߩ� + +
*����  ��������������������       �� ��
*����  ������������������������  �� ++ + + +
*����  ����		  ��  ��������������  ��+
*����  ������������������������ �� +
*����  ����������������   �ߡ���  ��
*����  �������������������������� + +
*����  ���������������������� ������
*��������������������������������������������������
*���������������������������� + + + +
*������������������������������������Code is far away from bug with the animal protecting��������������
*���������������������������� + �����������ޱ���,������bug����
*����������������������������
*��������������������������������+������������������
*���������������������� �������������� + +
*�������������������� ���������������ǩ�
*�������������������� ������������������
*�����������������������������ש����� + + + +
*�����������������������ϩϡ����ϩ�
*�����������������������ߩ������ߩ�+ + + +
*/
#include <iostream>
#include <string>
using namespace std;

//#define DEBUG //����ȷ���Ƿ��ı������
#define Re(i,n)		for(int i=0;i<n;i++)

/*����˵��*/
/*Sample Input:

*/
class BaseClass
{
public:
	virtual void fn1() = 0;/*	{ cout << "I'm fn1 in BaseClass" << endl; }*/
	void fn2()	{ cout << "i'm fn2 in Baseclass" << endl; }
};


class DerivedClass:public BaseClass
{
public:
	void fn1()	{ cout << "I'm fn1 in DerivedClass" << endl; }
	void fn2(){ cout << "I'm fn2 in DerivedClass" << endl; }
};






int main()//���Ǵ������ú���~
{
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	DerivedClass Done;
	BaseClass *Bpointer= &Done;
	DerivedClass *Dpointer = &Done;
	Bpointer->fn1(); //û�ж���ֻ�����DerivedClass �е�fn1. ��������˶���Ҳû�á�
	Bpointer->fn2(); 
	Dpointer->fn1();
	Dpointer->fn2();
#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}