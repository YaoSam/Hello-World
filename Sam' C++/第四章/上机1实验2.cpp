#include <iostream>
using namespace std;
//#define DEBUG
/*ûʲô��˵��*/
class Array
{
private:
	int num[10];
	int Max;
public:
	Array(int a[])
	{
		Max = a[0];
		for (int i = 0; i < 10; i++)
		{
			if (Max < a[i])Max = a[i];
			num[i] = a[i];
		}
	}
	void ShowArray()
	{
		for (int i = 1; i <= 10; i++) cout << num[i - 1]<<' ';
		cout << endl;
	}
	void showMax()
	{
		cout << "���ֵΪ��" << Max<<endl;
	}
};

int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	Array one(a);
	one.ShowArray();
	one.showMax();
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}