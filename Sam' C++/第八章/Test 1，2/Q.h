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
#define  Re(i,n) for(int i=1;i<=n;i++)	//��1ѭ����n
//Debug�ú�������Ȼһ������ö�����... ...
void debug(std::string warning) 
{
	std::cout << warning << std::endl;
	system("pause");
	exit(1);
}

int gcd(int m, int n) //���Լ��
{
	if (n == 0)return m;
	else return gcd(n, m%n);
}

/*����˵��*//*
Ŀ�ģ����������������㡣PS��Ϊ����ʽ��׼������Ϊ����ʽ�ĳ������漰ϵ������������float�Ͳ��ܵõ���ȷ�Ĵ𰸡�
�ȶ�����һ������������Q��
��ÿ���������ɻ��صķ��Ӻͷ�ĸ��ɡ�
�����������������������㣬����ÿһ��return�����˹��캯������֤�˻��ء�
Ҳ������^�����������㡣
���˴�����const������&���������ϼ������Ч�ʣ�Ҳ��ֹ�˲������޸ĵ������
		*/
class Q//����������
{
	int up, down; //���ӣ���ĸ
public:
	Q(int U=0, int D = 1);					//Ĭ��Ϊ�㡣ò�����븺��Ҳ�ǶԵ�... ...�����Ϊʲô��
	Q(double decimal);					//��������ת��Ϊ�����������ݶ���ȷֵΪС�����5λ��
	friend std::ostream &operator<<(std::ostream &out, Q const &This);
	friend bool operator==(const Q &a, const Q &b)		{ return a.up*b.down == b.up*a.down; }
	friend bool operator>(const Q &a, const Q &b)			{ return a.up*b.down > a.down*b.up; }
	//����ͨ��֮���ʽ�ӡ�Ȼ�����ù��캯�������ֻ��ء�PS��Ϊ�˼�����е��ѿ���
	friend Q operator+(const Q &a, const Q &b)					{ return Q(a.up*b.down + a.down*b.up, a.down*b.down); }
	friend Q operator-(const Q &a, const Q &b)					{ return Q(a.up*b.down - a.down*b.up, a.down*b.down); }
	friend Q operator*(const Q &a, const Q &b)					{ return Q(a.up*b.up, a.down*b.down); }
	friend Q operator/(const Q &a, const Q &b)					{ return Q(a.up*b.down, a.down*b.up); }
	Q&operator+=(const Q &other)		{ *this = *this + other; return *this; }
	Q&operator-=(const Q &other)		{ *this = *this - other; return *this; }
	Q&operator*=(const Q &other)		{ *this = *this * other; return *this; }
	Q&operator/=(const Q &other)			{ *this = *this / other; return *this; }
	Q operator^(int const &n)const			{ Q ans(1);		for (int i = 1; i <= n;i++)ans *= *this;	return ans; }
};
Q::Q(int U, int D)		//Ĭ��Ϊ�㡣ò�����븺��Ҳ�ǶԵ�... ...�����Ϊʲô��
{
	if (D == 0)
	{
		std::cout << "��ĸ����Ϊ��!" << std::endl;
		exit(1);
	}
	else if (D == 1)	{ up = U; down = 1; return; }
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

bool operator>=(Q const &a, Q const &b)			{ return a > b || a == b; }
bool operator!=	(Q const &a, Q const &b)			{ return !(a == b); }
bool operator<	(Q const &a, Q const &b)				{ return !(a > b || a == b); }
bool operator<=(Q const &a, Q const &b)			{ return !(a > b); }