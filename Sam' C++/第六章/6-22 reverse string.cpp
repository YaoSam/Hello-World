#include <iostream>
#include <string>

using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)
#define RE(n)			for(int I=0;I<n;I++)

/*程序注释*/
/*
打了两种做法。
void：用了全局变量left，right来指示递归。
string：用了substr和字符串的‘+’来重组字符串。
*/
/*Sample Input:

*/

void swap(char &a, char &b)
{
	char sto = a;
	a = b;
	b = sto;
}

//int left, right=-1;
//void reverse1(string &s)//void有点难想。参数又固定了，只能用全局变量。
//{
//
//	if(right<0)			left=0, right=s.length()-1;//用right来定义开关。
//#ifdef debug
//	cout << s.substr(left, right - left) << endl;
//#endif	
//	if (left < right)	swap(s[left++], s[right--]), reverse1(s);
//	else right = -1; //递归结束，重新初始化
//}

string reverse(string &s)//这里用了string类型的函数... ...
{
#ifdef DEBUG
cout << s << endl;//查看递归过程
#endif
	s.su
	if(s.length()>1)
		s =s[s.length()-1]+reverse(s.substr(1, s.length() - 2)) + s[0]; //需要递归的次数为s.length()/2
	//另一种写法
	//s =reverse(s.substr(1, s.length() - 1)) + s[0]; //代码简短一点，需要递归的次数为s.length()
	return s;
}


int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	string abc = "1234567890";
	cout <<"倒转前："+ abc << endl;
	reverse(abc);
	cout <<"倒转后："+ abc << endl;
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}