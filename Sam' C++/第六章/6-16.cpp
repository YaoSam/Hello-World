#include <iostream>
#include <string>
using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)
#define RE(n)			for(int I=0;I<n;I++)

/*����ע��*/
/*Sample Input:

*/

int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	int a = 1,*p=&a,&r=a;
	cout << a << endl;
	*p = 10;
	cout<<a<<endl;
	r=5;
	cout << a << endl;
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}