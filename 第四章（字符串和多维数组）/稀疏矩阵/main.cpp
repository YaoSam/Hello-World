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
#include "Sparse.h"
using namespace std;

#define DEBUG //����ȷ���Ƿ��ı������
#ifndef re(i,n)
#define re(i,n) for(unsigned int i=0;i<n;i++)
#endif // !re(i,n)
#ifndef Re(i,n)
#define Re(i,n)		for(unsigned int i=1;i<=n;i++) //ѭ��n��
#endif // !Re(i,n)

int main()
{
	srand(time(NULL));
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	try{
		int m, n, data;
		unsigned int colume, row;
		unsigned int num;
		cin >> colume >> row >> num;
		int **mat = new int *[row];
		re(i, row)
		{
			mat[i] = new int[colume];
			memset(mat[i], 0, sizeof(int)*colume);
		}
		re(i, num){
			cin >> m >> n >> data;
			mat[m][n] = data;
		}
		re(i, row)
		{
			re(j, colume)
				cout << mat[i][j] << ' ';
			cout << endl;
		}
		cout << endl;
		sparse<int> one(mat, row, colume);
		cout << one << endl;
		cout << one + one << endl;
		one.transpose();
		cout << one << endl;
		one.print();
	}
	catch (const char *a)
	{
		cout<<a<<endl;
	}
#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}