#include <iostream>
#include "DATE.h"
using namespace std;
//#define Debug
#define scanf scanf_s

int printyear(int year)
{
	Date(year, 1, 1).CalenderY();
	return 0;
}
int main()
{
#ifdef Debug
	FILE *empty;
	freopen_s(&empty, "in.txt", "r", stdin);
	freopen_s(&empty, "out.txt", "w", stdout);
#endif
	Date now(20150610), birth(19960611);
	cout << now - birth << endl;
	cout << now - 1378 << endl;
	system("pause");
	return 0;
}

/*Sample Input*/
/*

19950930 20141112
20080808 20141129
20140101 20141129
20130101 20150202
20130101 20141129
20141010 20141129
19950930 20141129
20141129 20141129
^z

*/
