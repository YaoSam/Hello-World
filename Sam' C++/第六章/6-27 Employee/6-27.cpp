#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

//#define DEBUG
/*Sample Input:

*/

int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	Employee one("Ҧ쿲�", "����", "��ɽ��ѧ 173-607", 10086);
	one.display();
	one.setname("��˧��");
	one.display();
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}