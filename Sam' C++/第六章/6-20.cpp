#include <iostream>
#include <string>

using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)
#define RE(n)			for(int I=0;I<n;I++)

/*程序注释*/
/*Sample Input:

*/
class SimpleCircle
{
	int *itsRadius;
public:
	SimpleCircle(int n=0)
	{
		itsRadius = new int(n);
	}
	SimpleCircle(SimpleCircle &p)//深复制
	{
		itsRadius = new int(p.itsRadius[0]);
	}
	~SimpleCircle()
	{
		cout << "DELETE~" << endl;
		delete itsRadius;
	}
	void showR()
	{
		cout << *itsRadius << endl;
	}
};





int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	SimpleCircle one(10);
	one.showR();
	SimpleCircle *p = new SimpleCircle(13);
	p->showR();
	SimpleCircle two =*p; //测试复制函数
	delete p;		//p被释放
	two.showR();	//two的功能完好。
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}