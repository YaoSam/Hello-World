#include <iostream>
using namespace std;
//#define DEBUG
/*ͨ��ת�����ͽ�ԭ���������ݾ���ת������Double�������Ӷ��ﵽ�����߾��ȵ�Ŀ��*/
int getPower(int x, int y)
{
	int sum = 1;
	for (int i = 1; i <= y; i++)
		sum *= x;
	return sum;
}

double getPower(double x, int y)
{
	double sum = 1;
	for (int i = 1; i <= y; i++)
		sum *= x;
	return sum;
}
int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	int a, m; 
	double b;
	cin >> a >> b >> m;
	cout << "a^m=" << getPower(a, m) << endl;
	cout << "b^m=" << getPower(b, m) << endl;
	cout << "a^m=" << getPower((double)a, m) << endl;
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}