#include "Acount.h"
using namespace std;
//#define Re(i,n) for(int i=1;i<=n;i++)
#define RE(n)	for(int I=1;I<=n;I++)
Acount::Acount(int id, string Name, int today, float money):
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
	if (one < lastdate)	cout << "存款日期出错" << endl;
	else if ( Passed_Day> SetDay)																				//已经过了结算日。将中间的利息补上
	{
		save(0, Last_Settle_Day+SetDay);																//第一个结算日。
		Passed_Day -= SetDay;
		RE (Passed_Day / SetDay)		amount *= (1.0 + RATE);													//中间的无存款的结算日
		Last_Settle_Day += Passed_Day-Passed_Day%SetDay;
		lastdate = Last_Settle_Day;
		save(money, one);																								//最后再存入。
	}
	else																														//还没有过结算日
	{
		Accmulation += amount*(one - lastdate);														//计算权重。
		lastdate = one;
		amount += money;
		if (money!=0)
		{
			one.PrintDate();
			cout << "存入：" << money << "元\t";	
			cout << "余额为：" << amount << endl;
		}	
		if (Passed_Day == SetDay)																				//恰好结算日
		{
			Last_Settle_Day = one;
			amount += Accmulation*RATE / SetDay;
			cout << "结算利息: " << Accmulation*RATE / SetDay << endl;
			cout << "余额为：" << amount << "元" << endl;
			Accmulation = 0;
		}
	}
}

void Acount::show(int date)
{
	save(0, Date(date));
	Date(date).PrintDate();
	cout << "户主：" << name << " ID: " << ID << " 余额为：" << amount << endl;
}