#include <iostream>
using namespace std;
//#define DEBUG
/*++x��+�����ã�x++�����ú�+*/
int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	int myAge = 39,yourAge = 39;
	cout << "I am :" << myAge << " years old. " << endl;
	cout << "You are :" << yourAge << " years old. " << endl;

	myAge++;
	++yourAge;
	cout << "One year passes..." << endl;
	cout << "I am :" << myAge << " years old. " << endl;
	cout << "You are :" << yourAge << " years old. " << endl;

	cout << "Another year passes." << endl;
	cout << "I am :" << myAge ++<< " years old. " << endl;
	cout << "You are :" << ++yourAge << " years old. " << endl;

	cout << "Let's print it again.'" << endl;
	cout << "I am :" << myAge << " years old. " << endl;
	cout << "You are :" << yourAge << " years old. " << endl;
#ifndef DEBUG
		printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}