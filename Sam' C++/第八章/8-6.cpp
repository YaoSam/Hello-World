/*
*
*　　　	 　　　　┏┓　           ┏┓+ +
*　　  　　　　　┏┛┻━━━━━━┛┻┓ + +
*　　  　　　　　┃　　　　       ┃ 　
*　　  　　　　　┃　　　━　　  ┃ ++ + + +
*　　  　　		  ┃  ███━███  ┃+
*　　  　　　　　┃　　　　　　 ┃ +
*　　  　　　　　┃　　   ┻　　  ┃
*　　  　　　　　┃　　　　　　┃ + +
*　　  　　　　　┗━┓　　　 ┏━┛
*　　　　　　　　　┃　　　┃　　　　　　　　　　　
*　　　　　　　　　┃　　　┃ + + + +
*　　　　　　　　　┃　　　┃　　　　Code is far away from bug with the animal protecting　　　　　　　
*　　　　　　　　　┃　　　┃ + 　　　　神兽保佑,代码无bug　　
*　　　　　　　　　┃　　　┃
*　　　　　　　　　┃　　　┃　　+　　　　　　　　　
*　　　　　　　　　┃　 　　┗━━━┓ + +
*　　　　　　　　　┃ 　　　　　　　┣┓
*　　　　　　　　　┃ 　　　　　　　┏┛
*　　　　　　　　　┗┓┓┏━┳┓┏┛ + + + +
*　　　　　　　　　　┃┫┫　┃┫┫
*　　　　　　　　　　┗┻┛　┗┻┛+ + + +
*/
#include <iostream>
#include <string>
using namespace std;

//#define DEBUG //用来确定是否文本输出。
#define Re(i,n)		for(int i=0;i<n;i++)

/*程序说明*/
/*Sample Input:

*/

class one
{
protected:
	int num1;
public:
	one(int n) :num1(n){}
	one operator+(one const &other)
	{
		num1 *= 2;
		cout << "I did a plus in one" << endl;
		cout << num1 << endl;
		return one(other.num1);
	}
	void show()
	{
		cout << "show1" << endl;
	}
};
class two :public one
{
	int num2;
public:
	two(int n1, int n2) :one(n1), num2(n2){}
	two operator+(two const &other)
	{
		two a(*this);
		a.one::operator+(other);
		cout << "i did a plus in two" << endl;
		cout << num1 << ' ' << num2 << endl;
		return two(num1, other.num2);
	}
	void show()
	{
		one::show();
		cout << "show2" << endl;
	}
};

int main()//我是呆萌哒妹函数~
{
#ifdef DEBUG
	FILE *err; //没用的指针... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	two a(100, 100);
	two b(1, 12345);
	a + b;
#ifndef DEBUG //加个断点。
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}