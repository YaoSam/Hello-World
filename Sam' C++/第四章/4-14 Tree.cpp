#include <iostream>
using namespace std;
//#define DEBUG
/*ûʲô��˵��*/
class Tree
{
private:
	int Age;
public:
	Tree(int a)
	{
		Age = a;
	}
	int grow(int years)
	{
		Age += years;
		return Age;
	}
	int age()
	{
		cout << "Ages is:" << Age<<endl;
		return Age;
	}
};

int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	Tree one(13);
	one.age();
	one.grow (13);
	one.age();

#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}