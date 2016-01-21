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
#define Re(i,n)		for(int i=1;i<=n;i++) //循环n次
void debug(string warning)
{
	cerr << warning << endl;
	system("pause");
	exit(1);
}

//3. 建立两个磁盘文件f1.dat和f2.dat，编程实现以下工作：
//（1）	从键盘输入20个整数，分别存放到两个磁盘文件中（每个文件中放10个整数）；
//（2）	从f1.dat读入10个数，然后存放到f2.dat文件原有数据的后面；
//（3）	从f2.dat中读入20个整数，将它们按从小到大的顺序存放到f2.dat(不保留原来的数据)。
//

//冒泡排序
void mysort(int *num, int left, int right){
	int temp;
	for (int i = left; i < right; i++)
		for (int j = right; j > i;j--)
			if (num[j] < num[j - 1])
			{
				temp = num[j];
				num[j] = num[j - 1];
				num[j - 1] = temp;
			}
}

int main()//我是呆萌哒妹函数~
{
#ifdef DEBUG
	FILE *err; //没用的指针... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	//(1)
	//从键盘输入20个整数，
	int *num=new int[100];
	cout << "请输入20个整数" << endl;
	Re(i, 20)cin >> num[i];
	//分别存放到两个磁盘文件中（每个文件中放10个整数）；
	ofstream out;
	out.open("f1.dat");
	Re(i, 10)out << num[i] << endl;
	out.close();

	out.open("f2.dat");
	Re(i, 10)out << num[i + 10] << endl;
	out.close();
	delete[] num;

	//(2)
	num = new int[100];
	ifstream in;
	in.open("f1.dat");
	if (!in)debug("无法打开文件f1.dat");
	//	从f1.dat读入10个数，
	Re(i, 10)in >> num[i];
	in.close();
	//然后存放到f2.dat文件原有数据的后面；
	out.open("f2.dat", ios_base::app);
	Re(i,10)out << num[i] << endl;
	out.close();
	delete[] num;
	//(3)
	num = new int[100];
	//从f2.dat中读入20个整数，
	in.open("f2.dat");
	Re(i, 20)in >> num[i];
	in.close();
	//将它们按从小到大的顺序存放到f2.dat(不保留原来的数据)。
	mysort(num, 1, 20);
	out.open("f2.dat");
	Re(i, 20)out << num[i] << endl;
	out.close();
	delete[] num;
#ifndef DEBUG //加个断点。
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}