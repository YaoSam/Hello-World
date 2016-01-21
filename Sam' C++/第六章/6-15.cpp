#include <iostream>
#include <string>

using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)
#define RE(n)			for(int I=0;I<n;I++)

/*程序注释*/
//	p1能指向某个变量，常量，但不能通过p1来改变其指向的内存的值（就是只读啦~）		错误用法 *p1 = 1;
//	p2初始化时就必须为其分配空间，并且只能指向常量，不能指向变量。错误用法，p2=&n;
/*Sample Input:

*/

int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	//p1
	int n = 13;
	const int *p1;
	p1=new int(1);	
	delete p1;
	p1=new int(12);//可以改变指向
	p1 = &n;			//可以指向变量
	//p2
	int *const p2=new int(2); //一开始就必须分配空间，放进一个常量。
	*p2 =13;//可以改变其内存中的值。
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}