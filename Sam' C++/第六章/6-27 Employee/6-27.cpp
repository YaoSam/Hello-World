#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

//#define DEBUG
/*Sample Input:

*/

int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	Employee one("姚炜昌", "广州", "中山大学 173-607", 10086);
	one.display();
	one.setname("大帅哥");
	one.display();
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}