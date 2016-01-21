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
*　　　　　　　　　┃　　　┃　　　　Code is far away from bug with the animal protecting*　　　　　　　　　┃　　　┃ + 　　　　神兽保佑,代码无bug　　
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
#define Re(i,n) for(unsigned int i=1;i<=n;i++) //循环n次
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
		Now->next = Pre;			//将Now指向前一个。
		Pre = Now;					//Pre 和 Now 的关系已经断了
		Now = Next;					//Now 和Now->next的关系也断了
		Next = Next->next;		//所以在这里判定循环条件。
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
	FILE *err; //没用的指针... ...
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

#ifndef DEBUG //加个断点。
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}