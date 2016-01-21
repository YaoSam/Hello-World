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

unsigned int ten[10] = { 1, 10, 100, 1000, 10000, 100000, 1000000 };
bool isnum(char a)
{
	return (a >= '0'&&a <= '9');
}
int priority[1000] = { 0 };
double caculate(double a,double b,char oper)
{
	if (oper == '*')			return a*b;
	else if (oper == '/')	return a / b;
	else if (oper == '+')	return a + b;
	else if (oper == '-')	return a - b;
	else
		throw "�޷�ʶ��";
}

int main()
{
	srand(time(NULL));
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	StackChar Oper;
	Stack<double> num;
	priority[int('(')] = 5;
	priority[int(')')] = 5;
	priority[int('*')] = 4;
	priority[int('/')] = 4;
	priority[int('+')] = 3;
	priority[int('-')] = 3;
	priority[int('#')] = 1;
	try
	{
		char str[1000];
		cin >> str;
		int i = 0, count = 0;
		StackInt temp;
		int sum = 0;
		bool numflag = 0;
		while (str[i] != '\0')
		{
			//��������
			while (isnum(str[i]))
			{
				temp.push((str[i] - '0'));
				i++;
				numflag = 1;
			}
			if (numflag)
			{
				count = 0;
				sum = 0;
				while (!temp.isEmpty())
					sum += ten[count++] * temp.pop();	//�����ǽṹ�塣��װ�ԾͲ����ˡ�
				cout << sum << endl;
				num.push(sum);
				numflag = 0;
			}
			
			if (str[i]==')')
			{
				Oper.pop();
			}
			else if (Oper.isEmpty()||priority[str[i]] > priority[Oper.GetTop()])
				Oper.push(str[i]);
			else if (priority[str[i]] == priority[Oper.GetTop()])
			{
				if (str[i] == '#')	break;
				num.push(caculate(num.pop(), num.pop(), Oper.pop()));
				Oper.push(str[i]);
			}
			else	
			{
				num.push(caculate(num.pop(), num.pop(), Oper.pop()));
				i--;
			}
		
			i++;
		}
	}
	catch (const char* a)
	{
		cout << a << endl;
	}
	cout << num.pop() << endl;



#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}