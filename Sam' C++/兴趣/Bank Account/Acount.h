#pragma once
#include <iostream>
#include<string>
#include "C:\Users\Sam\OneDrive\C++\Source\Sam' C++\Sam' C++\����\��Ȥ\����\DATE.h"
#define RE(n)		for(int I=1;I<=n;I++)
using namespace std;
const double RATE = 0.005;
const int SetDay = 30;//Ĭ�Ͻ������ڡ�
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
	if (one < lastdate)						cout << "������ڳ�������ʧ��" << endl;
	else if (amount + money<0)		cout << "���㣬����ʧ��" << endl;
	else if (Passed_Day > SetDay)																				//�Ѿ����˽����ա����м����Ϣ����
	{
		save(0, Last_Settle_Day + SetDay);																//��һ�������ա�
		Passed_Day -= SetDay;
		RE(Passed_Day / SetDay)		amount *= (1.0 + RATE);													//�м���޴��Ľ�����
		Last_Settle_Day += Passed_Day - Passed_Day%SetDay;
		lastdate = Last_Settle_Day;
		save(money, one);																								//����ٴ��롣
	}
	else																														//��û�й�������
	{
		Accmulation += amount*(one - lastdate);														//����Ȩ�ء�
		lastdate = one;
		amount += money;
		//if (money != 0)					//�����ʾ��
		//{
		//	one.PrintDate();
		//	cout << "���룺" << money << "Ԫ\t";
		//	cout << "���Ϊ��" << amount << endl;
		//}
		if (Passed_Day == SetDay)	//��Ϣ��ʾ																//ǡ�ý�����
		{
			Last_Settle_Day = one;
			amount += Accmulation*RATE / SetDay;
			//cout << "������Ϣ: " << Accmulation*RATE / SetDay << endl;
			//cout << "���Ϊ��" << amount << "Ԫ" << endl;
			Accmulation = 0;
		}
	}
}

void Acount::show(int date)
{
	save(0, Date(date));
	if (Date(date) < lastdate)return;
	Date(date).PrintDate();
	cout << "������" << name << endl;
	cout << " ID: " << ID << endl;
	cout<< " ���Ϊ��" << amount << endl;
}