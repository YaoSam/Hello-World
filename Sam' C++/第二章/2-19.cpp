#include <iostream>
using namespace std;
//#define DEBUG
/*
��Ϊunsigned�Ĺ�ϵ��
���Ը��ŵı�ʶ1��ʶ�����������1��
�������ֱ�÷ǳ��Ĵ�*/

int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	unsigned int x, y = 100, z = 50;
	x = y - z;
	cout << "Difference is:" << x << endl;
	x = z - y;
	cout << "\nNow difference is:" << x << endl;
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}