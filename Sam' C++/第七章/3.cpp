
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
//3. 分别定义Teacher(教师）类和Cadre(干部），采用多重继承方式由这两个类派生出新类Teacher_Cadre(教师兼干部）。要求：
//	（1）两个基类中都包含姓名、年龄、性别、地址、电话等数据成员。
//	（2）在Teacher类中还包含数据成员title(职称），在Cadre类中还包含数据成员post(职务），在Teacher_Cadre类中还包含数据成员wages(工资）。
//	（3）对两个基类中的姓名、年龄、性别、地址、电话等数据相同的名字，在引用这些数据成员时，指定作用域。
//	（4）在类体中声明成员函数，在类外定义成员函数。
//	（5）在派生类Teacher_Cadre的成员函数show中调用Teacher类中的display函数，输出姓名、年龄、性别、地址、电话，然后再用cout语句输出职务与工资。
//

class Teacher
{
protected:
	string Name,Address,PhoneNumber,Title;
	bool Gender;
	int Age;
public:
	Teacher(string name, int age, bool gender, string address, string phone,string title);
	void display();
};
Teacher::Teacher(string name, int age, bool gender, string address, string phone,string title) :
Name(name),
Age(age),
Gender(gender),
Address(address),
PhoneNumber(phone),
Title(title)
{}
void Teacher::display()
{
	cout << "姓名" << Name << endl
		<< "年龄" << Age << endl
		<< "性别" << (Gender ? "男" : "女") << endl
		<< "地址：" << Address << endl
		<< "电话号码" << PhoneNumber << endl;
}


class Cadre
{
protected:
	string Name,Address,PhoneNumber,Post;
	bool Gender;
	int Age;
public:
	Cadre(string name, int age, bool gender, string address, string phone, string post);
	void display();
};
Cadre::Cadre(string name, int age, bool gender, string address, string phone, string post) :
Name(name),
Age(age),
Gender(gender),
Address(address),
PhoneNumber(phone),
Post(post)
{}
void Cadre::display()
{
	cout << "姓名：" << Name << ' '
		<< "年龄：" << Age << ' '
		<< "性别：" << (Gender ? "男" : "女") << ' ' << endl
		<< "地址：" << Address << ' '
		<< "电话号码" << PhoneNumber << endl;
}

class Teacher_Cadre :public Teacher, public Cadre
{
	int Wages;
public:
	Teacher_Cadre(string name, int age, bool gender, string address, string phone, string title,string post,int wages);
	void show();
};

Teacher_Cadre::Teacher_Cadre(string name, int age, bool gender, string address, string phone, string title, string post, int wages):
Teacher(name, age, gender, address, phone, title),
Cadre(name, age, gender, address, phone, post),
Wages(wages)
{}

void Teacher_Cadre::show()
{
	Teacher::display();
	cout << "职务：" << Post << endl << "工资：" << Wages<<endl;
}



int main()//我是呆萌哒妹函数~
{
#ifdef DEBUG
	FILE *err; //没用的指针... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	Teacher one("姚炜昌", 20, 1, "中山大学173-607", "10086", "学生");
	one.display();
	Teacher_Cadre two("姚炜昌", 20, 1, "中山大学173-607", "10086", "学生", "大一新生", 125);
	two.show();

#ifndef DEBUG //加个断点。
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}