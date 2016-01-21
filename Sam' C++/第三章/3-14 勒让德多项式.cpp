#include <iostream>
using namespace std;
#define DEBUG
/*P1(x)=1,p2(x)=x,pn=[(2n-1)x*(pn-1)(x)*-(n-1)(p(n-2)(x))]/n)*/

float Pn(int n, float x)
{
	cout << n;//用来观察迭代过程。
	if (n == 0)return 1;
	else if (n == 1)return x;
	else return ((2 * n - 1)*x*Pn(n - 1, x) - (n - 1)*Pn(n - 2, x)) / n;
	cout << '\n';
}

int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	for(int i=1;i<=10;i++)cout<<"Pn="<<Pn(i,2)<<endl;
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}