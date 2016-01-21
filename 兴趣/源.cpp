
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <iomanip>
#include <algorithm>
	using namespace std;

#define re(i,n) for( int i=0;i<n;i++)
#define MIN -2147483647


	bool com(int a, int b)
	{
		if (a == MIN || b == MIN)
			return 1;
		else
			return a == b;
	}


	int main()
	{
		//FILE *err; //没用的指针... ...
		//freopen_s(&err, "in.txt", "r", stdin);
		//freopen_s(&err, "out.txt", "w", stdout);
		int n;
		cin >> n;
		int mark = 0;
		re(i, n)
		{
			int m;
			cin >> m;
			int a[1000] = { 0 };
			memset(a, 0, sizeof(a));
			re(k, m)
			{
				cin >> a[k];
				if (a[k] == -1)
					mark = k;
			}
			int b1[1000] = { 0 }, b2[1000] = { 0 }, b3[1000] = { 0 }, b4[1000] = { 0 };
			re(k, 1000)
			{
				b1[k] = MIN;
				b2[k] = MIN;
				b3[k] = MIN;
				b4[k] = MIN;
			}
			re(k, m - 3)
			{
				if (k + 1 != mark&&k != mark&&k + 2 != mark)
				{
					b1[k + 3] = a[k] + a[k + 1] + a[k + 2];
				}
				if (k + 3 != mark&&k + 1 != mark&&k != mark)
				{
					b2[k + 2] = a[k + 3] - a[k + 1] - a[k];
				}
				if (k != mark&&k + 2 != mark&&k + 3 != mark)
				{
					b3[k + 1] = a[k + 3] - a[k + 2] - a[k];
				}
				if (k + 3 != mark&&k + 2 != mark&&k + 1 != mark)
				{
					b4[k] = a[k + 3] - a[k + 2] - a[k + 1];
				}
			}
			int flag;
			int a1 = b1[mark], a2 = b2[mark], a3 = b3[mark], a4 = b4[mark];
			flag = com(a1, a2) && com(a1, a3) && com(a1, a4) && com(a2, a3) && com(a3, a4) && com(a2, a4);
			if (flag)
			{
				if (a1 != MIN)
					cout << a1 << endl;
				else if (a2 != MIN)
					cout << a2 << endl;
				else if (a3 != MIN)
					cout << a3 << endl;
				else if (a4 != MIN)
					cout << a4 << endl;
				else
					cout << -1 << endl;
			}
			else cout << -1 << endl;

		}
		return 0;
	}
}
