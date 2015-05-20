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
#pragma once
#include "Q.h"
/*
Fx
Ŀ�ģ�����ʽ���������㣨����Ϊ���������
Ȼ������������������ɶ���ʽploy��
���л���һ�������Աdegree�����������㡣
�������������㻹��mod �����ж���ʽ������
//���ڡ��ҡ�����ʲô��
//Sample:
//���ֳ�ʼ��
Fx f(1,2,3,4)					//����f=1+2x+3x^2+4x^3
Fx g(Q(1,2),Q(3,4))			//g=1/2+3/4x
Q a={Q(1,2),Q(3,4),4,0,6}
int b={1,2,3,4};
Fx f(a),h(b);
//����ʽ����������+����
Fx ans=f*g;				 //f+g,f-g,f*g,f/g���ǿ��Ե�Ӵ��
cout<<f*g
f%g;					//���������ࡣ

//�Ƚ�����ĸ�������
gcd(f,g);					//�������ʽ��ͨ��%ʵ�֡�����շת�������������������ȫû�в��û���� ��ȫû������
Bezout(f,g)				//�������f��g��Bezout��ʽ����������飩����gcd�Ļ�����ʵ�֡�
g.f(2)							//.f() ����g��x=2�ĺ���ֵ��ע�ⷵ�ص���һ�������������Կ���g.f(2).show();����ʾ
g.D()							//.D() ���ص�����Ҳ����һ������ʽ��
*/
const int MAX = 12;	//�������ʽ����ߴ�����
class Fx
{
private:
	Q coef[MAX + 2];					//ϵ��������������ɡ�
	int degree;							//������n��	
	friend Fx Bezout(Fx const &f, Fx const &g); //��Ϊ����Ҫ��ȡdegree��
	friend Fx gcd(Fx const &f, Fx const &g);
public:
	Fx(int const a[]);		 //�������������鶨�����ʽ��
	Fx(Q const one[]);
	Fx(Q a0 = 0, Q a1 = 0, Q a2 = 0, Q a3 = 0, Q a4 = 0, Q a5 = 0, Q a6 = 0, Q a7 = 0); //����������Ķ�����������ʽ... ...�����е�... ...����
	friend std::ostream &operator<<(std::ostream &out, Fx const &This);
	Fx operator +(Fx const &other) const;
	Fx operator -(Fx const &other) const;
	Fx operator *(Fx const &other) const;
	Fx operator /(Fx const &other) const;
	//��ʵ���� ���޸�һ��return���Ǵ��ˡ��ҷ������ø��ˡ�Ч��ʲô��ȥ����~
	Fx operator %(Fx other) const	{ return *this - other*(*this / other); }
	Q f(Q const &x) const;			//����ֵ
	Fx D()const;					//��
};
Fx::Fx(int const a[])		 //�������������鶨�����ʽ��
{
	Re(i, MAX)
	{
		coef[i].up = a[i];
		if (a[i] != 0)degree = i;
	}
}
Fx::Fx(Q const one[])
{
	Re(i, MAX)
	{
		coef[i] = one[i];
		if (one[i].up != 0)degree = i;
	}
}
Fx::Fx(Q a0, Q a1, Q a2, Q a3, Q a4, Q a5, Q a6, Q a7)
{
	degree = -1;
	if (a0.up != 0)degree = 0; coef[0] = a0;
	if (a1.up != 0)degree = 1, coef[1] = a1;
	if (a2.up != 0)degree = 2, coef[2] = a2;
	if (a3.up != 0)degree = 3, coef[3] = a3;
	if (a4.up != 0)degree = 4, coef[4] = a4;
	if (a5.up != 0)degree = 5, coef[5] = a5;
	if (a6.up != 0)degree = 6, coef[6] = a6;
	if (a7.up != 0)degree = 7, coef[7] = a7;
}
std::ostream &operator<<(std::ostream &out, Fx const &This)
{
	out << " ( ";
	if (This.degree == -1)out << 0;
	else	Re(i, This.degree)
	{
		if (This.coef[i].up!=0)
		{		
			out << This.coef[i];
			if (i != 0)out << "x^" << i;
			if (i != This.degree)out << '+';
		}
	}
	out << " ) ";
	return out;
}
Fx Fx::operator +(Fx const &other) const
{
	int M = degree > other.degree ? degree : other.degree;		//���Ŀ��ܽ���
	Fx temp;
	Re(i, M)
	{
		temp.coef[i] = coef[i] + other.coef[i];			//ÿһ��ϵ���ֱ����
		if (temp.coef[i].up != 0) temp.degree = i;	//ȷ��׼ȷ������
	}
	return temp;
}
Fx Fx::operator -(Fx const &other) const
{
	int M = degree > other.degree ? degree : other.degree;
	Fx temp;
	Re(i, M)
	{
		temp.coef[i] = coef[i] - other.coef[i];		//ֻ���ӷ���һ�����š�
		if (temp.coef[i].up != 0) temp.degree = i;
	}
	return temp;
}
Fx Fx::operator *(Fx const &other) const
{
	Fx temp;													//��ʼ�����Ϊ�㡣
	if (degree != -1 && other.degree != -1)		//�ų�Ϊ��һ����������
	{
		temp.degree = degree + other.degree;		//����Ϊ������ӣ���Ϊ��������֤��Ϊ�㡣��׳���һ����
		Re(i, degree)												//����ѭ����ģ�������˷���
			Re(j, other.degree)
			temp.coef[i + j] += coef[i] * other.coef[j];
	}
	return temp;
}
Fx Fx::operator /(Fx const &other) const
{
	//�ݹ鹫ʽΪ��fn+1=fn-qn*g. 
	//ֱ��fn��<g. ANS=q����ͣ�����fn��ʵ����������
	Fx temp;
	if (degree < other.degree)return temp;
	else
	{
		temp.coef[degree - other.degree] = coef[degree] / other.coef[other.degree];
		temp.degree = degree - other.degree;
		return temp + (*this - temp*other) / other;
	}
}
Fx gcd(Fx const &f, Fx const &g)
{
	if (g.degree == -1) return f;
	else return gcd(g, f%g);
}
const Fx one(1);
Fx Fx::D()const
{
	Fx temp;
	Re(i, MAX)		temp.coef[i] = coef[i + 1] * (i + 1);	//��Ϊ������������ֱ����������Ĺ��캯����������һ����ʽת��
	temp.degree = degree - 1;
	return temp;
}
Q Fx::f(Q const &x) const											//��������ֵ
{
	Q sum;				//Ĭ��Ϊ0
	Re(i, degree)	sum += coef[i] * (x^i);						//�����������������ص�^����~ˬ��
	return sum;
}
inline void ShowDiv(Fx const &f, Fx const &g)		//������Bezoutʹ�õ���ʾ��������ĺ�����
{
	std::cout << f << "=" << f/g << '*' << g << '+' << f%g << std::endl;
}
inline void ShowMul(Fx const &u, Fx const &f, Fx const &v, Fx const &g)//������ʾBezout��ʽ�ĺ�����
{
	std::cout << u << '*' << f << '+' << v << '*' << g << '=' << u*f + v*g << std::endl;
}

Fx u, v;//Ϊ�˱�China���ö�ʹ��ȫ�ֱ�����
Fx Bezout(const Fx  &f, const Fx  &g)		//��gcd�Ļ����������˻ش��Ĳ�����uf+vg=gcd(f,g)
{
	static Fx tempu;
	if (g.degree == -1)
	{
		std::cout << "����Ϊշת�������gcd(f,g) ="; std::cout << f;
		std::cout << std::endl;
		std::cout << "����Ϊ�ش�ʵ��Bezout��ʽ\n";
		v = Fx();				//��ʼ��
		u = one;
		return  f;
	}
	else
	{
		ShowDiv(f, g);
		Fx tempANS = Bezout(g, f%g);
		tempu = u;
		u = v;
		v = tempu - v*(f / g);
		ShowMul(u, f, v, g);
		return tempANS;
	}
}

Fx China(const Fx &g1,const Fx &r1, const Fx &g2,  const Fx &r2)
{
	Bezout(g1, g2);
	Fx ANS = u*g1*r2 + v*g2*r1;
	std::cout << ANS << std::endl;
	return ANS;
}