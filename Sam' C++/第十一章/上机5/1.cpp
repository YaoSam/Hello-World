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
using namespace std;

#define DEBUG //����ȷ���Ƿ��ı������
#define Re(i,n)		for(int i=1;i<=n;i++) //ѭ��n��
void debug(string warning)
{
	cerr << warning << endl;
	system("pause");
	exit(1);
}

template <class T>
void myswap(T &a, T &b){
	T temp = a;
	a = b;
	b = temp;
	return;
}


template <class T>
void mysort(T *array, int left, int right)//ð��
{
	for (int i = left; i < right; i++)
		for (int j = right; j > i; j--)
			if (array[j] >array[j - 1])
				myswap(array[j], array[j - 1]);
}

int main()//���Ǵ������ú���~
{
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	float num[1000];
	Re(i, 10)cin >> num[i];
	Re(i, 10)cout << num[i] << ' ';
	cout << endl;
	mysort(num, 1, 10);
	Re(i, 10)cout << num[i] << ' ';

#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}