#include <iostream>
using namespace std;
//#define DEBUG
/*���Բ�ͬ*/
class A
{
private: int a;
public :
	A(int n)
	{
		a = 2*n;
	}
	void showa()
	{
		cout << a << endl;
	}
};
int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	A a1(3), a2(4);
	a1.showa(),a2.showa();
#ifndef DEBUG
	cout << "a1��a2��a��ͬ";
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}