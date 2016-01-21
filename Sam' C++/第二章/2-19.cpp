#include <iostream>
using namespace std;
//#define DEBUG
/*
因为unsigned的关系，
所以负号的标识1被识别成了正常的1，
所以数字变得非常的大。*/

int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	unsigned int x, y = 100, z = 50;
	x = y - z;
	cout << "Difference is:" << x << endl;
	x = z - y;
	cout << "\nNow difference is:" << x << endl;
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}