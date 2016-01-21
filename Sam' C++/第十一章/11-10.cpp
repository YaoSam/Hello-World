/*
*
*　　　	 　　　　   ┏┓　		 ┏┓+ +
*　　  　　　　　┏┛┻━━━━━━┛┻┓ + +
*　　  　　　　　┃　　　　       ┃ 　
*　　  　　　　　┃　　　━　　 ┃ ++ + + +
*　　  　　		   ┃  ███━███  ┃+
*　　  　　　　　┃　　　　　　┃ +
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
#include <winstring.h>
#include <fstream>
#include <sstream>
#include <locale>
using namespace std;

//#define DEBUG //用来确定是否文本输出。
#define Re(i,n)		for(int i=1;i<=n;i++) //循环n次
void debug(string warning)
{
	cerr << warning << endl;
	system("pause");
	exit(1);
}

int main()//我是呆萌哒妹函数~
{
#ifdef DEBUG
	FILE *err; //没用的指针... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif

	int Count[10000] = { 0 };					//用来计数。
	wstring str;										//用来将字符与数目对应。
	wchar_t temp; 
	wifstream in("11-10.txt");
	if (!in) debug("无法打开文档");
	locale loc(".936");								//编码格式必须改... ...FXXK... ...
	wcout.imbue(loc);
	in.imbue(loc);
	while ((temp = in.get()) != WEOF)		//宽字符的结束和平时不一样... ...FXXK。真实的值为65535 .
	{
		if (str.find(temp) == wstring::npos)
		{
			str += temp;
			Count[str.length()-1]++;
		}
		else Count[str.find(temp)]++;	
	}
	Re(i, str.length())
		wcout << str[i - 1] << ": " << Count[i - 1] << '\t';
	//Just have fun!!!
#ifndef DEBUG 
	printf("\n");
	system("pause");	//加个断点。
#endif // !DEBUG
	return 0;
}