#pragma once
#include <iostream>
#include <Windows.h>

#define Re(i,n) for(int i=1;i<=n;i++)
//用来输出星期
const char WEEK[7][10] = { "天", "一", "二", "三", "四", "五", "六" };
//每月的最大日数
const int LengthOfMonth[2][20] = { { 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, { 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };//用来确定每个月的天数,0设为31是为了和12月对应
//每月最后一天到01.01的天数。（非闰年）
const int MonthOfYear[30] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };																//每月相对于本年日期的累计数。
class Date
{
private:
	int year, month, day, week;
	bool IsLeapYear;							//标记是否为闰年
	inline int GetMonth()			const;	//返回当月最大天数
	inline void CheckLeap();				//更新是否为闰年。
	void Checkday()			const;		//检查日期是否正确。一般在构造函数处用。
	int DayToFirst()				const;		//相对于公元元年的日期。
	int GetWeek();								//确定今天是星期几。
	int GetWeek1();									
public:
	Date(int date);
	Date(int Year, int Month, int Day);
	bool operator >	(Date const &other)const;  //比较日期的大小。
	bool operator<=	(Date const &other)const{ return !(*this > other); }
	bool operator==	(Date const &other)const;
	bool operator!=	(Date const &other)const{ return !(*this == other); }
	bool operator>=	(Date const &other)const{ return (*this > other || *this == other); }
	bool operator <	(Date const &other)const{ return !(*this > other || *this == other); }
	Date &operator++(int);						//日期自身加一
	Date operator++();						//后置运算符，影响效率尽量别用。
	Date &operator--(int);						//基本和--反过来。
	Date operator--();
	Date operator+	(int num)const;		//加上一定的天数。
	Date operator-	(int num)const;		 	
	Date &operator+=(int num)	{ *this = *this + num; return *this; }				//自增运算,运用+
	Date &operator-=	(int num)	{ *this = *this - num; return *this; }
	inline int DayofYear()	const;			//计算每一天是该年的第几天，也就是原题。
	int Count(Date Today);					//用Plus 来算。一步一步来。代码非常的直观... ...不过效率会很低
	int operator -(Date const &other)const ;	//返回日期之间的差，相对值。
	friend std::ostream &operator<<(std::ostream &out, Date &This);
	void CalenderM()const;					//打印某一个月的日历。
	void CalenderY();							//打印一年的日历
};

Date::Date(int date = 20141129) : month((date / 100) % 100), day(date % 100), week(-1)
{
	year = date / 10000;
	CheckLeap();
	Checkday();
}
Date::Date(int Year, int Month, int Day) :
year(Year),
month(Month), 
day(Day), 
week(-1),
IsLeapYear(Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0))
{
	Checkday();
}

void Date::Checkday()const
{
	if ((month <= 0 || day <= 0) || (month > 12 || day > GetMonth()))
	{
		printf("%d年%d月%d日----日期不正确！", year, month, day);
		system("pause");
		exit(1);
	}
}
 void Date::CheckLeap()		{ IsLeapYear = year % 400 == 0 || (year % 4 == 0 && year % 100 != 0); }
 int Date::GetMonth()const	{ return LengthOfMonth[!IsLeapYear][month]; }

inline int Date::DayofYear()const//计算每一天是该年的第几天，也就是原题。
{
	return MonthOfYear[month] + day + (IsLeapYear&&month > 2);	//再加上闰年那一天。
}
int Date::DayToFirst()const		//算法参考C++的书
{
	int years = year - 1;
	return years * 365 + years / 4 - years / 100 + years / 400+MonthOfYear[month-1]+day +(IsLeapYear&&month>2);
}
int Date::operator -(Date const &other) const	{ return DayToFirst() - other.DayToFirst(); }

bool Date::operator >(Date const &other)const
{
	//if			(year > other.year)				return true;
	//else if	(year < other.year)					return false;
	//else if	(month>other.month)			return true;
	//else if	(month < other.month)			return false;
	//else if	(day>other.day)						return true;
	//return false;
	return (10000 * year + month * 100 + day > 10000 * other.year + other.month * 100 + other.day);
}
bool Date::operator==(Date const &other)const
{
	return (year == other.year&&month == other.month&&day == other.day); 
}


Date &Date::operator++(int )
{
	if (week >= 0)
	{
		if (week < 6)				week++; //星期的
		else week = 0;
	}
	if (day < LengthOfMonth[!IsLeapYear][month])  day++; //天数的
	else
	{
		day = 1;
		if (month < 12)		month++; //月数的
		else
		{
			month = 1;
			year++;//年份的
			CheckLeap();
		}
	}
	return *this;
}
Date Date::operator++() 
{
	Date temp = *this;
	(*this)++;
	return temp;
}
Date& Date::operator--(int)
{
	if (week >= 0)
	{
		if (week > 0)week--;
		else week = 6;
	}
	if (day > 1)day--;
	else
	{
		day =LengthOfMonth[!IsLeapYear][month-1];	//是上一个月;
		if (month > 1) month--;
		else
		{
			month = 12;
			year--;
			CheckLeap();
		}
	}
	return *this;
}
Date Date::operator--()
{
	Date temp = *this;
	(*this)--;
	return temp;
}

Date Date::operator+(int num)const
{
	if (num < 0)	return *this - num;
	Date temp = *this;
	if (num >= 366)
	{
		temp = Date(year + num / 366, 1, 1);
		num -= temp - *this;
	}
	//std::cout << num << std::endl;
	Re(i, num)++temp;
	return temp;
}
Date Date::operator-(int num)const
{
	if (num < 0)		return *this + (-num);
	Date temp = *this;
	if (num >= 365)
	{
		temp = Date(year - num / 366, 12, 31);
		num -= (*this - temp); 
	}
	//std::cout << num << std::endl;
	Re(i, num)	temp--;
	return temp;
}

int Date::Count(Date Today) //用Plus 来算。一步一步来。目前只是用来验算了。
{
	int sum = 0;
	for (; *this > Today; ++Today, sum++);
	for (; *this < Today; --Today, sum++);
	return sum;
}
int Date::GetWeek1() //依赖于--，++
{
	static Date STD; STD.week = 6;
	for (; *this> STD; ++STD);
	for (; *this < STD; --STD);
	week = STD.week;
	return week;
}

int Date::GetWeek()//依赖于 -
{
	Date STD; 
	STD.week = 6;
	week = (STD.week + (*this - STD) % 7 + 7) % 7;
	return week;
}
std::ostream &operator<<(std::ostream &out, Date &This)
{
	if (This.week < 0)This.GetWeek();
	out << This.year << "年" << This.month << "月" << This.day << "日"<<" 星期"<<WEEK[This.week];
	return out;
}

void Date::CalenderM()const
{
	Date TheFirst(year, month, 1);				//每月第一天
	TheFirst.GetWeek();
	//接下来就是调节输出格式的问题了。
	printf("\n%d年%d月:\n星期天\t\t一\t\t二\t\t三\t\t四\t\t五\t\t六 \n  ", year, month);
	for (int i = 0; i < TheFirst.week; i++)	printf("\t\t");
	for (; TheFirst.day< GetMonth(); ++TheFirst)
	{
		printf("\t\t%d", TheFirst.day);
		if (TheFirst.week == 6)printf("\n  ");
		Sleep(100);
	}
	printf("\t\t%d\n", TheFirst.day);
}
void Date::CalenderY()//打印一年的日历
{
	for (Date date1(year, 1, 15); date1.month <= 12; date1.month++)	date1.CalenderM();
}

