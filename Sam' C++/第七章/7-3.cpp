#include <iostream>
#include <string>
using namespace std;
//#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)

/*程序注释*/
/*代码胜于雄辩*/

class A
{
protected:
	int one;
public:
	A(int num) :one(num){}
	void fn1()
	{
		cout << "Here is fn1 in A" << endl;
	}
	void fn2()
	{
		cout << "Here is fn2 in A" << endl;
	}
};

class B :public A
{
public:
	B(int num) :A(num){}
	void fn2()
	{
		cout << "Here is fn2 in B" << endl;
	}
};

int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	A one(123);
	B two(234);
	one.fn1();
	one.fn2();
	two.fn1();
	two.fn2();

#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}