#include <iostream>
#include <string>
using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)

/*����ע��*/
/*����ʤ���۱�*/

class Base
{
public:
	void fn1()
	{
		cout << "Here is fn1 in Base" << endl;
	}
	void fn2()
	{
		cout << "Here is fn2 in Base" << endl;
	}
};
class Derived:public Base
{
public:
	void fn1()
	{
		cout << "Here is fn1 in Derived" << endl;
	}
};




int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif

	Derived one;
	one.Base::fn1();
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}