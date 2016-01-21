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
#include <fstream>
#include <sstream>
using namespace std;

#define DEBUG //用来确定是否文本输出。
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
	string line,temp;
	ostringstream str(temp);
	ifstream in("11-9.txt");
	int i = 1;
	while(getline(in, line))
		str <<i++<<": "<< line << endl;
	in.close();
	
	ofstream output("11-9.txt");
	output<<str.str();
	output.close();
#ifndef DEBUG //加个断点。
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}