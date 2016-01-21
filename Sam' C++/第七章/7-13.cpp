#include <iostream>
#include <string>
using namespace std;

#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)

/*����ע��*/
/*˳��Ϊ�������ʱ��ļ̳�˳�������
Ҳ����Խ��ʼ�ĵ�ַԽ��
��̳еĹ���ͬһ����ַ��Ҳ����ͬһ��������
*/
/*Sample Output: ������ֵ�����иı䡣
Base1.var�ڴ��ַ: 0025FE50
Base2.var�ڴ��ַ: 0025FE54
Drived.var�ڴ��ַ: 0025FE58
&Base1.var-&Base2.var=-1
&Base1.var-&Derived.var=-2

Base01.var1: 0025FE34
Base02.var2: 0025FE3C
Derived.var: 0025FE40
Base01.var0: 0025FE44
Base02.var0: 0025FE44
&two.var1-two.var2= -2
&two.var2-&two.var0= -2
&two.var -&two.var0= -1
&two.Base01::var0 - &two.var 1
&two.Base01::var0 - &two.Base02::var2= 2
&two.Base01::var0 -&two.Base01::var1= 4


*/
class Base1{
public:
	int var;
	void fun(){ cout << "Member of Base1" << endl; }
};

class Base2{
public:
	int var;
	void fun(){ cout << "Member of Base2" << endl; }
};

class Derived :public Base1,public Base2{
public:
	int var;
	void fun(){ cout << "Member of Derived" << endl; }
};

/************************************************************************/
/* �����ķָ���  ����������7-8���ֵģ��������������غϡ��������֡�      */
/************************************************************************/

class Base0{
public:
	int var0;
	void fun0(){ cout << "Member of Base0" << endl; }
};

class Base01 :virtual public Base0{
public: 
	int var1;
};


class Base02 :virtual public Base0{
public:
	int var2;
};

class Derived0:public Base01,public Base02{
public:
	int var;
	void funt0(){ cout << "Member of Derived" << endl; }
};

int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	Derived one;
	cout << sizeof(Base1) << ' ' << sizeof(Base2) << ' ' << sizeof(Derived) << endl;
	cout << "Base1.var�ڴ��ַ: " << &one.Base1::var << endl
		<< "Base2.var�ڴ��ַ: " << &one.Base2::var << endl
		<< "Drived.var�ڴ��ַ: " << &one.var << endl
		<< "&Base1.var-&Base2.var=" << &one.Base1::var - &one.Base2::var << endl
		<< "&Base1.var-&Derived.var=" << &one.Base1::var - &one.var << endl;

	/************************************************************************/
	/*  �����ķָ���                                              */
	/************************************************************************/
	cout << endl;
	Derived0 two;
	cout << sizeof(Base0) << ' ' << sizeof(Base01) << ' ' << sizeof(Base02) << ' ' << sizeof(Derived0) << endl;
	cout
		<< "Base01.var1: " << &two.Base01::var1 << endl
		<< "Base02.var2: " << &two.Base02::var2 << endl
		<< "Derived.var: " << &two.var << endl
		<< "Base01.var0: " << &two.Base01::var0 << endl
		<< "Base02.var0: " << &two.Base02::var0 << endl
		<< "&two.var1-two.var2= " << &two.var1 - &two.var2 << endl
		<< "&two.var2-&two.var0= " << &two.var2 - &two.var0 << endl
		<< "&two.var -&two.var0= " << &two.var - &two.var0 << endl;

#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}