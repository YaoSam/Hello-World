#include <iostream>
#include <string>
#include "friend.h"
using namespace std;

#define DEBUG
#define Re(i,n)		for(int i=1;i<=n;i++)
#define RE(n)		for(int I=1;I<=n;I++)

/*����ע��*/
/*Sample Input:

*/

int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif

	X a(10);
	Y b(20);
	Z c(30);
	h(a);
	c.f();
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}