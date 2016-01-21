#include <iostream>
#include <string>
#include "MyString.h"
using namespace std;

//#define DEBUG

/*程序注释*/
/*Sample Input:

*/

int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	MyString one("how do you do?"),two("I'm fine, thanks!"),three("He\nhe\n");
	string hallo = "What the fuck are you doing?!";
	MyString four(hallo);
	cout << hallo << endl;
	four.show();
	one.show();
	(one + two).show();
	one += two;
	one.show();
	three.show();
	cout << three[1] << three[12] << endl;
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}