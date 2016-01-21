#pragma once
#include <iostream>
using namespace std;

class Y;
class Z;
class X
{
	int i;
	friend int h(X &abc);
	friend int Y::g();
	friend class Z; 
public:
	X(int n) :i(n){}
	void show()
	{
		cout << i << endl;
	}
};

class Y
{
	X one;
public:
	Y(int n) :one(n){}
	int g()
	{
		one.i++;
		one.show();
		return 0;
	}
};

class Z
{
	X a;
public:
	Z(int n) :a(n){}
	int f()
	{
		a.i += 5;
		a.show();
		return 0;
	}
};

int h(X &a)
{
	a.i += 10;
	a.show();
	return 0;
}