#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MaxSize = 100;
template<class Datatype>
class Seqlist
{
public:
	Seqlist(){ length = 0; }
	Seqlist(Datatype a[], int n);
	void insert(Datatype x, int i);
	int locate(Datatype x);
	void Printlist();
	Datatype data[MaxSize];
	int length;
private:
};

template<class Datatype>
Seqlist<Datatype>::Seqlist(Datatype a[], int n)
{
	if (n>MaxSize) throw"illegal";
	for (int i = 0; i<n; i++)
		data[i] = a[i];
	length = n;
}

template<class Datatype>
void Seqlist<Datatype>::insert(Datatype x, int i)
{
	if (length >= MaxSize) throw"error";
	if (i<1 || i>length + 1) throw"inappropriate location";
	for (int j = length; j >= i; j--)
		data[j] = data[j - 1];
	data[i - 1] == x;
	length++
}
template<class Datatype>
void Seqlist<Datatype>::Printlist()
{
	for (int i = 0; i<length; i++)
		cout << data[i];
}

template<class Datatype>
int Seqlist<Datatype>::locate(Datatype x)
{
	int i;
	for (i = 0; i < length; i++)
		if (data[i] == x) return i + 1;
	return 0;
	/*{
		if (data[i] != x);
		else break;
	}
	return i;

	/*没有输出的罪魁祸首！就是这段代码！说明以后不能随便照搬书上的东西!*/
}

int p = 0, x1;
void Move(Seqlist<int>&L)
{
	int i = 0, j = L.length - 1;
	x1 = L.data[0];
	int temp;
	while (i != j)
	{
		while (j>i&&L.data[j]>x1) j--;
		while (i<j&&L.data[i]<x1) i++;
		if (i <= j) {
			temp = L.data[i];
			L.data[i] = L.data[j];
			L.data[j] = temp;
		}
	}
	p = L.locate(x1);
}
int search1(Seqlist<int>L, int x)
{
	/*	int j = 0;
	while (L.data[j] != x&&j<L.length)
	j++;
	return (j+1);*/
	int count = 0;
	for (int j = 0; j < L.length; j++)
	{
		if (L.data[j] != x) count++;
		else break;
	}
	return (count + 1);
}

int search2(Seqlist<int>L, int x)
{
	int count = 0;
	x1 = L.data[0];
	/*if (x <= x1)
	{
	while (L.data[j] != x&&j <= p)
	{
	j++;
	}
	return (j+1);
	}
	else
	{
	j = p + 1;
	while (L.data[j] != x&&j<L.length)
	j++;
	return (j-p);
	}*/
	if (x <= x1)
	{
		for (int j = 0; j <= p; j++)
		{
			if (L.data[j] != x)
				count++;
			else break;
		}
		return count;

	}
	else
	{
		for (int j = p + 1; j < L.length; j++)
		{
			if (L.data[j] != x) count++;
			else break;
		}
		return count;
	}
}

int main()
{
	int a[20];
	int n1, n2;
	int m1 = 0;
	int m2 = 0;
	srand((unsigned)time(NULL));
	for (int i = 0; i<20; i++)
		a[i] = (rand() % (40)) + 1;
	Seqlist<int>list(a, 20);
	Move(list);
	list.Printlist();
	for (int k = 1; k<150; k++)
	{
		int x = (rand() % (40)) + 1;
		n1 = search1(list, x);
		n2 = search2(list, x);
		if (k % 10 == 0)
			cout << n1 << " " << n2 << "  " << p << "  " << x << endl;
		m1 += n1;
		m2 += n2;
	}
	cout << m1 << endl;
	cout << m2 << endl;
	getchar();
	return 0;
}

