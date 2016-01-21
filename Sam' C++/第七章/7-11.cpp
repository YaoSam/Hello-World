#include <iostream>
#include <string>
using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)

/*程序注释*/
/*Sample Output
Here is fn1 in BaseClass
Here is fn2 in BaseClass
Here is fn1 in DerivedClass
Here is fn2 in DerivedClass
*/

class BaseClass
{
public:
	void fn1()
	{
		cout << "Here is fn1 in BaseClass" << endl;
	}
	void fn2()
	{
		cout << "Here is fn2 in BaseClass" << endl;
	}
};
class DerivedClass:public BaseClass
{
public:
	void fn1()
	{
		cout << "Here is fn1 in DerivedClass" << endl;
	}
	void fn2()
	{
		cout << "Here is fn2 in DerivedClass" << endl;
	}
};
int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	DerivedClass one;
	one.BaseClass::fn1();
	one.BaseClass::fn2();
	one.fn1();
	one.fn2();
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}