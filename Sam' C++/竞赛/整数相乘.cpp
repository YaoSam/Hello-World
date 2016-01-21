#include <iostream>
#include <string>

using namespace std;

#define DEBUG
#define Re(i,n)		for(int i=1;i<=n;i++)
#define RE(n)		for(int I=1;I<=n;i++)

/*程序注释*/
/*Sample Input:

*/
int  a[100000] = { 0 };
int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	int COUNT2 = 0;
	for (int n = 1; n <= 50; n++)
	{
		int COUNT = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= i; j++)
			{
				a[i*j]++;
				if (a[i*j] == 1)
					COUNT++;
			}
		memset(a, 0, sizeof(a));
		cout << n << ' ' << COUNT << endl;
	}



#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}