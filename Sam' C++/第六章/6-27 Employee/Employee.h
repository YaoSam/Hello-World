#include <iostream>
#include <string>
using namespace std;

//姓名，地址，城市，邮编。
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
		cout << "姓名：" << name << endl;
		cout << "城市：" << city << endl;
		cout << "地址：" << address << endl;
		cout << "邮编：" << postcode<< endl;
	}
	void setname(string const &newname)
	{
		name = newname;
	}
};