#include <iostream>
using namespace std;
//#define DEBUG
/*ûʲô��˵��*/
int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
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