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
#define Re(i,n)		for(int i=0;i<n;i++) //ѭ��n��

class point{
	int x, y;
public:
	point(int m=0, int n=0) :x(m), y(n){}
	friend point operator+(point const &A, point const &B);
	friend ostream &operator<<(ostream &out, point const &This);
};

point operator+(point const &A, point const &B){ return point(A.x + B.x, A.y + B.y); } //�������
ostream &operator<<(ostream &out, point const &This){	return out << '(' << This.x << ',' << This.y << ')';}

int main()//���Ǵ������ú���~
{
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	point one(123,43);
	cout << one + point(123,100) << endl;	//��ʱ������
	cout << one + 200 << endl;					//�Զ�����ת��

#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}