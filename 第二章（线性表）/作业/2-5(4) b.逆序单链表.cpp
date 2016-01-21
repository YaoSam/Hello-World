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
*������������������������������������Code is far away from bug with the animal protecting*���������������������������� + �����������ޱ���,������bug����
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
#define Re(i,n) for(unsigned int i=1;i<=n;i++) //ѭ��n��
#endif // !Re(i,n)

void debug(string warning)
{
	cerr << warning << endl;
	system("pause");
	exit(1);
}

template <class T>
struct node 
{
	T data;
	node<T>* next;
};
template <class T>
ostream &operator<<(ostream& out, node<T>* head)
{
	while (head->next)
	{
		out << head->data << ' ';
		head = head->next;
	}
	return out << head->data;
}

template <class T>
node<T>* create(T List[], unsigned int length)
{
	node<T>* phead, *p,*q;
	phead = new node < T > ;
	phead->data = List[0];
	q = phead;
	re(i, length-1)
	{
		p = new node < T > ;
		p->data = List[i + 1];
		q->next = p;
		q = p;
	}
	q->next = NULL;
	return phead;
}

template <class T>
node<T>* invert(node<T>* head)
{
	node<T> *Pre, *Now, *Next;
	Pre = head;
	Now = Pre->next;
	Next = Now->next;

	head->next = NULL;
	while (Next->next)
	{
		Now->next = Pre;			//��Nowָ��ǰһ����
		Pre = Now;					//Pre �� Now �Ĺ�ϵ�Ѿ�����
		Now = Next;					//Now ��Now->next�Ĺ�ϵҲ����
		Next = Next->next;		//�����������ж�ѭ��������
	}
	Now->next = Pre;
	Next->next = Now;
	return Next;
}

template <class T>
node<T>* invert2(node<T>*head,node<T>* Pre=NULL)
{
	static node<T> *ans;
	if (head->next->next)
		invert2(head->next, head);
	else
	{
		ans = head->next;
		head->next->next = head;
	}
	head->next = Pre;
	return ans;
}


	float num[1000];
int main()
{
	srand(time(NULL));
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	unsigned int length = 10000;
	//int num[1000];
	re(i, 1000005)
		//num[i] = rand() % 100;
		num[i]=float(rand())/float(RAND_MAX)*100;
	//re(i,length)
		//cout << num[i] << ' ';
	cout << endl;
	//node<int>* head = create(num, length);
	node<float>* head = create(num, length);
	//cout << head << endl;
	//invert(head);

#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}