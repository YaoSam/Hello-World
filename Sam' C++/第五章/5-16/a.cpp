#include <iostream>
#include <string>

using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)
#define RE(n)			for(int I=0;I<n;I++)

/*����ע��
(1)����
(2)����
(3)������ʾ����
(4)����ʱ����

*/
/*Sample Input:

*/
void f(int x, int y)
{
	std::cout << x << y << std::endl;
}
void f(int x);
int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	//f(1);
	cout << "hallo!" << endl;

#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}