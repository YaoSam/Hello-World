#include <iostream>
using namespace std;

int main()
{
	int X[10000], Y[10000];
	int n;
	int maxx,minx,maxy ,miny;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> X[i] >> Y[i];
		if (i == 1)minx = maxx = X[i], miny = maxy = Y[i];
		if (X[i] > maxx)	maxx = X[i];
		if (X[i] < minx)	minx = X[i];
		if (Y[i] > maxy)	maxy = Y[i];
		if (Y[i] < miny)	miny = Y[i];
	}
	int A = (maxx - minx) > (maxy - miny) ? (maxx - minx) : (maxy - miny);
	cout << A*A << endl;
	return 0;
}