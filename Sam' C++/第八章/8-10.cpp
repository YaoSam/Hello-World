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
#define Re(i,n)		for(int i=0;i<n;i++) //循环n次

class point{
	int x, y;
public:
	point(int m=0, int n=0) :x(m), y(n){}
	friend point operator+(point const &A, point const &B);
	friend ostream &operator<<(ostream &out, point const &This);
};

point operator+(point const &A, point const &B){ return point(A.x + B.x, A.y + B.y); } //简洁如我
ostream &operator<<(ostream &out, point const &This){	return out << '(' << This.x << ',' << This.y << ')';}

int main()//我是呆萌哒妹函数~
{
#ifdef DEBUG
	FILE *err; //没用的指针... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	point one(123,43);
	cout << one + point(123,100) << endl;	//临时变量。
	cout << one + 200 << endl;					//自动类型转换

#ifndef DEBUG //加个断点。
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}