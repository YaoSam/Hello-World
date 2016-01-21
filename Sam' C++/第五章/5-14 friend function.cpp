#include <iostream>
#include <string>

using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=1;i<=n;i++)
#define RE(n)		for(int I=1;I<=n;I++)

/*程序注释*/
/*Sample Input:

*/
class Car;
class Boat
{
private:
	int weight;
	friend const int getTotalWeight(Boat &b, Car &c);
public:
	Boat(int n) :weight(n){}
};
class Car
{
private:
	int weight;
	friend const int getTotalWeight(Boat &b,Car &c);
public:
	Car(int n) :weight(n){}
};

const int getTotalWeight(Boat &b, Car &c)
{
	cout << "Total Weight is :" << b.weight+c.weight << endl;
	return 0;
}

int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	Boat one(1234);
	Car Benz(1000);
	getTotalWeight(one,Benz);
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}