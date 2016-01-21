#include <iostream>
#include <string>
using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)

/*程序注释*/
/*构造按派生顺序，析构逆序，
用文本输出会看得比较清楚。*/
/*Sample Output:
A mammal is born.
A dog is born.
A dog is dead.
A mammal is dead.
*/
class Mammal
{
public:
	Mammal()
	{
		cout << "A mammal is born." << endl;
	}

	~Mammal()
	{
		cout << "A mammal is dead." << endl;
	}

private:

};

class Dog:public Mammal
{
public:
	Dog():Mammal()
	{
		cout << "A dog is born." << endl;
	}

	~Dog()
	{
		cout << "A dog is dead." << endl;
	}

private:

};


int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	Dog one;

#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}