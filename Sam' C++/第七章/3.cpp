
/*
*
*������	 ��������������           ����+ +
*����  ���������������ߩ��������������ߩ� + +
*����  ��������������������       �� ��
*����  ������������������������  �� ++ + + +
*����  ����		  ��  ��������������  ��+
*����  ������������������������ �� +
*����  ����������������   �ߡ���  ��
*����  �������������������������� + +
*����  ���������������������� ������
*��������������������������������������������������
*���������������������������� + + + +
*������������������������������������Code is far away from bug with the animal protecting��������������
*���������������������������� + �����������ޱ���,������bug����
*����������������������������
*��������������������������������+������������������
*���������������������� �������������� + +
*�������������������� ���������������ǩ�
*�������������������� ������������������
*�����������������������������ש����� + + + +
*�����������������������ϩϡ����ϩ�
*�����������������������ߩ������ߩ�+ + + +
*/
#include <iostream>
#include <string>
using namespace std;

//#define DEBUG //����ȷ���Ƿ��ı������
#define Re(i,n)		for(int i=0;i<n;i++)

/*����˵��*/
//3. �ֱ���Teacher(��ʦ�����Cadre(�ɲ��������ö��ؼ̳з�ʽ��������������������Teacher_Cadre(��ʦ��ɲ�����Ҫ��
//	��1�����������ж��������������䡢�Ա𡢵�ַ���绰�����ݳ�Ա��
//	��2����Teacher���л��������ݳ�Աtitle(ְ�ƣ�����Cadre���л��������ݳ�Աpost(ְ�񣩣���Teacher_Cadre���л��������ݳ�Աwages(���ʣ���
//	��3�������������е����������䡢�Ա𡢵�ַ���绰��������ͬ�����֣���������Щ���ݳ�Աʱ��ָ��������
//	��4����������������Ա�����������ⶨ���Ա������
//	��5����������Teacher_Cadre�ĳ�Ա����show�е���Teacher���е�display������������������䡢�Ա𡢵�ַ���绰��Ȼ������cout������ְ���빤�ʡ�
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
	cout << "����" << Name << endl
		<< "����" << Age << endl
		<< "�Ա�" << (Gender ? "��" : "Ů") << endl
		<< "��ַ��" << Address << endl
		<< "�绰����" << PhoneNumber << endl;
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
	cout << "������" << Name << ' '
		<< "���䣺" << Age << ' '
		<< "�Ա�" << (Gender ? "��" : "Ů") << ' ' << endl
		<< "��ַ��" << Address << ' '
		<< "�绰����" << PhoneNumber << endl;
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
	cout << "ְ��" << Post << endl << "���ʣ�" << Wages<<endl;
}



int main()//���Ǵ������ú���~
{
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	Teacher one("Ҧ쿲�", 20, 1, "��ɽ��ѧ173-607", "10086", "ѧ��");
	one.display();
	Teacher_Cadre two("Ҧ쿲�", 20, 1, "��ɽ��ѧ173-607", "10086", "ѧ��", "��һ����", 125);
	two.show();

#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}