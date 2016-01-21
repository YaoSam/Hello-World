#include <iostream>
#include <string>
using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)

/*����ע��*/
/*���찴����˳����������
���ı�����ῴ�ñȽ������*/
/*Sample Output:
A mammal is born.
A dog is born.
A dog is dead.
A mammal is dead.
*/
class Mammal
{
public:
	Mammal()
	{
		cout << "A mammal is born." << endl;
	}

	~Mammal()
	{
		cout << "A mammal is dead." << endl;
	}

private:

};

class Dog:public Mammal
{
public:
	Dog():Mammal()
	{
		cout << "A dog is born." << endl;
	}

	~Dog()
	{
		cout << "A dog is dead." << endl;
	}

private:

};


int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	Dog one;

#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}