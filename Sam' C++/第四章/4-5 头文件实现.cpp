#include <iostream>
using namespace std;
#include "People.h"
//#define DEBUG
/*ûʲô��˵��*/
int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	People me(14336238, 0, "441900199509306330", 19950930);
	me.ShowPeople();

#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}