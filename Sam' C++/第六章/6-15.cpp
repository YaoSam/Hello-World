#include <iostream>
#include <string>

using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)
#define RE(n)			for(int I=0;I<n;I++)

/*����ע��*/
//	p1��ָ��ĳ��������������������ͨ��p1���ı���ָ����ڴ��ֵ������ֻ����~��		�����÷� *p1 = 1;
//	p2��ʼ��ʱ�ͱ���Ϊ�����ռ䣬����ֻ��ָ����������ָ������������÷���p2=&n;
/*Sample Input:

*/

int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	//p1
	int n = 13;
	const int *p1;
	p1=new int(1);	
	delete p1;
	p1=new int(12);//���Ըı�ָ��
	p1 = &n;			//����ָ�����
	//p2
	int *const p2=new int(2); //һ��ʼ�ͱ������ռ䣬�Ž�һ��������
	*p2 =13;//���Ըı����ڴ��е�ֵ��
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}