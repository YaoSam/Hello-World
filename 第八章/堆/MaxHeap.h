#pragma once
#include <iostream>
#include <string>
#undef  TEMP
#define TEMP template <class T>
#undef  re
#define re(i,n) for(unsigned int i=0;i<n;i++)
//ֻ��Ҫ����>
TEMP bool operator<	(T const & a, T const &b)	{	return	b > a;					}
TEMP bool operator>=	(T const & a, T const &b)	{	return	a > b || !(b > a);		}
TEMP bool operator<=	(T const & a, T const &b)	{	return	!(a > b);				}
TEMP bool operator!=	(T const & a, T const &b)	{	return	a > b || b > a;		}
TEMP bool operator==	(T const & a, T const &b)	{	return	!(a>b) && !(b>a);	}
TEMP void Swap(T &a, T &b);

const int HeapSize = 100000;
TEMP
class MaxHeap
{
	//��¼���һ���ڵ�
	int Current;
	T *Heap;
	//���µ���i�ڵ㡣
	void Down( int i);
	//���ϵ����ڵ�
	void Up(int i);
public:
	//���캯����ͨ�������������Žڵ�ʵ�֡�
	MaxHeap(T const *data = NULL, unsigned int n = 0);
	//��̬�����ڴ����Ҫ����������������
	MaxHeap(MaxHeap<T> const & other):Current(other.Current),Heap(new T[HeapSize])
	{
		memcpy(Heap, other.Heap, sizeof(T)*Current);
	}
	MaxHeap<T>& operator=(MaxHeap<T> const & other);
	~MaxHeap(){ delete[] Heap; }
	//����
	void push(T const &X);
	//�����ڵ㡣��ɾ��
	T pop();
	bool isEmpty()const{ return Current < 0; }
	//��������ѵġ�
	friend std::ostream & operator<<(std::ostream& out, MaxHeap<T>const &other)
	{
		if (other.Current < 0)return out;
		unsigned int level = 0;
		re(i, other.Current + 1)
		{
			if (i == ((1 << level) - 1))
			{
				out << std::endl;
				level++;
			}
			out << other.Heap[i] << " ";
		}
		return out << std::endl;
	}
};
TEMP
void heapSort(T a[], unsigned int n);
