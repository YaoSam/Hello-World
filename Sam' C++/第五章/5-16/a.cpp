#include <iostream>
#include <string>

using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)
#define RE(n)			for(int I=0;I<n;I++)

/*程序注释
(1)编译
(2)连接
(3)不会提示错误
(4)连接时出错

*/
/*Sample Input:

*/
void f(int x, int y)
{
	std::cout << x << y << std::endl;
}
void f(int x);
int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	//f(1);
	cout << "hallo!" << endl;

#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}