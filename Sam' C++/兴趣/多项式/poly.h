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
#pragma once
#include "Q.h"
/*
Fx
目的：多项式的四则运算（除法为带余除法）
然后由有理数数组来组成多项式ploy。
其中还有一个特殊成员degree用来方便运算。
重载了四则运算还有mod 来进行多项式的运算
//关于‘我’能做什么？
//Sample:
//各种初始化
Fx f(1,2,3,4)					//就是f=1+2x+3x^2+4x^3
Fx g(Q(1,2),Q(3,4))			//g=1/2+3/4x
Q a={Q(1,2),Q(3,4),4,0,6}
int b={1,2,3,4};
Fx f(a),h(b);
//多项式的四则运算+求余
Fx ans=f*g;				 //f+g,f-g,f*g,f/g都是可以的哟。
cout<<f*g
f%g;					//还可以求余。

//比较特殊的附带函数
gcd(f,g);					//求最大公因式。通过%实现。还是辗转相除发。跟代码整数完全没有差别。没错，是 完全没有区别。
Bezout(f,g)				//输出关于f和g的Bezout公式（详见几代书），在gcd的基础上实现。
g.f(2)							//.f() 返回g在x=2的函数值。注意返回的是一个有理数。所以可以g.f(2).show();来显示
g.D()							//.D() 返回导数。也就是一个多项式。
*/
const int MAX = 12;	//代表多项式的最高次数。
class Fx
{
private:
	Q coef[MAX + 2];					//系数。由有理数组成。
	int degree;							//最高项的n。	
	friend Fx Bezout(Fx const &f, Fx const &g); //因为他们要读取degree。
	friend Fx gcd(Fx const &f, Fx const &g);
public:
	Fx(int const a[]);		 //用来给整型数组定义多项式。
	Fx(Q const one[]);
	Fx(Q a0 = 0, Q a1 = 0, Q a2 = 0, Q a3 = 0, Q a4 = 0, Q a5 = 0, Q a6 = 0, Q a7 = 0); //用来更方便的定义整数多项式... ...代码有点... ...无脑
	friend std::ostream &operator<<(std::ostream &out, Fx const &This);
	Fx operator +(Fx const &other) const;
	Fx operator -(Fx const &other) const;
	Fx operator *(Fx const &other) const;
	Fx operator /(Fx const &other) const;
	//其实除法 的修改一下return就是答案了。我反正懒得改了。效率什么的去他的~
	Fx operator %(Fx other) const	{ return *this - other*(*this / other); }
	Q f(Q const &x) const;			//求函数值
	Fx D()const;					//求导
};
Fx::Fx(int const a[])		 //用来给整型数组定义多项式。
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
	int M = degree > other.degree ? degree : other.degree;		//最大的可能阶数
	Fx temp;
	Re(i, M)
	{
		temp.coef[i] = coef[i] + other.coef[i];			//每一项系数分别相加
		if (temp.coef[i].up != 0) temp.degree = i;	//确认准确阶数。
	}
	return temp;
}
Fx Fx::operator -(Fx const &other) const
{
	int M = degree > other.degree ? degree : other.degree;
	Fx temp;
	Re(i, M)
	{
		temp.coef[i] = coef[i] - other.coef[i];		//只跟加法差一个符号。
		if (temp.coef[i].up != 0) temp.degree = i;
	}
	return temp;
}
Fx Fx::operator *(Fx const &other) const
{
	Fx temp;													//初始结果就为零。
	if (degree != -1 && other.degree != -1)		//排除为有一方零的情况。
	{
		temp.degree = degree + other.degree;		//阶数为绝对相加，因为最大项均保证不为零。零阶常数一样。
		Re(i, degree)												//两重循环，模仿整数乘法。
			Re(j, other.degree)
			temp.coef[i + j] += coef[i] * other.coef[j];
	}
	return temp;
}
Fx Fx::operator /(Fx const &other) const
{
	//递归公式为：fn+1=fn-qn*g. 
	//直到fn阶<g. ANS=q的求和，最后的fn其实就是余数。
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
	Re(i, MAX)		temp.coef[i] = coef[i + 1] * (i + 1);	//因为有理数定义了直接整数输入的构造函数，这里有一个隐式转换
	temp.degree = degree - 1;
	return temp;
}
Q Fx::f(Q const &x) const											//用于求函数值
{
	Q sum;				//默认为0
	Re(i, degree)	sum += coef[i] * (x^i);						//调用了有理数中重载的^运算~爽。
	return sum;
}
inline void ShowDiv(Fx const &f, Fx const &g)		//用来给Bezout使用的显示带余除法的函数。
{
	std::cout << f << "=" << f/g << '*' << g << '+' << f%g << std::endl;
}
inline void ShowMul(Fx const &u, Fx const &f, Fx const &v, Fx const &g)//用来显示Bezout公式的函数。
{
	std::cout << u << '*' << f << '+' << v << '*' << g << '=' << u*f + v*g << std::endl;
}

Fx u, v;//为了被China调用而使用全局变量。
Fx Bezout(const Fx  &f, const Fx  &g)		//在gcd的基础上增加了回代的操作。uf+vg=gcd(f,g)
{
	static Fx tempu;
	if (g.degree == -1)
	{
		std::cout << "以上为辗转相除法，gcd(f,g) ="; std::cout << f;
		std::cout << std::endl;
		std::cout << "以下为回代实现Bezout公式\n";
		v = Fx();				//初始化
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