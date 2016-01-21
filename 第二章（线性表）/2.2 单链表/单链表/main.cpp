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
#include "LinkList.h"

using namespace std;

#define DEBUG //用来确定是否文本输出。
#ifndef re
#define re(i,n)  for(int i=0;i<n;i++)
#endif // !re(i,n)

#ifndef Re
#define Re(i,n)	for(int i=1;i<=n;i++) //循环n次
#endif // !Re(i,n)

void debug(string warning)
{
	cerr << warning << endl;
	system("pause");
	exit(1);
}

int main()
{
#ifdef DEBUG
	FILE *err; //没用的指针... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif

	try	{
		srand(time(NULL));
		cout << "hello everyone" << endl;
		int a[1000];
		re(i, 1000)
			a[i] = rand() % 100;
		re(i, 50)
			cout << a[i] << ' ';
		cout << endl;
		LinkList<int> one(a, 10);
		one.PrintList();
		one.Insert(1, 11111);
		one.Insert(3, 23333);
		one.PrintList();
		one.Delete(3);
		one.PrintList();

		re(i, 10)
			cout << one.find(a[i]) << " " << one.Get(i + 1) << ' ' << endl;
		re(i, 11)
		{
			one.Delete(10 - i);
			cout << one.Length() << endl;
			one.PrintList();
		}
	}
	catch(string a)
	{
		cout<<a<<endl;
	}
#ifndef DEBUG //加个断点。
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}