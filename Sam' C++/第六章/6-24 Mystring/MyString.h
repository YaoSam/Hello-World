#include <iostream>
#include <string>
//using namespace std;
#define Re(i,n) for(int i=0;i<=n;i++)
class MyString
{
private:
	char *str;
	int len;		//str[len]='\0'
	int Getlen(char const *one)const;
public:
	MyString();
	MyString(char const one[]);						//正常的构造函数。
	MyString(std::string const &other);			//输入为string的构造函数。虽然我知道有点无聊。有string谁还会用MyString呢？
	MyString(MyString const &other);
	MyString &operator=(MyString const &other);
	~MyString();
	void show(){ std::cout << len << ": " << str << std::endl; }
	MyString operator+(MyString const &other)const ;
	void operator+=(MyString const &other);
	char &operator[](int i);
};
MyString::MyString()
{
	len = 0; 
}
MyString::MyString(char const one[])
{
	len = Getlen(one);
	str = new char[len + 10];
	Re(i, len)str[i] = one[i];
}
MyString::MyString(std::string const &other)
{
	len = other.length();
	str = new char[len + 10];
	Re(i, len)str[i] = other[i];
	str[len] = '\0';//保险起见。
}
MyString::MyString(MyString const &other)
{
	str = new char[other.len+10];
	len = other.len;
	Re(i, len)
		str[i] = other.str[i];
}
MyString &MyString::operator=(MyString const &other)
{
	if (this == &other)return *this;
	char *temp = str;
	str = new char[other.len + 10];
	len = other.len;
	Re(i, len)
		str[i] = other.str[i];
	delete[] temp;
	return *this;
}

MyString::~MyString()
{
	delete[] str;
}
int MyString::Getlen(char const *one)const
{
	int i = 0;
	while (one[i] != '\0')i++;
	return i;						//此时one[i]=='\0' 即下标可以到达''\0
}
MyString MyString::operator+(MyString const &other)const
{
	MyString temp;
	temp.len = len + other.len;
	temp.str = new char[temp.len + 10];
	Re(i, len)			temp.str[i] = str[i];					//str[len]=='\0'
	Re(i, other.len)	temp.str[i + len] = other.str[i]; //str[len]=other.str[0],str[len+other.len]=other.str[other.len];
	return temp;
}
void MyString::operator+=(MyString const &other)
{
	*this = *this + other;
}
char &MyString::operator[](int i)
{
	if(i<len)return str[i];
	else std::cout << "下标越界！" << std::endl;		//一点异常处理
	return str[len+1];
}
