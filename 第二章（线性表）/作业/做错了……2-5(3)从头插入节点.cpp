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

template <class T>
struct node
{
	node<T> *pre, *next;
	T data;
	node(T data=0) :data(data){}
};
template <class T>
void link(node<T> *a, node<T>*b)
{
	if (a)a->next = b;
	if (b)b->pre = a;
}
template <class T>
node<T>* create(const T a[], unsigned int n)
{
	node<T> *head, *p1;
	if(a) head = p1 = new node<T>(a[0]);
	else
	{
		return NULL;
	}
	head->pre = NULL;
	Re(i,n-1)
	{
		link(p1, new node<T>(a[i]));
		p1 = p1->next;
	}
	p1->next = NULL;
	return head;
}

template <class T>
node<T>* insert(node<T> *&head, const T &a)
{
	if (head)
		link(new node<T>(a), head);
	else
		return new node<T>(a);
	head = head->pre;
	return head;
}

template <class T>
void print(node<T>* head)
{
	while (head)
	{
		cout << head->data << ' ';
		head = head->next;
	}
	cout << endl;
}

template <class T>
node<T>* create2(T a[], unsigned int n)
{
	node<T> *head, *p1;
	head = p1 = new node<T>;
	head->pre = NULL;
	re(i,n)
	{
		link(p1, new node<T>(a[i]));
		p1 = p1->next;
	}
	p1->next = NULL;
	return head;
}
template <class T>
node<T>* insert2(node<T>* head, const T &a)
{
	node<T>* temp = head->next;
	link(head, new node<T>(a));
	link(head->next, temp);
	return head;
}
template <class T>
void print2(node<T> *head)
{
	head = head->next;
	while (head)
	{
		cout << head->data << ' ';
		head = head->next;
	}
	cout << endl;
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
	re(i,10)
		head1=insert(head1, char('a'+i));
	re(i,10)
		insert2(head2, char('a' + i));

	print(head1);
	print2(head2);

	cout << "hello world" << endl;
#ifndef DEBUG //加个断点。
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}