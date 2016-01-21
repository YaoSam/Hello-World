#include <iostream>
#include <string>

using namespace std;

#define DEBUG
#define Re(i,n)		for(int i=1;i<=n;i++)
#define RE(n)		for(int I=1;I<=n;I++)

/*程序注释*/
/*Sample Input:

*/
class complex
{
	float a, b;//a+bi
public:
	complex(float A, float B) :a(A), b(B){}
	complex  operator+ (const complex other) const
	{
		return complex(a + other.a, b + other.b);
	}
	complex operator-(const complex other)const
	{
		return complex(a - other.a, b - other.b);
	}
	complex operator*(const complex other)const
	{
		return complex(a*other.a - b*other.b, a*other.b + other.a*b);
	}
	void show()
	{
		cout << a << "+" << b << "i" << endl;
	}
};

int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	complex a(1, 2), b(2, 3);
	(a*b).show();
	(a+b).show();
	(a-b).show();

#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}