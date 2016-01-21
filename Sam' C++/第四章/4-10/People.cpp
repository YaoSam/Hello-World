#pragma once
#include "People.h"
#include <iostream>
using namespace std;
Date::Date()//默认构造函数
{
	year = month = day = 1;
}
Date::Date(int date)//输入一个八位数字当作日期。
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
	printf("%d年%d月%d日", year, month, day);
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
	cout << "一个人：\n编号：" << num << "\n性别：" << Gender[sex] << endl;
	birthday.ShowDate();
	cout << "身份证号：" << endl;
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