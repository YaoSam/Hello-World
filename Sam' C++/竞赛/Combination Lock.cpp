#include <iostream>
using namespace std;
#define DEBUG
/*没什么好说的*/

int change(int a,int n)
{
	if (a > n) return n - a;
	else if (a <= 0) return  n + a;
	else return a;
}


int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	int N;
	cin >> N;
	int a;
	int b[10][10],c[10][10];
		for (int i = 1; i <= 3; i++)
		{
			cin >> a;
			for (int k = 1; k <= 5; k++)
				b[i][k] =change(a + k - 3,N);
		}
		for (int i = 1; i <= 3; i++)
		{
			cin >> a;
			for (int k = 1; k <= 5; k++)
				c[i][k] =change( a + k - 3,N);
}

		int COUNT=0; int SUM=1;
		for(int i=1;i<=3;i++,SUM*=COUNT,COUNT=0)
			for(int j=1;j<=5;j++)
				for(int k=1;k<=5;k++)
					if (b[i][j] == c[i][k])COUNT++;
		cout<<250-SUM<<endl;
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}