#include <iostream>
#include <string>

using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)
#define RE(n)			for(int I=0;I<n;I++)

/*����ע��*/
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
	SimpleCircle(SimpleCircle &p)//���
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
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	SimpleCircle one(10);
	one.showR();
	SimpleCircle *p = new SimpleCircle(13);
	p->showR();
	SimpleCircle two =*p; //���Ը��ƺ���
	delete p;		//p���ͷ�
	two.showR();	//two�Ĺ�����á�
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}