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
#include <time.h>
using namespace std;

#ifndef Re(i,n)
#define Re(i,n)		for(int i=1;i<n;i++) //循环n次
#endif // !Re(i,n)

int gcd(int m, int n)
{
	if (n==0)
		return m;
	else 
		return gcd(n, m%n);
}


int lcm(int a, int b)
{
	return a*b / gcd(a, b);
}

int main()
{
	int c = 105;
		for (int d = 106; d <=300; d++)
				Re(b, 105)
					Re(a, b)
					{
						long ans = lcm(lcm(c, d), lcm(a, b));
						if (ans == (a + b + c + d))
						{
							cout << ans << ' ' << (a + b + c + d) << endl;
							cout << b<< ' ' << a << ' ' << c << ' ' << d << endl;
						}
					}
		
#ifndef DEBUG //加个断点。
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}