#include <iostream>
#include <string>
#include "Acount.h"
using namespace std;
#define DEBUG
#define Re(i,n) for(int i=1;i<=n;i++)
/*程序注释*/
/*Sample Input:

*/

int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	Acount Sam(14336238, "Sam", 20150105, 10000);
	Sam.save(1000, 20150415);
	Sam.save(-10000,20150915);
	Sam.show(20160101);
	cout << endl;
	Acount Bob(14336236,"Bob",20150225,2000);
	Bob.save(1000, 20150303);
	Bob.save(1000,20150404);
	Bob.save(1000,20150505);
	Bob.show(20160101);
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}