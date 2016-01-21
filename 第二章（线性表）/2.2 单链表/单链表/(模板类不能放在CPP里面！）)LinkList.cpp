#include "LinkList.h"
template <class T>
LinkList<T>::LinkList()
{
	head = NULL;
}

template  <class T>
LinkList<T>::LinkList(T a[], int n)
{
	head = new node <T>;
	node<T> *temp = head;
	re(i, n)
	{
		temp->next = new node < T >;
		temp = temp->next;
		temp->data = a[i];
	}
	temp->next = NULL;
}

template <class T>
LinkList<T>::~LinkList()
{
	node<T> *temp;
	while (head != NULL)
	{
		temp = head->next;
		delete head;
		head = temp;
	}
}

template <class T>
int LinkList<T>::Length() const
{
	int count = 0;
	node<T>	*temp = head->next;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

template <class T>
T LinkList<T>::Get(int i) const
{
	node<T> *temp = head;
	if (i == 0) throw "不能为零";
	re(j, i)
	{
		if (temp != NULL)
			temp = temp->next;
		else
			throw "查找越界";
	}
	return temp->data;
}

template <class T>
int LinkList<T>::find(T const &x) const
{
	node<T> *temp = head->next;
	int count = 0;
	while (temp != NULL)
	{
		count++;
		if (temp->data == x)
			return count;
		temp = temp->next;
	}
	return  -1;
}

template <class T>
void LinkList<T>::Insert(int i, T const &x)
{
	node<T> *temp = head;
	if (i == 0)	return;
	re(j, i - 1)
	{
		if (temp != NULL)
			temp = temp->next;
		else
			throw"插入下标越界";
	}
	node<T> *one = temp->next;
	temp->next = new node < T >;
	temp->next->data = x;
	temp->next->next = one;
	return;
}

template <class T>
T LinkList<T>::Delete(int i)
{
	node<T> *temp = head;
	re(j, i - 1)
	{
		if (temp != NULL)
			temp = temp->next;
		else throw "删除下标越界";
	}
	node<T> *temp2 = temp->next->next;
	T one = temp->next->data;
	delete temp->next;
	temp->next = temp2;
	return one;
}

template < class T >
void LinkList<T>::PrintList()const
{
	node<T> *p = head->next;
	if (!p)cout << "链表为空" << endl;
	while (p != NULL)
	{
		std::cout << p->data << ' ';
		p = p->next;
	}
	std::cout << std::endl;
}

//下面是测试代码
/*
srand(time(NULL));
cout << "hello everyone" << endl;
int a[1000];
re(i, 1000)
a[i] = rand() % 100;
re(i, 50)
cout << a[i] << ' ';
cout << endl;
LinkList<int> one(a, 50);
one.PrintList();
one.Insert(1, 11111);
one.Insert(3, 23333);
one.PrintList();
one.Delete(3);
one.PrintList();

re(i, 50)
cout << one.find(a[i]) << " " << one.Get(i+1) << ' ' << endl;
re(i, 51)
{
one.Delete(50-i);
cout << one.Length() << endl;
one.PrintList();
}
*/