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
	if (one < lastdate)	cout << "������ڳ���" << endl;
	else if ( Passed_Day> SetDay)																				//�Ѿ����˽����ա����м����Ϣ����
	{
		save(0, Last_Settle_Day+SetDay);																//��һ�������ա�
		Passed_Day -= SetDay;
		RE (Passed_Day / SetDay)		amount *= (1.0 + RATE);													//�м���޴��Ľ�����
		Last_Settle_Day += Passed_Day-Passed_Day%SetDay;
		lastdate = Last_Settle_Day;
		save(money, one);																								//����ٴ��롣
	}
	else																														//��û�й�������
	{
		Accmulation += amount*(one - lastdate);														//����Ȩ�ء�
		lastdate = one;
		amount += money;
		if (money!=0)
		{
			one.PrintDate();
			cout << "���룺" << money << "Ԫ\t";	
			cout << "���Ϊ��" << amount << endl;
		}	
		if (Passed_Day == SetDay)																				//ǡ�ý�����
		{
			Last_Settle_Day = one;
			amount += Accmulation*RATE / SetDay;
			cout << "������Ϣ: " << Accmulation*RATE / SetDay << endl;
			cout << "���Ϊ��" << amount << "Ԫ" << endl;
			Accmulation = 0;
		}
	}
}

void Acount::show(int date)
{
	save(0, Date(date));
	Date(date).PrintDate();
	cout << "������" << name << " ID: " << ID << " ���Ϊ��" << amount << endl;
}