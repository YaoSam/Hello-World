#include <iostream>
#include <string>

using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)
#define RE(n)			for(int I=0;I<n;I++)

/*����ע��*/
/*
������α�������⡣���˾��û���ϰ�����⡣��һ��new����һ��delete�ͺ��ˡ�
*/
/*Sample Input:

*/
int*p;			//��������p��Ϊȫ�֡������Ϳ��ں�������֮��p�ͷš�
int fn1()		//��������ڴ�й©��������֮��������������p���ڴ沢û�б��ͷš�
{
	 p = new int(5);
	return *p;
}



int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	int a = fn1();
	cout<<"the calue of a is: "<<a<<endl;
	delete p;
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}