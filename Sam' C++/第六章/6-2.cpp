#include <iostream>
#include <string>

using namespace std;
//#define DEBUG

#define Re(i,n)		for(int i=0;i<n;i++)
#define RE(n)			for(int I=0;I<n;I++)

/*����ע��*/
//a[20]�ĵ�һ��Ԫ��Ϊa[0],���һ��Ԫ��Ϊa[19];

/*Sample Input:
*/

int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	int a[20];
	Re(i, 20)		a[i] = i;
	Re(i, 20)		cout << a[i]<<' ';
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}