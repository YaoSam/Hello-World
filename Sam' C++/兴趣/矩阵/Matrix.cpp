/**
*������������������������������+ +
*����������		�������ߩ��������ߩ� + +
*����������		��������������	�� ��
*����������		������������������ ++ + + +
*����������		 ������������������	��+
*����������		��������������	�� +
*����������		�����������ߡ�����
*����������		������������������ + +
*����������		��������������������
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
#include "Matrix.h"
using namespace std;

#define DEBUG

/*����ע��*/
/*Sample Input:
2 3
1 2 3 4 5 6
2 3
3 4 5 6 7 8
*/

//Sample output
/*
1  2  3
4  5  6

3  4  5
6  7  8

4  6  8
10  12  14
*/


class Complex{
	double real, img;
public:
	Complex(double a = 0, double b = 0):real(a), img(b){}
	friend Complex operator+(const Complex & a, const Complex &b){ return Complex(a.real + b.real, a.img + b.img); }
	friend ostream &operator<<(ostream &out, const Complex& other){ return out << other.real << '+' << other.img << 'i'; }
};





int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	Complex a(1, 2);
	double d = 1.23;
	Complex &ua=Complex(1);
	cout << ua << endl;
	cout << a + d << endl;
	//Matrix one,two;
	//cin >> one;
	//cout << one.rref() << endl;
	//float a;
	//cin>>a;
	//Q b=a;
	//cout<<b<<endl;
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}