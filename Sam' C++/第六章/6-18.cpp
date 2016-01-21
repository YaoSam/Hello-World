#include <iostream>
#include <string>

using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)
#define RE(n)			for(int I=0;I<n;I++)

/*程序注释*/
/*
关于如何避免的问题。个人觉得还是习惯问题。有一个new就有一个delete就好了。
*/
/*Sample Input:

*/
int*p;			//改正，将p设为全局。这样就可在函数结束之后将p释放。
int fn1()		//这里存在内存泄漏。返回了之后函数结束，但是p的内存并没有被释放。
{
	 p = new int(5);
	return *p;
}



int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	int a = fn1();
	cout<<"the calue of a is: "<<a<<endl;
	delete p;
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}