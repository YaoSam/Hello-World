#include <iostream>
#include <string>

using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)
#define RE(n)			for(int I=0;I<n;I++)

/*����ע��*/
/*
��������������
void������ȫ�ֱ���left��right��ָʾ�ݹ顣
string������substr���ַ����ġ�+���������ַ�����
*/
/*Sample Input:

*/

void swap(char &a, char &b)
{
	char sto = a;
	a = b;
	b = sto;
}

//int left, right=-1;
//void reverse1(string &s)//void�е����롣�����̶ֹ��ˣ�ֻ����ȫ�ֱ�����
//{
//
//	if(right<0)			left=0, right=s.length()-1;//��right�����忪�ء�
//#ifdef debug
//	cout << s.substr(left, right - left) << endl;
//#endif	
//	if (left < right)	swap(s[left++], s[right--]), reverse1(s);
//	else right = -1; //�ݹ���������³�ʼ��
//}

string reverse(string &s)//��������string���͵ĺ���... ...
{
#ifdef DEBUG
cout << s << endl;//�鿴�ݹ����
#endif
	s.su
	if(s.length()>1)
		s =s[s.length()-1]+reverse(s.substr(1, s.length() - 2)) + s[0]; //��Ҫ�ݹ�Ĵ���Ϊs.length()/2
	//��һ��д��
	//s =reverse(s.substr(1, s.length() - 1)) + s[0]; //������һ�㣬��Ҫ�ݹ�Ĵ���Ϊs.length()
	return s;
}


int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	string abc = "1234567890";
	cout <<"��תǰ��"+ abc << endl;
	reverse(abc);
	cout <<"��ת��"+ abc << endl;
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}