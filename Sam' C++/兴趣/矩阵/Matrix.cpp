#include <iostream>
#include <string>
#include "Matrix.h"
using namespace std;

#define DEBUG

/*����ע��*/
/*Sample Input:

*/

int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif

	Mn one,two;
	cin >> one >> two;
	cout << one << two << endl;
	cout << one * two << endl;
	cout << one.rref() << two.rref() << (one + two).rref() << endl;
	//int m, n;
	//cin >> m >> n;
	//cout << m << n << endl;
	//int num[100];
	//Re(i, m*n)
	//	cin >> num[n+i];
	//Mn one = Mn(num, m, n);
	//cout << one << endl;
	//cout << one.rref() << endl;
	//cout<<one.det()<<endl;
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}