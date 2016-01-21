#ifndef _TEM_H__
#define _TEM_H__

#include <iostream>
using namespace std;

template <class Elem>
class List {
private:
	Elem data;
public:
	List(Elem a) {
		data = a;
	}
	void print(void);
};

//#include "templateclass.cpp"
#endif