#include <iostream>
using namespace std;
//#define DEBUG
int Fibonacci(int n)
{
	cout << n; //ͨ��������۲�ݹ���̡��ӵ�һ��1��ʼ�����߿���
	if (n == 1 || n == 2)return 1;
	else return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	for (int i = 1; i <= 10; i++)
		cout << "\n Fibonacci(n) :"<<Fibonacci(i) << endl;

#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}