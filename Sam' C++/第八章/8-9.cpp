/*
*
*������	 ��������������           ����+ +
*����  ���������������ߩ��������������ߩ� + +
*����  ��������������������       �� ��
*����  ������������������������  �� ++ + + +
*����  ����		  ��  ��������������  ��+
*����  ������������������������ �� +
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

//#define DEBUG //����ȷ���Ƿ��ı������
#define Re(i,n)		for(int i=0;i<n;i++)

class BaseClass
{
public:
	~BaseClass(){ cout << "A BaseClass die now." << endl; }
};

class DerivedClass :public BaseClass
{
public:
	~DerivedClass(){ cout << "A DerivedClass die here." << endl; }
};





int main()//���Ǵ������ú���~
{
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	BaseClass *Bpointer = new DerivedClass;
	delete Bpointer; //BaseClass���ˡ�

#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}