#include <iostream>
#include <string>

using namespace std;

#define DEBUG
#define Re(i,n)		for(int i=1;i<=n;i++)
#define RE(n)		for(int I=1;I<=n;I++)

/*程序注释*/
/*Sample Input:

*/
long long an[40000];
long long num[40000];
int f(int n)
{
	if (n == 1)return 1;
	else if (an[n] == 1)return num[n];
	else
	{
		int sum=0;
		int big = (n - 1)*(n - 1);
		for (int i = n;i>=1; i--)
		{
			if (i*n > big)sum++;
			else 
			{
				int ok = 1;
				for (int j = n - 1; j > i;j--)
					if ((i*n)%j==0&&i*n/j<=n-1)
					{
						ok = 0; break;
					}
				sum += ok;
			}
		}
		num[n] =sum+ f(n - 1);
		an[n] = 1;
//		cout <<n<<' '<<num[n] << endl;
		return num[n];
	}
}
int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	f(30000);
	RE(10)
	{
		int i;
		cin>>i;
		cout << f(i)<<endl;
	}
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}
/*
1 1
2 3
3 6
4 9
5 14
6 18
7 25
8 30
9 36
10 42
11 53
12 59
13 72
14 80
15 89
16 97
17 114
18 123
19 142
20 152
21 164
22 176
23 199
24 209
25 225
26 239
27 254
28 267
29 296
30 308
31 339
32 354
33 372
34 390
35 410
36 423
37 460
38 480
39 501
40 517
41 558
42 575
43 618
44 638
45 659
46 683
47 730
48 747
49 778
50 800
*/