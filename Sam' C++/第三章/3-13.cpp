#include <iostream>
using namespace std;
//#define DEBUG
int Fibonacci(int n)
{
	cout << n; //通过这个来观察递归过程。从第一个1开始向两边看。
	if (n == 1 || n == 2)return 1;
	else return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	for (int i = 1; i <= 10; i++)
		cout << "\n Fibonacci(n) :"<<Fibonacci(i) << endl;

#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}