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
using namespace std;

#define DEBUG //用来确定是否文本输出。
#define Re(i,n)		for(int i=0;i<n;i++) //循环n次
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
	//freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	//10_3
	ofstream out("test1.txt");
	out << "已经成功写入文件！" << endl;
	out.close();

	//10_4
	ifstream in("test1.txt");
	if (!in)debug("打不开test1.txt");
	string one;
	in>>one;
	cout << "在test1.txt中的字符：\n";
	cout << one << endl;
	in.close();
	

	//10_5
	out.open("test1.txt", ios_base::app);
	out << "已成功添加字符!" << endl;
	out.close();

#ifndef DEBUG //加个断点。
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}