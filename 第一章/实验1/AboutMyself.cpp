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
#include <time.h>
using namespace std;

#define DEBUG //用来确定是否文本输出。
#ifndef re(i,n)
#define re(i,n) for(int i=0;i<n;i++)
#endif // !re(i,n)
#ifndef Re(i,n)
#define Re(i,n)		for(int i=1;i<=n;i++) //循环n次
#endif // !Re(i,n)

void debug(string warning)
{
	cerr << warning << endl;
	system("pause");
	exit(1);
}
/************************************************************************/
/* 实验大纲                                                                     */
/************************************************************************/
//1.定义模板 template < class DataType >
//2.class AboutMyself
//{
//		定义一个记录个人信息的结构，其中ID为类型DataType(这样以后定义对象时可选择为int 或char)的数组
//		定义一个字符串记录个人爱好信息
//		在构造函数中赋初值信息
//		增加相应的成员函数进行相应的输入及显示结果
//}
//3．在main()中：
//	·定义一个100个元素的float型数组A;
//		·用随机数给A的各元素赋值;
//		·定义AboutMyself类的对象Me（此时要制定DataType为int或者char）
//			·显示A中的结果
//			·输入和显示Me的相关信息。
//
#define MAX 8
template <class T>
class AboutMyself
{
	struct PersonalInformation
	{
		string name;
		bool gender;// 男0，女1
		int age;
		T ID[MAX];
		PersonalInformation(const string &a, bool b, int c) :name(a), gender(b), age(c){}
	}me;
	string interest;
public:
	AboutMyself(const string &name="我", bool gender=0, int age=0, const T id[]=NULL, const string &interest="无"):
		interest(interest),
		me(name,gender,age)
	{
		if(id)	//id!=NULL
			memcpy(me.ID, id, sizeof(T)*MAX);
	}
	friend ostream &operator<<(ostream &out, const AboutMyself<T> &other )
	{
		out << "姓名：" << other.me.name << endl
			<< "性别：" << (other.me.gender ? "女" : "男" )<< endl
			<< "年龄：" << other.me.age << endl;
		re(i, MAX)
			out << other.me.ID[i];
		return out<<endl << "" << other.interest;
	}
};


int main()
{
	srand(time(NULL));
#ifdef DEBUG
	FILE *err; //没用的指针... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	float A[100];
	re(i, 100)
		A[i] = float(rand()) / float(RAND_MAX) * 100;
	AboutMyself<char> ME("hello", 0, 18, "14336238", "唱歌跳舞打代码");
	re(i, 100)
		cout << A[i] << ' ';
	cout << endl;
	cout << ME << endl;

#ifndef DEBUG //加个断点。
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}