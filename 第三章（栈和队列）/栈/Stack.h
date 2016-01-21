#include <iostream>
#include <string>
#include <time.h>

using namespace std;
 int const StackSize = 10000;

template <class T>
class Stack
{
public:
	 int top;
	T data[StackSize];
public:
	Stack(T a[] = NULL, unsigned num = 0): top(num-1)
	{
		if (num > StackSize)
			throw "Stack Overflow";
		if (a)
			memcpy(data, a, num*sizeof(T));
	}
	void clear()	{ memset(data, 0, sizeof(data)); top = -1; }
	int Top()const{ return top; }
	bool isEmpty()
	{
		return (top < 0); 
	}
	T pop()
	{
		if (top < 0)
			throw "Stack Empty";
		return data[top--];
	}
	void push(const T &one)
	{
		if (top>= StackSize)
			throw "Stack Overflow";
		data[++top]=one;
	}
	T GetTop() const
	{
		if (top < 0)
			throw "Stack Empty";
		return data[top];
	}
	T operator()()
	{
		if (top<0)
			throw "Stack Empty";
		return data[top--];
	}
	void operator()(const T & one)
	{
		if (top >= StackSize)
			throw "Stack Overflow";
		data[++top] = one;
	}
};

typedef Stack<int> StackInt;
typedef Stack<char> StackChar;
