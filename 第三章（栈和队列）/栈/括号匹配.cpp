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
#include "Stack.h"

using namespace std;


#define DEBUG //����ȷ���Ƿ��ı������
#ifndef re(i,n)
#define re(i,n) for(unsigned int i=0;i<n;i++)
#endif // !re(i,n)
#ifndef Re(i,n)
#define Re(i,n)		for(unsigned int i=1;i<=n;i++) //ѭ��n��
#endif // !Re(i,n)

void debug(string warning)
{
	cerr << warning << endl;
	system("pause");
	exit(1);
}


int main()
{
	srand(time(NULL));
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	char input[100000];
	cin>>input;
	int count=0;
	while (input[++count] != '\0');
	StackChar one;
	try
	{
		re(i, count)
		{
			if (input[i] == '(')
				one.push('(');
			else
				one.pop();
		}
		cout << one.top << endl;
	}
	catch (const Exception &a)
	{
		cout << a << endl;
	}
	//catch (const char *e)
	//{
	//	cout << e << endl;
	//}

#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}