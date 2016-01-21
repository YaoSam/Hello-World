/*
*
*����������������������  ����+ +
*�������������������ߩ��������ߩ� + +
*����������������������������  �� ��
*�������������������������������� ++ + + +
*��������			 |   ��������������    ��+
*����������������������������  �� +
*�����������������������ߡ�������
*����������������������������  �� + +
*��������������������������������
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
#include <iostream>
class C
{
	double real, img;
	double mol()const { return real*real + img*img; }
public:
	C(double a=0, double b=0) :real(a), img(b){}
	friend std::ostream &operator<<(std::ostream &out, C const &This);
	friend C operator+ (C const &This, C const &other)		{ return C(This.real + other.real, This.img + other.img); }
	friend C operator-	 (C const &This, C const &other)		{ return C(This.real - other.real, This.img - other.img); }
	friend C operator * (C const &This, C const &other)		{ return C(This.real*other.real - This.img*other.img, This.real*other.img + This.img*other.real); }
	friend C operator / (C const &This, C const &other);		//ʽ���е㳤
	C operator+=(C const &other)			{ real += other.real; img += other.img; return *this; }
	C operator-=(C const &other)			{ real -= other.real; img -= other.img; return *this; }
	C operator*=(C const &other)			{ *this = *this * other; return *this; }
	C operator/=(C const &other)			{ *this = *this / other; return *this; }
};

std::ostream & operator<<(std::ostream &out, C const &This)
{
	out << This.real;
	if(This.img!=0)	out<< "+" << This.img << "i";
	return out;
}
std::istream & operator>>(std::istream &in, C &This)
{
	double a, b;
	in >> a>> b;
	This = C(a, b);		//����friendֻ�������ˡ�
	return in;
}

C operator/(C const &This, C const &other)	//ʽ���е㳤	
{
	double Real = (This.real*other.real + This.img*other.img) / other.mol();
	double Img = (other.real*This.img - This.real*other.img) / other.mol();
	return C(Real, Img);
}
