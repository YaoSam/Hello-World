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
#include "SeqTree.h"
using namespace std;

#define DEBUG //����ȷ���Ƿ��ı������
#define re(i,n) for(unsigned int i=0;i<n;i++)
#define Re(i,n)		for(unsigned int i=1;i<=n;i++) //ѭ��n��

int main()
{
	srand(time(NULL));
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	SeqTree<int> tree;
	int temp;
	while (cin>>temp)
	{
		tree.insert(temp);
	}
		tree.mid();
		cout << endl;
		tree.print();
		cout << endl;
		cout<<tree.findMAX(35);
		cout << endl;
		cout<<tree.findMAX(13);
	//cout << endl;
	//int a = 67;
	//if (tree.find(42))
	//	tree.Del(42);
	//if (tree.find(67))
	//	tree.Del(67);
	//cout << endl;
	//tree.mid();
	//int b[1000];
	//re(i, 100)
	//{
	//	SeqTree<int> a;
	//	re(j, 100)
	//		a.insert(b[j]=rand()%1000);
	//	re(j, 100)
	//	{
	//		cout << (a.find(b[j])->Data()) << ' ';
	//	}
	//}

#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}
//65 55 90 42 58 70 10 45 67 83
#undef  DEBUG
#undef  re(i,n)
#undef  Re(i,n)