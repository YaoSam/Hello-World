/*
*
*　　　	 　　　　   ┏┓　		 ┏┓+ +
*　　  　　　　　┏┛┻━━━━━━┛┻┓ + +
*　　  　　　　　┃　　　　       ┃ 　
*　　  　　　　　┃　　　━　　 ┃ ++ + + +
*　　  　　		   ┃  ███━███  ┃+
*　　  　　　　　┃　　　　　　┃ +
*　　  　　　　　┃　　   ┻　　  ┃
*　　  　　　　　┃　　　　　　┃ + +
*　　  　　　　　┗━┓　　　 ┏━┛
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
using namespace std;

#define DEBUG //用来确定是否文本输出。
#define Re(i,n)		for(int i=0;i<n;i++) //循环n次
void debug(string warning)
{
	cout << warning << endl;
	system("pause");
	exit(1);
}
//3. 定义一个抽象类Shape，由它派上生出3个派生类：Circle（圆形）、Rectangle（矩形）、Triangle（三角形），用一个函数printArea分别输出以上三者的面积，3个图形的数据在定义对象时给定。
//4.  定义一个抽象类Shape，由它派上生出5个派生类：Circle（圆形）、Square（正方形）、Rectangle（矩形）、Trapezoid（梯形）、Triangle（三角形）。用虚函数分别计算几种图形的面积，并求它们的和。要求用基类指针数组，使它的每一个元素指向一个派生类对象。
class Shape
{
public:
	virtual void printArea()const=0;
};

class Circle :public Shape
{
	double r;
public:
	Circle(double R = 0) :r(R){ if (r <= 0)debug("半径不能小于零"); }
	void printArea()const { cout << "圆形面积：" << r*r*3.1415 << endl; }
};
class Retangle :public Shape
{
	double l, h;
public:	
	Retangle(double L = 0, double H = 0) :l(L), h(H){ if (l <= 0 || h <= 0)debug("边长不能小于零"); }
	void printArea()const { cout <<"长方形面积："<< l*h << endl; }
};
class Square :public Shape{
	double a;
public:
	Square(double a) :a(a){ if (a <= 0)debug("正方形边长不能小于零"); }
	void printArea()const{ cout <<"正方形面积：" <<a*a << endl; }
};
class Triangle :public Shape
{
	double a, b, c;
public:
	Triangle(double a = 0, double b = 0, double c = 0) :a(a), b(b), c(c)
	{
		double p = (a + b + c)/2;
		if (a <= 0 || b <= 0 || c <= 0)
			debug("边长不能小于零");
		if ((p - a) <= 0 || (p - b) <= 0 || (p - c) <= 0)
			debug("三角形三边大小出错");
	}
	void printArea()const
	{
		double p = (a + b + c)/2;
		cout <<"三角形面积："<< sqrt(p*(p - a)*(p - b)*(p - c))<<endl; //海伦公式
	}
};

void fun(Shape *one){
	one->printArea();
}


int main()//我是呆萌哒妹函数~
{
#ifdef DEBUG
	FILE *err; //没用的指针... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	Triangle a(3, 2, 3);
	Circle b(12);
	Retangle c(3, 4);
	Square d(123);
	Shape *manyShape[12] = { &a, &b, &c, &d };
	Re(i, 4)fun(manyShape[i]);

#ifndef DEBUG //加个断点。
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}