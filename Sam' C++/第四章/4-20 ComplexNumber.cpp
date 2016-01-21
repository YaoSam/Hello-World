#include <iostream>
using namespace std;
#define DEBUG
#define Arithmetic
/*
�Ӽ��˳���Ū�ˡ�
����Ϊ�˼���ֱ�۷��������˹���(conjugate)�������и�����ģ(module)�ĸ���
���ȥ����Arithmetic��ע�����Σ����������ʾ��ʽģʽ����Ȼ��������
*/

class Complex
{
private:
	float a, b;//a+bi
	 float module;
	 void conjugate()
	{
		b = -b;
	}
	 void showans()
	{
//		cout << "ANS: ";
		if (a != 0)cout << a;
		if (b < 0)cout << b << 'i'<<endl;
		else if (b > 0) cout<< '+' << b << 'i' << endl;
	}
public:
	Complex(float x, float y=0)//x+yi
	{
		a = x, b=y;
		module = a*a + b*b;
	}
	void show()
	{
		if (a != 0)cout << a;
		if (b < 0)cout << b << 'i';
		else if (b > 0) cout << '+' << b << 'i';
	}
	void add(Complex &one)
	{
#ifdef Arithmetic
		show(); cout << '+'; one.show(); cout << '='; 
#endif
		a += one.a;
		b += one.b;
		showans();
	}
	void subtract(Complex &one)
	{
#ifdef Arithmetic
		show(); cout << '-'; one.show(); cout << '=';
#endif
		a -= one.a;
		b -= one.b;
		showans();
	}
	void multiple(Complex &one,bool ifshow=1)
		//(a+bi)(c+di)=ac-bd+(bc+ad)i
		//����ifshow����Ϊ�ڳ�����Ҳ�����˳˷�����������Ҫ�����������
	{
#ifdef Arithmetic
		if (ifshow == 1){ show(); cout << '*'; one.show(); cout << '='; }
#endif
		float stoa = a;
		float c = one.a, d = one.b;
		stoa = a*c - b*d;
		b = b*one.a + a*one.b;
		a = stoa;
		if(ifshow==1)showans();
	}
	void divide( Complex &one)
	{
#ifdef Arithmetic
		show(); cout << "��"; one.show(); cout << '=';
#endif
		one.conjugate();//��ȡ�������
		multiple(one,0);
		a /= one.module, b /= one.module;
		showans();
	}
};

int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
	Complex c1(3, 5),c2 = 4.5, c3(-3,4);
	c1.add(c2);
	c1.subtract(c2);
	c1.multiple(c3);
	c1.divide(c3);
#endif
#ifdef DEBUG
	float a, b, c, d;
	char Operation;
	cout << "��������������������������Ҫ���еĲ�����" << endl;
	cout << "Sample: 1 3 / 2 4" << endl;
	for (int i = 1; i <= 3;i++)
	{
		cin>> a >> b>>Operation >> c>> d;
			Complex one(a, b), two(c, d);
			if (Operation == '+')			one.add(two);
			else if (Operation == '-')	one.subtract(two);
			else if (Operation == '*')	one.multiple(two);
			else if (Operation == '/')	one.divide(two);
			else cout << "�������������" << endl;
	}

#endif
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}