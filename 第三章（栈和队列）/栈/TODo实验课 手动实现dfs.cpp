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



int n=5;
bool flag[100];
int bag[100];

void print()
{
	int sum=0;
	re(i, n)
	{
		sum += flag[i] ? bag[i] : 0;
		cout << bag[i] << ": " << flag[i] << ' ';
	}
	cout << endl << sum << endl;
}


int main()
{
	srand(time(NULL));
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	Stack<int> stack;
	re(i, n)
		cin >> bag[i];
	stack(-1);
	while (!stack.isEmpty())
	{
		if (stack.Top() == n)
		{
			print();
			stack();
		}
		else
		{
			int a = stack.GetTop();
			if (a==-1)
			{
				stack();
				stack(0);
				flag[stack.Top()] = 0;
				stack(-1);
			}
			else if (a==0)
			{
				stack();
				stack(1);
				flag[stack.Top()] = 1;
				stack(-1);
			}
			else
			{
				stack();
			}
		}
	}
#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}