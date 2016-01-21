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
#define Re(i,n)		for(int i=0;i<n;i++) //ѭ��n��
void debug(string warning)
{
	cout << warning << endl;
	system("pause");
	exit(1);
}
//3. ����һ��������Shape��������������3�������ࣺCircle��Բ�Σ���Rectangle�����Σ���Triangle�������Σ�����һ������printArea�ֱ�����������ߵ������3��ͼ�ε������ڶ������ʱ������
//4.  ����һ��������Shape��������������5�������ࣺCircle��Բ�Σ���Square�������Σ���Rectangle�����Σ���Trapezoid�����Σ���Triangle�������Σ������麯���ֱ���㼸��ͼ�ε�������������ǵĺ͡�Ҫ���û���ָ�����飬ʹ����ÿһ��Ԫ��ָ��һ�����������
class Shape
{
public:
	virtual void printArea()const=0;
};

class Circle :public Shape
{
	double r;
public:
	Circle(double R = 0) :r(R){ if (r <= 0)debug("�뾶����С����"); }
	void printArea()const { cout << "Բ�������" << r*r*3.1415 << endl; }
};
class Retangle :public Shape
{
	double l, h;
public:	
	Retangle(double L = 0, double H = 0) :l(L), h(H){ if (l <= 0 || h <= 0)debug("�߳�����С����"); }
	void printArea()const { cout <<"�����������"<< l*h << endl; }
};
class Square :public Shape{
	double a;
public:
	Square(double a) :a(a){ if (a <= 0)debug("�����α߳�����С����"); }
	void printArea()const{ cout <<"�����������" <<a*a << endl; }
};
class Triangle :public Shape
{
	double a, b, c;
public:
	Triangle(double a = 0, double b = 0, double c = 0) :a(a), b(b), c(c)
	{
		double p = (a + b + c)/2;
		if (a <= 0 || b <= 0 || c <= 0)
			debug("�߳�����С����");
		if ((p - a) <= 0 || (p - b) <= 0 || (p - c) <= 0)
			debug("���������ߴ�С����");
	}
	void printArea()const
	{
		double p = (a + b + c)/2;
		cout <<"�����������"<< sqrt(p*(p - a)*(p - b)*(p - c))<<endl; //���׹�ʽ
	}
};

void fun(Shape *one){
	one->printArea();
}


int main()//���Ǵ������ú���~
{
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	Triangle a(3, 2, 3);
	Circle b(12);
	Retangle c(3, 4);
	Square d(123);
	Shape *manyShape[12] = { &a, &b, &c, &d };
	Re(i, 4)fun(manyShape[i]);

#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}