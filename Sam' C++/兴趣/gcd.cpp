#include <iostream>
using namespace std;
#define DEBUG
long long  gcd(long long  m, long long  n)//用来求xm+yn=gcd中的x y。
{
	if (m < n)	{ long long  sto = m; m = n, n = sto; }
	static long long  x = 1, y = 0, tempm;
	static bool first = 1;
	if (first == 1)												//第一次进入，开关关闭。记录m值
	{
		first = 0;
		tempm = m;
	}
	if (n == 0)
	{	
		cout << m << endl;
		x = 1, y = 0;											//修改从前x,y的值，递归进行到一半了，开始计算x,y.
		return m;
	}

	else
	{
		printf("%lld÷%lld=%lld*%lld+%lld\n", m, n,m / n, n, m%n);//显示辗转相除的递归过程
		long long  d=gcd(n, m%n);								//先储存，输出完了之后再return。
		long long  tempx = x;										//x,y都是static变量，不会消失。
		x = y;
		y = tempx - y*(m / n);
		printf("%lld*%lld+%lld*%lld=%lld\n", x,m , y,n, x*m + y*n);//显示回来过程。
		if (tempm == m)									//检测到m值。已经回到最初堆栈。输出xy
		{
			printf("%lld %lld\n", x, y);
			first = 1;
		}
		return d;
	}

}

int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	gcd(16920,14355);
	cout << endl;
	gcd(3,35);
	cout<<endl;
	gcd(5,21);
	gcd(7,15);
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}