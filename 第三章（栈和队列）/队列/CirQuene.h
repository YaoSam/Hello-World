#pragma once
#ifndef TEMP
#define TEMP template<class T>
#endif // !TEMP

int const QueneSize=1000;

TEMP
class CirQuene
{
	unsigned int front, rear;
	T data[QueneSize];
public:
	CirQuene() :front(0), rear(0){}
	void push(T const & object)
	{
		data[front] = object;
		front++;
		front %= QueneSize;
	}
	T pop()
	{
		if (rear == front)
			throw "Quene Empty";
		T temp = data[rear];
		rear++; 
		rear %= QueneSize;
		return temp;
	}
	bool isEmpty(){ return (rear == front); }
	bool isFull(){ return front + 1 == rear || (front == QueneSize - 1 && rear == 0); }
	~CirQuene(){}

};
