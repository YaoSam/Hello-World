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

//4. 编程实现以下功能：
//（1）	按职工号由小到大的顺序将5个员工的数据（包括号码、姓名、年龄、工资）输出到磁盘文件中保存。
//（2）	从键盘输入两个员工的数据（职工号大于已有的职工号），增加到文件的末尾。
//（3）	输出文件中全部职工的数据。
//（4）	从键盘输入一个号码，从文件中查找有无此职工号，如有则显示此职工是第几个职工，以及此职工的全部数据。如没有，就输出“无此人”。可以反复多次查询，如果输入查找的职工号为0，就结束查询。


//第一题中的模板排序
template <class T>
void myswap(T &a, T &b){
	T temp = a;
	a = b;
	b = temp;
	return;
}
template <class T>
void mysort(T *array, int left, int right)//冒泡
{
	for (int i = left; i < right; i++)
		for (int j = right; j > i; j--)
			if (!(array[j] > array[j - 1]))
				myswap(array[j], array[j - 1]);
}

//（包括号码、姓名、年龄、工资）
struct employee{
	int num;
	string name;
	int age;
	int wage;
};
//用来排序用的
bool operator>(employee const &a, employee const &b){ return a.num > b.num; }
//用来输入输出。
ostream &operator<<(ostream &out, const employee &other)
{
	return out << other.name << ' ' << other.num << ' ' << other.age << ' ' << other.wage << endl;
}
istream &operator>>(istream &in, employee &other)
{
	return in>> other.name>> other.num  >> other.age >> other.wage;
}


int main()//我是呆萌哒妹函数~
{
#ifdef DEBUG
	FILE *err; //没用的指针... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	//(1)
	employee many[10] = { { 15, "姚炜昌", 20, 1000 }, { 3, "姚力涛", 20, 2000 }, { 2, "SamYao", 18, 1000 }, { 10, "BobYao", 20, 12312 }, {5,"无名氏",30,1233} };
	//由小到大的顺序
	mysort(many, 0, 4);
	//输出到磁盘文件中保存。
	ofstream out("employee.dat");
	Re(i, 5)out << many[i - 1];
	out.close();
	memset(many, 0, sizeof(many));

	//(2)
	cout << "请输入两个员工的数据" << endl;
	//从键盘输入两个员工的数据
	Re(i, 2)cin >> many[i];
	//增加到文件的末尾。
	out.open("employee.dat", ios_base::app);
	Re(i, 2)out << many[i];
	out.close();
	memset(many, 0, sizeof(many));

	//(3)
	ifstream in("employee.dat");
	//输出文件中全部职工的数据。
	Re(i, 7)in >> many[i],cout<<many[i];
	in.close();
	
	//(4)
	int num;
	bool flag = 0;
	cout << "请输入查找的员工代码：" << endl;
	while (cin >> num)
	{
		Re(i, 7)
			if (many[i].num == num)
			{
				cout << "找到员工：" << many[i];
				flag = 1;
				break;
			}
		if(!flag)cout << "无法找到员工。" << endl;
		flag = 0;
	}

#ifndef DEBUG //加个断点。
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}