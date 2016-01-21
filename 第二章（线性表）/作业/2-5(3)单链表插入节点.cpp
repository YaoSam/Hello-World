/*
*
*　　　	 　　　　   ┏┓　		 ┏┓+ +
*　　  　　　　　┏┛┻━━━━━━┛┻┓ + +
*　　  　　　　　┃　　　　       ┃ 　
*　　  　　　　　┃　　　━　　 ┃ ++ + + +
*　　  　　		   ┃  ███━███  ┃+
*　　  　　　　　┃　　　　　　┃ +
*　　  　　　　　┃　　   ┻　　  ┃
*　　  　　　　　┃　　　　　　┃ + +
*　　  　　　　　┗━┓　　　 ┏━┛
*　　　　　　　　　┃　　　┃　　　　　　　　　　　
*　　　　　　　　　┃　　　┃ + + + +
*　　　　　　　　　┃　　　┃　　　　Code is far away from bug with the animal protecting　　　　　　　
*　　　　　　　　　┃　　　┃ + 　　　　神兽保佑,代码无bug　　
*　　　　　　　　　┃　　　┃
*　　　　　　　　　┃　　　┃　　+　　　　　　　　　
*　　　　　　　　　┃　 　　┗━━━┓ + +
*　　　　　　　　　┃ 　　　　　　　┣┓
*　　　　　　　　　┃ 　　　　　　　┏┛
*　　　　　　　　　┗┓┓┏━┳┓┏┛ + + + +
*　　　　　　　　　　┃┫┫　┃┫┫
*　　　　　　　　　　┗┻┛　┗┻┛+ + + +
*/
#include <iostream>
#include <string>
#include <time.h>
using namespace std;
#define TEMP(T) template<class T>
#define DEBUG //用来确定是否文本输出。
#ifndef re(i,n)
#define re(i,n) for(unsigned int i=0;i<n;i++)
#endif // !re(i,n)
#ifndef Re(i,n)
#define Re(i,n)		for(unsigned int i=1;i<=n;i++) //循环n次
#endif // !Re(i,n)
void debug(string warning)
{
	cerr << warning << endl;
	system("pause");
	exit(1);
}

TEMP(T)
struct node
{
	node<T>* next;
	T data;
	node(T const &a=0) :data(a),next(NULL){}
};

TEMP(T)
void link(node<T>* one, node<T>* two)
{
	if (one)
		one->next = two;
}
TEMP(T)
node<T> * create(T const a[], unsigned n)
{
	node<T>* head, *p1;
	if (!a)	return NULL;
	head = p1 = new node<T>(a[0]);
	Re(i, n - 1)
	{
		link(p1, new node<T>(a[i]));
		p1 = p1->next;
	}
	p1->next = NULL;
	return head;
}

TEMP(T)
 void insert(node<T>* &head,T const & a,unsigned int n)
{
	node<T>* p1 = head, *p2 = new node<T>(a);
	if (n == 0)
	{
		link(p2, head);
		head = p2;
		return;
	}
	re(i,n-1)
		p1 = p1->next;
	link(p2, p1->next);
	link(p1, p2);
	return;
}

TEMP(T)
void print(node<T> *head)
{
	while (head)
	{
		cout << head->data << ' ';
		head = head->next;
	}
	cout << endl;
}
 
TEMP(T)
node<T>* create2(T const a[], unsigned n)
{
	node<T> *head, *p1;
	head = p1 = new node < T > ;
	re(i, n)
	{
		link(p1, new node<T>(a[i]));
		p1 = p1->next;
	}
	p1->next = NULL;
	return head;
}

TEMP(T)
void insert2(node<T>* &head, T const &a,unsigned int n)
{
	node<T> *p1=head,*p2=new node<T>(a);
	re(i, n)
		p1 = p1->next;
	link(p2, p1->next);
	link(p1, p2);
}
TEMP(T)
void print2(node<T> *head)
{
	while (head->next)
	{
		cout << head->next->data << ' ';
		head = head->next;
	}
	cout << endl;
}

TEMP(T)
void Del(node<T>* head, T const &a)
{
	node<T>* p1;
	while (head&&head->next)
	{
		while (head->next&&head->next->data == a)
		{
			p1 = head->next;
			link(head, head->next->next);
			delete p1;
		}
		head = head->next;
	}
}

int main()
{
	srand(time(NULL));
#ifdef DEBUG
	FILE *err; //没用的指针... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif

	char a[1000] = "abcdefghijklmnopqrstuvwxyz";
	node<char>* head1 = create(a, 26);
	node<char>* head2 = create2(a, 26);
	print(head1);
	print2(head2);
	re(i, 10)
		insert(head1, char('a' + i),1);
	re(i, 20)
		insert2(head2, char('a' + i),0);
	print(head1);
	print2(head2);

#ifndef DEBUG //加个断点。
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}