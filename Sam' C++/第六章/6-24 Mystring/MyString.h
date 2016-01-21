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
	MyString(char const one[]);						//�����Ĺ��캯����
	MyString(std::string const &other);			//����Ϊstring�Ĺ��캯������Ȼ��֪���е����ġ���string˭������MyString�أ�
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
	str[len] = '\0';//���������
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
	return i;						//��ʱone[i]=='\0' ���±���Ե���''\0
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
	else std::cout << "�±�Խ�磡" << std::endl;		//һ���쳣����
	return str[len+1];
}
