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
#define re(i,n) for(unsigned int i=0;i<n;i++)
#define Re(i,n)		for(unsigned int i=1;i<=n;i++) //ѭ��n��

template<class T>
struct node{
	T data;
	node<T>* next;
	node(T data=0,node<T>* next=NULL) :data(data), next(next){}
};


template<class T>
class list{
	node<T>* head;
public:
	list(){
		head = new node < T > ;
	}
	list(T num[], unsigned int n)
	{
		head = new node < T > ;
		node<T>* temp=head;
		re(i, n)
		{
			temp->next = new node<T>(num[i]);
			temp = temp->next;
		}
	}
};
template<class T>
node<T>* create(T num[], unsigned int n)
{
	node<T>* head = new node < T > ;
	node<T>* temp = head;
	re(i, n)
	{
		temp->next = new node<T>(num[i]);
		temp = temp->next;
	}
	return head;
}
template<class T>
node<T>* combine(node<T>* a, node<T>* b)
{
	node<T>* head = NULL;
	if (a)
	{
		//ע������a�Ѿ�Ų��һ���ˡ�
		if (b)
		{
			if (a->data != b->data)
			{
				head = combine(b, a->next);
			}
			else
			{
				node<T>* temp = b->next;
				b->next = b->next->next;
				delete b->next;
			}
		}
		else
		{
			node<T>* temp = b;
			while (temp)
			{
				head->next = new node<T>(temp->data)
			}
		}
	else return new node<T>* (a->next->data);
	}
	else
		return combine(b, a);
	head->next=
}


int main()
{
	srand(time(NULL));
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif

#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}

#undef  DEBUG
#undef  re(i,n)
#undef  Re(i,n)