#include <iostream>
using namespace std;
//#define DEBUG
/*ûʲô��˵��*/
int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif

	int i;
	int j;
	i = 10;
	j = 20;
	cout << "i+j=" << i + j;

#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG

	return 0;
}