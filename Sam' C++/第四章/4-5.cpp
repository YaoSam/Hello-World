#include <iostream>
using namespace std;
//#define DEBUG
/*可以不同*/
class A
{
private: int a;
public :
	A(int n)
	{
		a = 2*n;
	}
	void showa()
	{
		cout << a << endl;
	}
};
int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	A a1(3), a2(4);
	a1.showa(),a2.showa();
#ifndef DEBUG
	cout << "a1与a2的a不同";
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}