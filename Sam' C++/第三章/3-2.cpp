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
	int intOne;
	int &rSomeRef = intOne;

	intOne = 5;
	cout << "intOne:\t" << intOne << endl;
	cout << "rSomeRef:\t" << rSomeRef << endl;
	int intTwo = 8;
	rSomeRef = intTwo;
	cout << "\nintOne:\t" << intOne << endl;
	cout << "intTwo:\t" << intTwo << endl;
	cout << "rSomeRef:\t" << rSomeRef << endl;
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}