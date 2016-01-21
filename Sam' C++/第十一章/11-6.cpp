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

//#define DEBUG //用来确定是否文本输出。
#define Re(i,n)		for(int i=0;i<n;i++) //循环n次
void debug(string warning)
{
	cerr << warning << endl;
	system("pause");
	exit(1);
}

struct dog{
	int age, weight;
};



int main()//我是呆萌哒妹函数~
{
#ifdef DEBUG
	FILE *err; //没用的指针... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	dog dog1 = { 5, 10 };
	//文本输入输出
	ofstream out;
	out.open("11-6.txt");
	out << dog1.age << ' ' << dog1.weight << endl;
	out.close();

	ifstream in;
	in.open("11-6.txt");
	if (!in)debug("无法代开文档11-6.txt");
	dog dog2;
	in >> dog2.age >> dog2.weight;
	in.close();
	
	cout << "dog2：" << dog2.age << ' ' << dog2.weight << endl;
	//二进制处理
	out.open("11-6.txt", ios_base::binary);
	out.write(reinterpret_cast<char *>(&dog1), sizeof(dog));
	out.close();

	in.open("11-6.txt", ios_base::binary);
	if (!in)debug("无法代开文档11-6.txt");
	dog2.age = 123;
	in.read(reinterpret_cast<char *>(&dog2), sizeof(dog));
	
	cout << "dog2：" << dog2.age << ' ' << dog2.weight << endl;


#ifndef DEBUG //加个断点。
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}