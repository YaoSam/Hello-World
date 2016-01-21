#include <iostream>
#include <string>
using namespace std;
//#define DEBUG
#define Re(i,n) for(int i=1;i<=n;i++)
/*程序注释*/
/*通过友元类来实现访问是有对象*/
/*Sample Input:

*/


class Fuel
{
private:
	int volume;
	friend class Engine;
public:
	Fuel(int num) :volume(num){}
inline	void show()
	{
		cout << "还剩下燃料：" << volume << endl;
	}
};
class Engine
{
private:
	int cost; //油耗。
	Fuel Left;
public:
	Engine(int num, int C) :Left(num), cost(C){};
	void run(int dis)
	{
		Left.show();
		printf("跑了%d公里，\n", dis);
		Left.volume -= dis*cost;
		Left.show();
	}
};
int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	Engine Power(10000, 8);
	Power.run(10);

#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}