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

/*����˵��*/
/*Sample Input:

*/

class one
{
protected:
	int num1;
public:
	one(int n) :num1(n){}
	one operator+(one const &other)
	{
		num1 *= 2;
		cout << "I did a plus in one" << endl;
		cout << num1 << endl;
		return one(other.num1);
	}
	void show()
	{
		cout << "show1" << endl;
	}
};
class two :public one
{
	int num2;
public:
	two(int n1, int n2) :one(n1), num2(n2){}
	two operator+(two const &other)
	{
		two a(*this);
		a.one::operator+(other);
		cout << "i did a plus in two" << endl;
		cout << num1 << ' ' << num2 << endl;
		return two(num1, other.num2);
	}
	void show()
	{
		one::show();
		cout << "show2" << endl;
	}
};

int main()//���Ǵ������ú���~
{
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	two a(100, 100);
	two b(1, 12345);
	a + b;
#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}