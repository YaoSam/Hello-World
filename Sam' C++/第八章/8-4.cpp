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

class Counter
{
	int C;
public:
	Counter() :C(0){}
	void operator +(int n){ C += n; }
	friend ostream& operator<<(ostream & out, const Counter &other);
};
ostream& operator<<(ostream & out, const Counter &other)
{
	out << other.C;
	return out;
}



int main()//我是呆萌哒妹函数~
{
#ifdef DEBUG
	FILE *err; //没用的指针... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	Counter one;
	Re(i, 100)
		one + 100;
	cout << one << endl;

#ifndef DEBUG //加个断点。
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}