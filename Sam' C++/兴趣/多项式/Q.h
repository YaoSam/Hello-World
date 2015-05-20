#pragma once
/**
*　　　　　　　　┏┓　　　┏┓+ +
*　　　　　		　┏┛┻━━━┛┻┓ + +
*　　　　　		　┃　　　　　	┃ 　
*　　　　　		　┃　　　━　　┃ ++ + + +
*　　　　　		 ████━████	┃+
*　　　　　		　┃　　　　　	┃ +
*　　　　　		　┃　　　┻　　┃
*　　　　　		　┃　　　　　　┃ + +
*　　　　　		　┗━┓　　　┏━┛
*　　　　　　　　　┃　　　┃　　　　　　　　　　　
*　　　　　　　　　┃　　　┃ + + + +
*　　　　　　　　　┃　　　┃　　　　Code is far away from bug with the animal protecting　　　　　　　
*　　　　　　　　　┃　　　┃ + 　　　　神兽保佑,代码无bug　　
*　　　　　　　　　┃　　　┃
*　　　　　　　　　┃　　　┃　　+　　　　　　　　　
*　　　　　　　　　┃　 　　┗━━━┓ + +
*　　　　　　　　　┃ 　　　　　　　┣┓
*　　　　　　　　　┃ 　　　　　　　┏┛
*　　　　　　　　　┗┓┓┏━┳┓┏┛ + + + +
*　　　　　　　　　　┃┫┫　┃┫┫
*　　　　　　　　　　┗┻┛　┗┻┛+ + + +
*/
#include <iostream>
#include <string>

#define Re(i,n)		for(int i=0;i<=n;i++) //多项式里面的Re出了一点问题。


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
//依赖于重载的>和==
template <typename T>		bool operator>=(T const &a, T const &b)			{ return a > b || a == b; }
template <typename T>		bool operator!=(T const &a, T const &b)			{ return !(a == b); }
template <typename T>		bool operator<(T const &a, T const &b)			{ return !(a > b || a == b); }
template <typename T>		bool operator<=(T const &a, T const &b)			{ return !(a > b); }
#endif // !TEMPLATE

/*程序说明*//*
目的：有理数的四则运算。PS：为多项式做准备，因为多项式的除法中涉及系数的相除如果用float就不能得到精确的答案。
先定义了一个有理数的类Q。
将每个有理数由互素的分子和分母组成。
并且重载了针对其的四则运算，并且每一个return都用了构造函数，保证了互素。
也重载了^用作次数运算。
用了大量的const，还有&。两者相结合即提高了效率，也防止了参数被修改的情况。
		*/
class Fx;
class Q//代表有理数
{
	int up, down; //分子，分母
	friend class Fx;
	friend std::ostream &operator<<(std::ostream &out, Fx const &This);
public:
	Q() :up(0), down(1){}
	Q(int U, int D = 1);						//默认为零。貌似输入负数也是对的... ...不清楚为什么。
	Q(double decimal);					//将浮点数转化为分数，这里暂定精确值为小数点后5位。
	friend std::ostream &operator<<(std::ostream &out, Q const &This);
	Q operator==(const Q &other)const	{ return up*other.down == other.up*down; }
	Q operator>(const Q &other)const	{ return up*other.down > down*up; }
	//就是通分之后的式子。然后再用构造函数来保持互素。PS：为了简洁打得有点难看。
	Q operator+(const Q &other)const		{ return Q(up*other.down + down*other.up, down*other.down); }
	Q operator-(const Q &other)const		{ return Q(up*other.down - down*other.up, down*other.down); }
	Q operator*(const Q &other)const		{ return Q(up*other.up, down*other.down); }
	Q operator/(const Q &other)const		{ return Q(up*other.down, down*other.up); }
	Q operator^(int const &n)const				{ Q ans(1);	Re(i, n)	ans *= *this;	return ans; }
};
Q::Q(int U, int D)		//默认为零。貌似输入负数也是对的... ...不清楚为什么。
{

	if (D == 0)
	{
		std::cout << "分母不能为零!" << std::endl;
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
Q::Q(double decimal)					//将浮点数转化为分数，这里暂定精确值为小数点后5位。
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