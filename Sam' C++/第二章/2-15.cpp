#include <iostream>
using namespace std;
//#define DEBUG
/*没什么好说的*/
int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif

	int i;
	int j;
	i = 10;
	j = 20;
	cout << "i+j=" << i + j;

#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG

	return 0;
}