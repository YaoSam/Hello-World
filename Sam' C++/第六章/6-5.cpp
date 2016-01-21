#include <iostream>
#include <string>

using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)
#define RE(m)		for(int I=0;I<m;I++)

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
	int a[5][3] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	Re(i, 5)
	{
		Re(j,3)	cout<<a[i][j]<<' ';
					cout << endl;
	}
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}