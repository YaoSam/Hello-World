#include <iostream>
#include <string>

using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)
#define RE(n)			for(int I=0;I<n;I++)

/*����ע��*/
/*
��α���������������⣬�����������ᱨ��İ�~��
*/
/*Sample Input:

*/

int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	//������
	int *p=new int(0);		
	//int *p;
	*p = 9;		//���⣬ʹ����δ����ռ��ָ�롣
	cout<<"The calue at p: "<<*p;
	delete p;
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}