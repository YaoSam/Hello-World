#include <iostream>
using namespace std;
#define DEBUG
/*ûʲô��˵��*/
int i;
namespace  Ns
{
	int j;
	class Example
	{
	private: int a;
	public:
		Example(int n)
		{
			a = n*n;
		}
		int show()
		{
			cout << "a=" << a << endl;
			return 0;
		}
		int wtf();
	};
	Example hallo(3);
}

class Example
{
private:
	int a, b, c;
public:
	Example(int one, int two)
	{
		a = one, b = two, c = a + b;
	}
	void show1()
	{
		cout << c << endl;
	}
};
int Ns::Example::wtf()
{
	cout << '\n' << show();
	return 10;
}
int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	int i = 5;
	Example Two(1, 2);
	Two.show1();
	Ns::j = 6;
	{
		using namespace Ns;
		int i=7;
		cout << "i=" << i << endl;
		cout << "j=" << j << endl;
	}
	cout << "i=" << i << endl;
	Ns::Example one(10);
	one.show();
	one.wtf();
	Ns::hallo.wtf();
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}