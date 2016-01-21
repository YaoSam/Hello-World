#include <iostream>
#include <string>
using namespace std;
//#define DEBUG
#define Re(i,n) for(int i=1;i<=n;i++)
/*����ע��*/
/*ͨ����Ԫ����ʵ�ַ������ж���*/
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
		cout << "��ʣ��ȼ�ϣ�" << volume << endl;
	}
};
class Engine
{
private:
	int cost; //�ͺġ�
	Fuel Left;
public:
	Engine(int num, int C) :Left(num), cost(C){};
	void run(int dis)
	{
		Left.show();
		printf("����%d���\n", dis);
		Left.volume -= dis*cost;
		Left.show();
	}
};
int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
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