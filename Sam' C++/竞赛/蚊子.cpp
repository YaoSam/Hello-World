#include <iostream>
using namespace std;
#define DEBUG


int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	int X[10000], Y[10000];
	int n;
	int maxx=0, minx=1000, maxy=0, miny=1000;
	cin>>n;
	for (int i = 1; i <= n; n++)
	{
		cin >> X[i] >> Y[i];
		if (X[i] > maxx)	maxx = X[i];
		if (X[i] < minx)	minx = X[i];
		if (Y[i] > maxy)	maxy = Y[i];
		if(Y[i]<miny)		miny=Y[i];
	}
	int A = (maxx - minx) > (maxy - miny) ? (maxx - minx) : (maxy - miny);
	cout << A*A << endl;
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}