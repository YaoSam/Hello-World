#include <iostream>
using namespace std;
#define DEBUG

void swap(int a, int b)
{
	int sto = a;
	a = b;
	b = sto;
}
int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err,"in.txt", "r", stdin);
	freopen_s(&err,"out.txt", "w", stdout);
#endif
	int x, y;
	cin >> x >> y;
	if (x > y)swap(x, y);
	cout << x << '<' << y << endl;
	return 0;
}