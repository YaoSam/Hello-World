/*
*
*������	 ��������   ������		 ����+ +
*����  ���������������ߩ��������������ߩ� + +
*����  ��������������������       �� ��
*����  ������������������������ �� ++ + + +
*����  ����		   ��  ��������������  ��+
*����  �������������������������� +
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
#include <time.h>
#include "CirQuene.h"
#include "C:\Users\Sam\OneDrive\C++\���ݽṹ\�����£�ջ�Ͷ��У�\ջ\Stack.h"
using namespace std;

#define DEBUG //����ȷ���Ƿ��ı������
#ifndef re(i,n)
#define re(i,n) for(unsigned int i=0;i<n;i++)
#endif // !re(i,n)
#ifndef Re(i,n)
#define Re(i,n)		for(unsigned int i=1;i<=n;i++) //ѭ��n��
#endif // !Re(i,n)

int main()
{
	srand(time(NULL));
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	try{
		int num;
		StackInt one;
		int n;
		cin >> n;
		re(i,n)
		{
			cin >> num;
			one.push(num);
		}
		CirQuene<int> quene;
		re(i, n)
			quene.push(one.pop());
		re(i,n/2)
		{
			one.push(quene.pop());
			quene.push(quene.pop());
		}
		re(i, n / 2)
			one.push(quene.pop());
		while (!one.isEmpty())
			cout << one.pop() << ' ';
		cout << endl;
	}
	catch (const char*a)
	{
		cout<<a<<endl;
	}

#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}