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

class point
{
	int x, y;
public:
	point(int m=0, int n=0) :x(m), y(n){}
	point &operator++(int)		{ x++; y++;							return *this; }
	point operator++()			{ point temp(*this); ++(*this); return temp; }
	point &operator--(int)		{ x--, y--;								return *this; }
	point operator--()				{ point temp; --(*this);			return temp; }
	friend ostream &operator<<(ostream &out, point const &This); 
};	
ostream &operator<<(ostream &out, point const &This)
{
	out << '(' << This.x << ',' << This.y << ')';
	return out;
}




int main()//���Ǵ������ú���~
{
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	point one(1, 2);
	one++;
	cout << one << endl;
	Re(i, 100)one--;
	cout << one << endl;

#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}