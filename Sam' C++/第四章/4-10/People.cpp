#pragma once
#include "People.h"
#include <iostream>
using namespace std;
Date::Date()//Ĭ�Ϲ��캯��
{
	year = month = day = 1;
}
Date::Date(int date)//����һ����λ���ֵ������ڡ�
{
	year = date / 10000;
	month = (date / 100) % 100;
	day = date % 100;
}
Date::Date(Date &p)
{
	cout << endl << "copy a day :";
	year = p.year;
	day = p.day;
	month = p.month;
	ShowDate();
}
void Date::ShowDate()
{
	printf("%d��%d��%d��", year, month, day);
}
Date::~Date()
{
	ShowDate();
	cout << ": I died. 8" << endl;
}
People::People(int Num=1, bool Sex=1, char id[]="123456789012345678", int date=20150101) :birthday(date)
{
	num = Num;
	sex = Sex;
	for (int i = 0; i < 18; i++)ID[i] = id[i] - '0';
}
void People::ShowPeople()
{
	cout << "һ���ˣ�\n��ţ�" << num << "\n�Ա�" << Gender[sex] << endl;
	birthday.ShowDate();
	cout << "���֤�ţ�" << endl;
	for (int i = 0; i < 18; i++)cout << ID[i];
	cout << endl << endl;
}
People::People(People &p)
{
	sex = p.sex;
	num = p.num;
	birthday = p.birthday;
	for (int i = 0; i < 18; i++)ID[i] = p.ID[i];
	cout << "copy a people :" << num<<endl;
}
People::~People()
{
	cout << num;
	cout << ": I'm dying! Help!" << endl;
	}