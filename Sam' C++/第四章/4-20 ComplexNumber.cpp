#include <iostream>
using namespace std;
#define DEBUG
#define Arithmetic
/*
加减乘除都弄了。
并且为了计算直观方便引入了共轭(conjugate)复数还有复数的模(module)的概念
如果去除对Arithmetic的注释屏蔽），便会变成显示算式模式，虽然还不完善
*/

class Complex
{
private:
	float a, b;//a+bi
	 float module;
	 void conjugate()
	{
		b = -b;
	}
	 void showans()
	{
//		cout << "ANS: ";
		if (a != 0)cout << a;
		if (b < 0)cout << b << 'i'<<endl;
		else if (b > 0) cout<< '+' << b << 'i' << endl;
	}
public:
	Complex(float x, float y=0)//x+yi
	{
		a = x, b=y;
		module = a*a + b*b;
	}
	void show()
	{
		if (a != 0)cout << a;
		if (b < 0)cout << b << 'i';
		else if (b > 0) cout << '+' << b << 'i';
	}
	void add(Complex &one)
	{
#ifdef Arithmetic
		show(); cout << '+'; one.show(); cout << '='; 
#endif
		a += one.a;
		b += one.b;
		showans();
	}
	void subtract(Complex &one)
	{
#ifdef Arithmetic
		show(); cout << '-'; one.show(); cout << '=';
#endif
		a -= one.a;
		b -= one.b;
		showans();
	}
	void multiple(Complex &one,bool ifshow=1)
		//(a+bi)(c+di)=ac-bd+(bc+ad)i
		//引入ifshow是因为在除法中也引用了乘法，所以那是要避免结果输出。
	{
#ifdef Arithmetic
		if (ifshow == 1){ show(); cout << '*'; one.show(); cout << '='; }
#endif
		float stoa = a;
		float c = one.a, d = one.b;
		stoa = a*c - b*d;
		b = b*one.a + a*one.b;
		a = stoa;
		if(ifshow==1)showans();
	}
	void divide( Complex &one)
	{
#ifdef Arithmetic
		show(); cout << "÷"; one.show(); cout << '=';
#endif
		one.conjugate();//先取共轭复数。
		multiple(one,0);
		a /= one.module, b /= one.module;
		showans();
	}
};

int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
	Complex c1(3, 5),c2 = 4.5, c3(-3,4);
	c1.add(c2);
	c1.subtract(c2);
	c1.multiple(c3);
	c1.divide(c3);
#endif
#ifdef DEBUG
	float a, b, c, d;
	char Operation;
	cout << "请输入两个复数，并且输入你要进行的操作：" << endl;
	cout << "Sample: 1 3 / 2 4" << endl;
	for (int i = 1; i <= 3;i++)
	{
		cin>> a >> b>>Operation >> c>> d;
			Complex one(a, b), two(c, d);
			if (Operation == '+')			one.add(two);
			else if (Operation == '-')	one.subtract(two);
			else if (Operation == '*')	one.multiple(two);
			else if (Operation == '/')	one.divide(two);
			else cout << "操作符输入错误" << endl;
	}

#endif
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}