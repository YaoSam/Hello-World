#pragma once
#define Re(i,n) for(int i=1;i<=n;i++)
char WEEK[7][10] = {"��","һ","��","��","��","��","��"};

#include "DATE.h"
#include <iostream>
using namespace std;
Date::Date(int date, int Week)://���Žӿڡ�
year (date / 10000),
month( (date / 100) % 100),
day (date % 100),
week ( Week)
{}
Date::Date(int date) :year(date / 10000), month((date / 100) % 100), day(date%100)
{ 
	week = -1;
	if (!IsDateRight())
	{
		cout << "���ڲ���ȷ��" << endl;
		system("pause");
		exit(0);
	}
}
Date::Date(int Year, int Month, int Day) :year(Year), month(Month), day(Day)
{
	week = -1;
	if (!IsDateRight())
	{
		cout << "���ڲ���ȷ��" << endl;
		system("pause");
		exit(0);
	}
}

inline int Date::GetLeapYear()const//�ж��Ƿ�Ϊ����
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))return 1;
	else return 0;
}

inline int Date::GetMonth()const//���ص����������
{
	//��һ��д�� IsLeapYear() ? DayOfMonth[0][month] : DayOfMonth[1][month];
	return DayOfMonth[!GetLeapYear()][month];
}

inline int Date::IsDateRight()const//�ж������Ƿ���ȷ
{
	if (month == 0 || day == 0)return 0;
	if (month > 12 || day > GetMonth()) return 0;//������������������
	return 1;
}

inline int Date::GetNum()const//���ڱȽϴ�С�����Ƿ���ȡ���ʵ�����������ʱ��ֱ�ӱȽϵġ���Ϊ�˳�����������ʹ�ɺ����ˡ�
{
	return  year * 10000 + month * 100 + day;
}

bool Date::operator >(Date const &other)const
{
	if (this->year > other.year)					 	return true;
	else if (this->year < other.year)				return false;
	else if (this->month>other.month)			return true;
	else if (this->month < other.month)		return false;
	else if (this->day>other.day)					return true;
	else if (this->day < other.day)					return false;
	return false;
}
bool Date::operator <=(Date const &other)const
{
	if (*this > other)return false;
	else return true;
}
bool Date::operator==(Date const &other)const
{
	if (this->year == other.year&&this->month == other.month&&this->day == other.day)return true;
	else return false;
}
bool Date::operator !=(Date const &other)const
{
	if (*this == other)return false;
	else return false;
}
bool Date::operator>=(Date const &other)const
{
	if (*this > other || *this == other)return true;
	else return false;
}
bool Date::operator <(Date const &other)const
{
	if (*this >= other)return false;
	else return true;
}


Date &Date::operator++()
{
	if (week>=0)
	{
		if (week < 6)				week++; //���ڵ�
		else week = 0;
	}
	if (day < GetMonth())  day++; //������
	else
	{
		day = 1;
		if (month < 12)		month++; //������
		else
		{
			month = 1;
			year++;//��ݵ�
		}
	}
	return *this;
}
Date Date::operator++(int)
{
	Date temp = *this;
	++(*this);
	return temp;
}
Date& Date::operator--()
{
	if (week>=0)
	{
		if (week > 0)week--;
		else week = 6;
	}
	if (day > 1)day--;
	else
	{
		day = GetLeapYear() ? DayOfMonth[0][month - 1] : DayOfMonth[1][month - 1];//����һ����;
		if (month > 1) month--;
		else
		{
			month = 12;
			year--;
		}
	}
	//PrintDate();
	return *this;
}
Date Date::operator--(int)
{
	Date temp = *this;
	--(*this);
	return temp;
}
void Date::operator +=(int num)	{ Re(i, num)	(*this)++; }
void Date::operator-=(int num)	{ Re(i, num)	(*this)--; }
Date Date::operator+(int num)const
{
	Date temp = *this;
	Re(i, num)temp++;				//��Ȼ��֪��������Ч�ʱȽϵ͡�
	return temp;
}
Date Date::operator-(int num)const
{
	Date temp = *this;
	Re(i, num)temp--;//��Ȼ��֪��������Ч�ʱȽϵ͡�
	return temp;
}

void Date::PrintDate()
{
	if(week<0)GetWeek();
	printf("%d��%d��%d�� ����%s\n", year, month, day,WEEK[week]);
}

int Date::DayofYear()const//����ÿһ���Ǹ���ĵڼ��죬Ҳ����ԭ�⡣
{
	int sum = 0;
	for (int i = 1; i < month; i++) //�����·ݵ�
		sum += DayOfMonth[!GetLeapYear()][i];				//ע���и�����Ϊ����-_-'������
	return sum + day;//�ټ�������
}

int Date::Count(Date Today) //��Plus ���㡣һ��һ����������ǳ���ֱ��... ...����Ч�ʻ�ܵ�
{
	int sum = 0;
	for (; *this > Today; Today++, sum++);
	for (; *this < Today	; Today-- , sum++);
	return sum;
}
int Date::Count2(Date Past)//ֱ�������ڲ�,�㷨��Count����һ�㣬����Ч�ʸߺܶࡣ
{
	if (Past>*this)	return Past.Count2(Date(GetNum()));//��������˳��
	int sum = 0;
//	Past.PrintDate(); PrintDate();
	//����������ʵ�������������ա��¡����Ѿ���DayofYear�н����
	if (year > Past.year)
	{
		sum += (Past.GetLeapYear() ? 366 : 365) - Past.DayofYear();													//��һ��
		for (Past.year++; Past.year < year; Past.year++)//��Ϊ��һ���Ѿ������ˡ�����Ҫ++		
						sum += (Past.GetLeapYear() ? 366 : 365);			
				//�м��ÿһ���������	
		sum += DayofYear();																											//���һ��ʣ�µ�������
	}
	else sum = DayofYear() - Past.DayofYear();								//ͬһ��ֱ�ӷ����������ڲ
	return sum;
}
int Date::operator -(Date other)  //ֱ�������ڲ�,�㷨��Count����һ�㣬����Ч�ʸߺܶࡣ
{
	if (other>*this)	return -(other-*this);//��������˳�� ,���һ᷵�ظ�ֵ��
	int sum = 0;
	//	other.PrintDate(); PrintDate();
	//����������ʵ�������������ա��¡����Ѿ���DayofYear�н����
	if (year > other.year)
	{
		sum += (other.GetLeapYear() ? 366 : 365) - other.DayofYear();													//��һ��
		for (other.year++; other.year < year; other.year++)//��Ϊ��һ���Ѿ������ˡ�����Ҫ++		
			sum += (other.GetLeapYear() ? 366 : 365);
		//�м��ÿһ���������	
		sum += DayofYear();																											//���һ��ʣ�µ�������
	}
	else sum = DayofYear() - other.DayofYear();								//ͬһ��ֱ�ӷ����������ڲ
	return sum;
}
int Date::GetWeek1()//ȷ�����������ڼ������ƹ�����ȫ������Count��ʵ�֣���Ϊ���ڵĸı���ȫ��������Plus()��Subtract()��
{
	Date STD(20141129, 6);
	for (; *this> STD; STD++);
	for (;*this < STD; STD--);
	week = STD.week;
	return week;
}
int Date::GetWeek()//������ -�����أ�count2��.
{
	Date STD(20141129, 6);
	if (*this>STD)		week = (STD.week + (*this-STD)) % 7;
	else		week = 6 + (STD.week -(*this-STD) + 1) % 7;
	return week;
}

void Date::CalenderM()//��ӡĳһ���µ�������
{
	Date TheFirst (year, month,1);	//�Ӹ��µĵ�һ������
	TheFirst.GetWeek();
	//���������ǵ��������ʽ�������ˡ�
	printf("\n%d��%d��:\n������\t\tһ\t\t��\t\t��\t\t��\t\t��\t\t�� \n  ", year, month);
	for (int i = 0; i < TheFirst.week; i++)	printf("\t\t");
	for (; TheFirst.day< GetMonth(); TheFirst++)
	{
		printf("\t\t%d", TheFirst.day);
		if (TheFirst.week == 6)printf("\n  ");
	}
	printf("\n");
}
void Date::CalenderY()//��ӡһ�������
{
	for (Date date1(year, 1, 15) ; date1.month <= 12; date1.month++)
		date1.CalenderM();

}

