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
#include "LinkList.h"

using namespace std;

#define DEBUG //����ȷ���Ƿ��ı������
#ifndef re
#define re(i,n)  for(int i=0;i<n;i++)
#endif // !re(i,n)

#ifndef Re
#define Re(i,n)	for(int i=1;i<=n;i++) //ѭ��n��
#endif // !Re(i,n)

void debug(string warning)
{
	cerr << warning << endl;
	system("pause");
	exit(1);
}

int main()
{
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif

	try	{
		srand(time(NULL));
		cout << "hello everyone" << endl;
		int a[1000];
		re(i, 1000)
			a[i] = rand() % 100;
		re(i, 50)
			cout << a[i] << ' ';
		cout << endl;
		LinkList<int> one(a, 10);
		one.PrintList();
		one.Insert(1, 11111);
		one.Insert(3, 23333);
		one.PrintList();
		one.Delete(3);
		one.PrintList();

		re(i, 10)
			cout << one.find(a[i]) << " " << one.Get(i + 1) << ' ' << endl;
		re(i, 11)
		{
			one.Delete(10 - i);
			cout << one.Length() << endl;
			one.PrintList();
		}
	}
	catch(string a)
	{
		cout<<a<<endl;
	}
#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}