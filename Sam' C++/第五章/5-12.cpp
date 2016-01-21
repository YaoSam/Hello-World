#include <iostream>
#include <string>

using namespace std;
//#define DEBUG

#define Re(i,n)		for(int i=1;i<=n;i++)
#define RE(n)		for(int I=1;I<=n;I++)

/*程序注释*/
/*静态成员的应用*/
/*Sample Input:

*/
int fn1()
{
	static int n=1;
	cout << ++n << endl;
	return 0;
}
int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	RE(10)fn1();

#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}