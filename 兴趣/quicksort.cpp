/*
*
*������	 ��������   ������		 ����+ +
*����  ���������������ߩ��������������ߩ� + +
*����  ��������������������       �� ��
*����  ������������������������ �� ++ + + +
*����  ����		   ��  ��������������  ��+
*����  �������������������������� +
*����  ����������������   �ߡ���  ��
*����  �������������������������� + +
*����  ���������������������� ������
*��������������������������������������������������
*���������������������������� + + + +
*������������������������������������Code is far away from bug with the animal protecting��������������
*���������������������������� + �����������ޱ���,������bug����
*����������������������������
*��������������������������������+������������������
*���������������������� �������������� + +
*�������������������� ���������������ǩ�
*�������������������� ������������������
*�����������������������������ש����� + + + +
*�����������������������ϩϡ����ϩ�
*�����������������������ߩ������ߩ�+ + + +
*/
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

#define DEBUG //����ȷ���Ƿ��ı������
#define re(i,n) for(unsigned int i=0;i<n;i++)
#define Re(i,n)		for(unsigned int i=1;i<=n;i++) //ѭ��n��

template <class T>
void Swap(T &a, T &b)
{
	T temp = a;a = b; b = temp;
	return;
}
template <class T>
T max(T a, T b)
{
	return a > b ? a : b;
}
void qsort(int a[],int left,unsigned int right)
{
	int mid = a[(left + right) / 2];
	int l = left, r = right;
	do 
	{
		while (a[l] < mid)l++;
		while (a[r] > mid)r--;
		if (l <= r)
			Swap(a[l++], a[r--]);
	} while (l <= r);
	if (r > left)		qsort(a, left, r);
	if (l < right)	qsort(a, l, right);
	return;
}
int value[1000];
int weight[1000];
int f[100];
int main()
{
	srand(time(NULL));
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	//int num[100];
	//re(i, 20)
	//{
	//	num[i] = rand() % 100;
	//	cout << num[i] << ' ';
	//}
	//qsort(num, 0, 19);
	//cout << endl;
	//re(i, 20)
	//{
	//	cout << num[i] << ' ';

	//}
	//cout << endl;
	int n;
	int maxweight;
	cin >> n;
	cin >> maxweight;
	re(i, n)
	{
		cin >> value[i] >> weight[i];
		for (int j = maxweight; j > 0; j--)
		{
			if (j < weight[i])
				f[j] = 0;
			else	f[j] = max(f[j - weight[i]] + value[i], f[j]);
		}
		re(j, maxweight+1)
			cout << f[j] << ' ';
		cout << endl;
	}
#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}

#undef  DEBUG
#undef  re(i,n)
#undef  Re(i,n)