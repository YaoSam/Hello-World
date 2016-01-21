#include <iostream>
#include <string>

using namespace std;
//#define DEBUG

#define Re(i,n)		for(int i=0;i<n;i++)
#define RE(n)			for(int I=0;I<n;I++)

/*程序注释*/
//a[20]的第一个元素为a[0],最后一个元素为a[19];

/*Sample Input:
*/

int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	int a[20];
	Re(i, 20)		a[i] = i;
	Re(i, 20)		cout << a[i]<<' ';
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}