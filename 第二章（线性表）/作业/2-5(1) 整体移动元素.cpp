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
#ifndef re(i,n)
#define re(i,n) for(unsigned int i=0;i<n;i++)
#endif // !re(i,n)
#ifndef Re(i,n)
#define Re(i,n)		for(unsigned int i=1;i<=n;i++) //ѭ��n��
#endif // !Re(i,n)

void debug(string warning)
{
	cerr << warning << endl;
	system("pause");
	exit(1);
}
template <class T>
void movetoleft(T num[],unsigned int length,unsigned int k)
{
	T *temp;
	if (k >= length) k %= length;
	temp = new T[k];
	memcpy(temp, num, k*sizeof(T));
	memcpy(num, num + k, (length - k)*sizeof(T));
	memcpy(num+k, temp, sizeof(T)*k);
	//re(i, length)
	//	cout << num[i] << ' ';
	delete[] temp;

}
int main()
{
	srand(time(NULL));
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	int  a[1000];
	re(i, 100)
		a[i] = i;
	re(i, 100)
		cout << a[i] << ' ';
	cout << endl;
	movetoleft(a, 30, 50);



#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}
