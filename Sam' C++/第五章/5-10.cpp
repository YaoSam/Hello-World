#include <iostream>
#include <string>

using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=1;i<=n;i++)
#define RE(n)		for(int I=1;I<=n;I++)

/*����ע��*/
/*Sample Input:

*/
class Test{
private :
	static int num;
public:
	Test(){}
	Test(int n)
	{
		num = n;
	}
	void show()
	{
		cout << num << endl;
	}
};
int Test::num = 10;
int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	Test().show();
	Test(12).show();
	Test one(123);
	one.show();
	Test two(123112);
	two.show();


#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}