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
#include <time.h>
using namespace std;

#define DEBUG //����ȷ���Ƿ��ı������
#ifndef re(i,n)
#define re(i,n) for(unsigned int i=0;i<n;i++)
#endif // !re(i,n)
#ifndef Re(i,n)
#define Re(i,n)		for(unsigned int i=1;i<=n;i++) //ѭ��n��
#endif // !Re(i,n)

void debug(string warning)
{
	cerr << warning << endl;
	system("pause");
	exit(1);
}
//template <class T>
//T MAX(T num[], unsigned int n,unsigned int index=0, T CurrentMax=0)
//{
//	if (index > n)
//		return CurrentMax;
//	if (index == 0)
//	{
//		CurrentMax = num[index];
//		return MAX(num, n, index + 1, CurrentMax);
//	}
//	else
//		return MAX(num, n, index + 1, (CurrentMax > num[index] ? CurrentMax : num[index]));
//}

struct node
{
	int data;
	node* next;
	node(int a=0, node* Next=NULL) :data(a), next(Next){}
};
node * create(int num[],int n)
{
	node* head = new node;
	node* temp = head;
	re(i, n)
	{
		temp->next = new node(num[i]);
		temp = temp->next;
	}
	return head;
}

int MAX(node* head, int i = 0,int max=0)
{
	if (head->next==NULL)
		return max;
	if (i == 0)
		max = head->next->data;
	else	max = max > (head->next->data) ? max : head->next->data;
	return MAX(head->next, i + 1, max);
}

unsigned int JieChen(unsigned int n)
{
	return n==0?1:n*JieChen(n - 1);
}
//����ؼ�
//Fn(AC)=Fn-1(AB)+F1(AC)+Fn-1(BC)
int Count = 0;
void P(int n, char A, char B, char C)
{
	if (n == 1)
	{
		Count++;
		printf("��%d��: %c->%c\n ", Count, A, C);
	}
	else { P(n - 1, A, C, B); P(1, A, B, C); P(n - 1, B, A, C); }
}

int main()
{
	srand(time(NULL));
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	int num[10000];
	int n = 100;
	re(i,n)
		num[i] = rand()%1000;
	re(i, n)
		cout << num[i] << ' ';
	node* head = create(num, n);
	cout << endl;
	cout << MAX(head) << endl;
	re(i, 15)
		cout << JieChen(i) << endl;
	P(4,'A','B','C');

#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}