#include "bignum.h"
#include <time.h>
using namespace std;
//#define DEBUG
#define TIME (float)clock()/CLOCKS_PER_SEC
#define Test() for(float t=TIME,flag=1;flag;flag=0,t=TIME-t,printf("cost time= %f\n",t)) //������������ʱ�䡣
int main()
{
#ifdef DEBUG
	FILE *err; //û�õ�ָ��...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	N one =2;
	int n;
	cout << "���Σ���ϲ������" << endl;
	//Test()
	//	Re(i, 17)
	//		one *= one;
	//one = 2;
	//Test()
	//	Re(i, 17)
	//		one = one*one;
	//string a = "1231";
	//cout << a << endl;
	//a[4] = 'c';
	//cout << a << endl;

	//cout << one << endl;
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}