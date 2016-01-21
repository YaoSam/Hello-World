#include <iostream>
#include <string>

using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=1;i<=n;i++)
#define RE(n)		for(int I=1;I<=n;I++)

/*程序注释*/
/*
运行结果：
x from main:5
y from main :7
x from myFunction :5
y from myFunction :10
Back from myFunction now!

x from main:5
y from main :7

在函数中优先调用函数中定义的元素。
在main中则调用全局定义。
*/
/*Sample Input:

*/
int x = 5, y = 7;
void myFunction()
{
	int y = 10;
	cout << "x from myFunction :" << x << endl;
	cout << "y from myFunction :" << y << endl;
}
int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	cout << "x from main:" << x << endl;
	cout << "y from main :" << y << endl;
	myFunction();
	cout << "Back from myFunction now!\n" << endl;
	cout << "x from main:" << x << endl;
	cout << "y from main :" << y << endl;
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}