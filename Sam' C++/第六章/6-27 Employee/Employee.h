#include <iostream>
#include <string>
using namespace std;

//��������ַ�����У��ʱࡣ
//setName(cout), display
class Employee
{
	int postcode;
	string name, city, address;
public:
	Employee(string NAME, string CITY, string ADDRESS, int code):
		name(NAME),
		city(CITY),
		address(ADDRESS),
		postcode(code)
	{}
	void display()
	{
		cout << "������" << name << endl;
		cout << "���У�" << city << endl;
		cout << "��ַ��" << address << endl;
		cout << "�ʱࣺ" << postcode<< endl;
	}
	void setname(string const &newname)
	{
		name = newname;
	}
};