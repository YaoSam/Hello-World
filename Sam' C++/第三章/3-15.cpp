#include <iostream>
using namespace std;
//#define DEBUG
/*通过转换类型将原本整型数据经过转换当作Double来处理，从而达到提高提高精度的目的*/
int getPower(int x, int y)
{
	int sum = 1;
	for (int i = 1; i <= y; i++)
		sum *= x;
	return sum;
}

double getPower(double x, int y)
{
	double sum = 1;
	for (int i = 1; i <= y; i++)
		sum *= x;
	return sum;
}
int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	int a, m; 
	double b;
	cin >> a >> b >> m;
	cout << "a^m=" << getPower(a, m) << endl;
	cout << "b^m=" << getPower(b, m) << endl;
	cout << "a^m=" << getPower((double)a, m) << endl;
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}