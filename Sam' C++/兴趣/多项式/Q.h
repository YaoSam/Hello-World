#pragma once
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

#define Re(i,n)		for(int i=0;i<=n;i++) //����ʽ�����Re����һ�����⡣


int gcd(int m, int n)
{
	//cout << m << ' ' << n << endl;
	if (n == 0)return m;
	else return gcd(n, m%n);
}
#ifndef TEMPLATE
#define TEMPLATE
template <typename T>		T &operator+=(T &This, T const &num)		{ This = This + num; return This; }
template <typename T>		T &operator-=(T &This, T const &num)			{ This = This - num;	return This; }
template <typename T>		T &operator*=(T &This, T const &num)			{ This = This * num;	return This; }
template <typename T>		T &operator/=(T &This, T const &num)			{ This = This / num;	return This; }
template <typename T>		T &operator%=(T &This, T const &num)		{ This = This % num;	return This; }
//���������ص�>��==
template <typename T>		bool operator>=(T const &a, T const &b)			{ return a > b || a == b; }
template <typename T>		bool operator!=(T const &a, T const &b)			{ return !(a == b); }
template <typename T>		bool operator<(T const &a, T const &b)			{ return !(a > b || a == b); }
template <typename T>		bool operator<=(T const &a, T const &b)			{ return !(a > b); }
#endif // !TEMPLATE

/*����˵��*//*
Ŀ�ģ����������������㡣PS��Ϊ����ʽ��׼������Ϊ����ʽ�ĳ������漰ϵ������������float�Ͳ��ܵõ���ȷ�Ĵ𰸡�
�ȶ�����һ������������Q��
��ÿ���������ɻ��صķ��Ӻͷ�ĸ��ɡ�
�����������������������㣬����ÿһ��return�����˹��캯������֤�˻��ء�
Ҳ������^�����������㡣
���˴�����const������&���������ϼ������Ч�ʣ�Ҳ��ֹ�˲������޸ĵ������
		*/
class Fx;
class Q//����������
{
	int up, down; //���ӣ���ĸ
	friend class Fx;
	friend std::ostream &operator<<(std::ostream &out, Fx const &This);
public:
	Q() :up(0), down(1){}
	Q(int U, int D = 1);						//Ĭ��Ϊ�㡣ò�����븺��Ҳ�ǶԵ�... ...�����Ϊʲô��
	Q(double decimal);					//��������ת��Ϊ�����������ݶ���ȷֵΪС�����5λ��
	friend std::ostream &operator<<(std::ostream &out, Q const &This);
	Q operator==(const Q &other)const	{ return up*other.down == other.up*down; }
	Q operator>(const Q &other)const	{ return up*other.down > down*up; }
	//����ͨ��֮���ʽ�ӡ�Ȼ�����ù��캯�������ֻ��ء�PS��Ϊ�˼�����е��ѿ���
	Q operator+(const Q &other)const		{ return Q(up*other.down + down*other.up, down*other.down); }
	Q operator-(const Q &other)const		{ return Q(up*other.down - down*other.up, down*other.down); }
	Q operator*(const Q &other)const		{ return Q(up*other.up, down*other.down); }
	Q operator/(const Q &other)const		{ return Q(up*other.down, down*other.up); }
	Q operator^(int const &n)const				{ Q ans(1);	Re(i, n)	ans *= *this;	return ans; }
};
Q::Q(int U, int D)		//Ĭ��Ϊ�㡣ò�����븺��Ҳ�ǶԵ�... ...�����Ϊʲô��
{

	if (D == 0)
	{
		std::cout << "��ĸ����Ϊ��!" << std::endl;
		Q();
	}
	else
	{
		int g = gcd(U, D);
		up = U / g;
		down = D / g;
		if (down < 0)	up *= -1, down *= -1;
	}
}
Q::Q(double decimal)					//��������ת��Ϊ�����������ݶ���ȷֵΪС�����5λ��
{
	int U = (int)(100000 * decimal);
	int g = gcd(U, 100000);
	up = U / g;
	down = 100000 / g;
}
std::ostream &operator<<(std::ostream &out, Q const &This)
{
	out << This.up;
	if (This.down != 1)		out << '/' << This.down;
	return out;
}