#pragma once
#define Re(i,n) for(int i=1;i<=n;i++)
char WEEK[7][10] = {"天","一","二","三","四","五","六"};

#include "DATE.h"
#include <iostream>
using namespace std;
Date::Date(int date, int Week)://后门接口。
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
		cout << "日期不正确！" << endl;
		system("pause");
		exit(0);
	}
}
Date::Date(int Year, int Month, int Day) :year(Year), month(Month), day(Day)
{
	week = -1;
	if (!IsDateRight())
	{
		cout << "日期不正确！" << endl;
		system("pause");
		exit(0);
	}
}

inline int Date::GetLeapYear()const//判断是否为闰年
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))return 1;
	else return 0;
}

inline int Date::GetMonth()const//返回当月最大天数
{
	//另一种写法 IsLeapYear() ? DayOfMonth[0][month] : DayOfMonth[1][month];
	return DayOfMonth[!GetLeapYear()][month];
}

inline int Date::IsDateRight()const//判断日期是否正确
{
	if (month == 0 || day == 0)return 0;
	if (month > 12 || day > GetMonth()) return 0;//天数超过当月天数。
	return 1;
}

inline int Date::GetNum()const//用于比较大小或者是否相等。其实可以在输入的时候直接比较的。但为了程序的完整。就打成函数了。
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
		if (week < 6)				week++; //星期的
		else week = 0;
	}
	if (day < GetMonth())  day++; //天数的
	else
	{
		day = 1;
		if (month < 12)		month++; //月数的
		else
		{
			month = 1;
			year++;//年份的
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
		day = GetLeapYear() ? DayOfMonth[0][month - 1] : DayOfMonth[1][month - 1];//是上一个月;
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
	Re(i, num)temp++;				//虽然我知道这样做效率比较低。
	return temp;
}
Date Date::operator-(int num)const
{
	Date temp = *this;
	Re(i, num)temp--;//虽然我知道这样做效率比较低。
	return temp;
}

void Date::PrintDate()
{
	if(week<0)GetWeek();
	printf("%d年%d月%d日 星期%s\n", year, month, day,WEEK[week]);
}

int Date::DayofYear()const//计算每一天是该年的第几天，也就是原题。
{
	int sum = 0;
	for (int i = 1; i < month; i++) //先算月份的
		sum += DayOfMonth[!GetLeapYear()][i];				//注意有个！因为反了-_-'。。。
	return sum + day;//再加上日期
}

int Date::Count(Date Today) //用Plus 来算。一步一步来。代码非常的直观... ...不过效率会很低
{
	int sum = 0;
	for (; *this > Today; Today++, sum++);
	for (; *this < Today	; Today-- , sum++);
	return sum;
}
int Date::Count2(Date Past)//直接求日期差,算法比Count复杂一点，但是效率高很多。
{
	if (Past>*this)	return Past.Count2(Date(GetNum()));//更正日期顺序
	int sum = 0;
//	Past.PrintDate(); PrintDate();
	//计算日期其实分三部，年月日。月、日已经在DayofYear中解决。
	if (year > Past.year)
	{
		sum += (Past.GetLeapYear() ? 366 : 365) - Past.DayofYear();													//第一年
		for (Past.year++; Past.year < year; Past.year++)//因为第一年已经算上了。所以要++		
						sum += (Past.GetLeapYear() ? 366 : 365);			
				//中间的每一年的天数。	
		sum += DayofYear();																											//最后一年剩下的天数。
	}
	else sum = DayofYear() - Past.DayofYear();								//同一年直接返回两个日期差。
	return sum;
}
int Date::operator -(Date other)  //直接求日期差,算法比Count复杂一点，但是效率高很多。
{
	if (other>*this)	return -(other-*this);//更正日期顺序 ,并且会返回负值。
	int sum = 0;
	//	other.PrintDate(); PrintDate();
	//计算日期其实分三部，年月日。月、日已经在DayofYear中解决。
	if (year > other.year)
	{
		sum += (other.GetLeapYear() ? 366 : 365) - other.DayofYear();													//第一年
		for (other.year++; other.year < year; other.year++)//因为第一年已经算上了。所以要++		
			sum += (other.GetLeapYear() ? 366 : 365);
		//中间的每一年的天数。	
		sum += DayofYear();																											//最后一年剩下的天数。
	}
	else sum = DayofYear() - other.DayofYear();								//同一年直接返回两个日期差。
	return sum;
}
int Date::GetWeek1()//确定今天是星期几。类似过程完全可以用Count来实现，因为星期的改变完全集成在了Plus()和Subtract()中
{
	Date STD(20141129, 6);
	for (; *this> STD; STD++);
	for (;*this < STD; STD--);
	week = STD.week;
	return week;
}
int Date::GetWeek()//依赖于 -的重载（count2）.
{
	Date STD(20141129, 6);
	if (*this>STD)		week = (STD.week + (*this-STD)) % 7;
	else		week = 6 + (STD.week -(*this-STD) + 1) % 7;
	return week;
}

void Date::CalenderM()//打印某一个月的日历。
{
	Date TheFirst (year, month,1);	//从该月的第一天算起
	TheFirst.GetWeek();
	//接下来就是调节输出格式的问题了。
	printf("\n%d年%d月:\n星期天\t\t一\t\t二\t\t三\t\t四\t\t五\t\t六 \n  ", year, month);
	for (int i = 0; i < TheFirst.week; i++)	printf("\t\t");
	for (; TheFirst.day< GetMonth(); TheFirst++)
	{
		printf("\t\t%d", TheFirst.day);
		if (TheFirst.week == 6)printf("\n  ");
	}
	printf("\n");
}
void Date::CalenderY()//打印一年的日历
{
	for (Date date1(year, 1, 15) ; date1.month <= 12; date1.month++)
		date1.CalenderM();

}

