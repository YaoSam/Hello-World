#include <iostream>
using namespace std;
#include "Circle.h"
//#define DEBUG
/*ûʲô��˵��*/

int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	Circle a(2);
	a.ShowArea();
	a.ShowPerimeter();

#ifndef DEBUG 
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}