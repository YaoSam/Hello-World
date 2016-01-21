#pragma once
#include <iostream>
#include<string>
#include "C:\Users\Sam\OneDrive\C++\Source\Sam' C++\Sam' C++\竞赛\兴趣\日期\DATE.h"
#define RE(n)		for(int I=1;I<=n;I++)
using namespace std;
const double RATE = 0.005;
const int SetDay = 30;//默认结算周期。
class Acount
{
private:
	int ID;
	string name;
	Date lastdate,Last_Settle_Day;
	float amount, Accmulation;
public:
	Acount(int id,string Name, int today, float money);
	void save(float money, int date){ save(money, Date(date)); }
	void save(float money, Date one);
	void show(int date);
};


Acount::Acount(int id, string Name, int today, float money) :
ID(id),
name(Name),
Last_Settle_Day(today),
lastdate(today),
amount(money),
Accmulation(0)
{}

void Acount::save(float money, Date one)
{
	int Passed_Day = one - Last_Settle_Day;
	if (one < lastdate)						cout << "存款日期出错，操作失败" << endl;
	else if (amount + money<0)		cout << "余额不足，操作失败" << endl;
	else if (Passed_Day > SetDay)																				//已经过了结算日。将中间的利息补上
	{
		save(0, Last_Settle_Day + SetDay);																//第一个结算日。
		Passed_Day -= SetDay;
		RE(Passed_Day / SetDay)		amount *= (1.0 + RATE);													//中间的无存款的结算日
		Last_Settle_Day += Passed_Day - Passed_Day%SetDay;
		lastdate = Last_Settle_Day;
		save(money, one);																								//最后再存入。
	}
	else																														//还没有过结算日
	{
		Accmulation += amount*(one - lastdate);														//计算权重。
		lastdate = one;
		amount += money;
		//if (money != 0)					//存款显示。
		//{
		//	one.PrintDate();
		//	cout << "存入：" << money << "元\t";
		//	cout << "余额为：" << amount << endl;
		//}
		if (Passed_Day == SetDay)	//利息显示																//恰好结算日
		{
			Last_Settle_Day = one;
			amount += Accmulation*RATE / SetDay;
			//cout << "结算利息: " << Accmulation*RATE / SetDay << endl;
			//cout << "余额为：" << amount << "元" << endl;
			Accmulation = 0;
		}
	}
}

void Acount::show(int date)
{
	save(0, Date(date));
	if (Date(date) < lastdate)return;
	Date(date).PrintDate();
	cout << "户主：" << name << endl;
	cout << " ID: " << ID << endl;
	cout<< " 余额为：" << amount << endl;
}