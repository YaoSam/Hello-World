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
#include "Tree.h"
using namespace std;

#define DEBUG //����ȷ���Ƿ��ı������
#ifndef re(i,n)
#define re(i,n) for(unsigned int i=0;i<n;i++)
#endif // !re(i,n)
#ifndef Re(i,n)
#define Re(i,n)		for(unsigned int i=1;i<=n;i++) //ѭ��n��
#endif // !Re(i,n)
//A B D # H # # E I # # J # # C F # K # # G # #
int main()
{
	srand(time(NULL));
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	//quenetree<char> a('#');
	//a.pre();
	tree<char>* hello;
	hello = Create('#');
	tree<char> a = *hello;
	hello->pre();
	cout << endl;
	hello->mid();
	cout << endl;
	hello->back();
	cout << endl;
	//hello->print();
	cout << endl;
	cout << hello->height() << endl;
	cout << hello->nodeNum() << endl;
	hello->printLeave();
	cout << endl;
	hello->InvertBackPrint();
	cout << endl;
	hello->back_1();
	cout << endl;
	cout << (hello->findParents('G')->DATA()) << endl;
	hello->Del('B');
	cout << endl;
	hello->pre();
#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}




//A B D # H # # E I # # J # # C F # K # # G # #