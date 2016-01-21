#include <iostream>
#include <string>

using namespace std;

#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)
#define RE(n)			for(int I=0;I<n;I++)

/*程序注释*/
/*Sample Input:

*/
void splitFloat(float x, int &intPart, float &fracPart)
{
	intPart = static_cast<int>(x);
	fracPart = x - intPart;
}


class Point{
	int x, y;
public:
	Point(int X = 0, int Y = 0) :x(X), y(Y){}
	~Point()
	{
		show();
		cout << "Destructor called." << endl;
	}
	int getx()const	{ return x; }
	int gety()const	{ return y; }
	void move(int newX, int newY)
	{
		x = newX;
		y = newY;
	}
	void show()
	{
		printf("(%d,%d)", x, y);
	}
};



int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	/*6_10*/
	cout << "Enter 3float point numbers:" << endl;
	Re(i,3)
	{
		float x,f;
		int n;
		cin >> x;
		splitFloat(x, n, f);
		cout << "Interger Part=" << n << " Fraction Part=" << f << endl;
	}

	/*6_16*/
	cout<<"Step one: "<<endl;
	Point &ptr1 = *new Point(0,0);
	ptr1.show();
	delete &ptr1;
	cout << "Step two :" << endl;
	ptr1 = *(new Point(1, 2));
	ptr1.show();
	delete &ptr1;

#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}