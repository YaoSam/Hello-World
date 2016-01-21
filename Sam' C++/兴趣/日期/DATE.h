#pragma once
#include <iostream>
#include <Windows.h>

#define Re(i,n) for(int i=1;i<=n;i++)
//�����������
const char WEEK[7][10] = { "��", "һ", "��", "��", "��", "��", "��" };
//ÿ�µ��������
const int LengthOfMonth[2][20] = { { 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, { 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };//����ȷ��ÿ���µ�����,0��Ϊ31��Ϊ�˺�12�¶�Ӧ
//ÿ�����һ�쵽01.01���������������꣩
const int MonthOfYear[30] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };																//ÿ������ڱ������ڵ��ۼ�����
class Date
{
private:
	int year, month, day, week;
	bool IsLeapYear;							//����Ƿ�Ϊ����
	inline int GetMonth()			const;	//���ص����������
	inline void CheckLeap();				//�����Ƿ�Ϊ���ꡣ
	void Checkday()			const;		//��������Ƿ���ȷ��һ���ڹ��캯�����á�
	int DayToFirst()				const;		//����ڹ�ԪԪ������ڡ�
	int GetWeek();								//ȷ�����������ڼ���
	int GetWeek1();									
public:
	Date(int date);
	Date(int Year, int Month, int Day);
	bool operator >	(Date const &other)const;  //�Ƚ����ڵĴ�С��
	bool operator<=	(Date const &other)const{ return !(*this > other); }
	bool operator==	(Date const &other)const;
	bool operator!=	(Date const &other)const{ return !(*this == other); }
	bool operator>=	(Date const &other)const{ return (*this > other || *this == other); }
	bool operator <	(Date const &other)const{ return !(*this > other || *this == other); }
	Date &operator++(int);						//���������һ
	Date operator++();						//�����������Ӱ��Ч�ʾ������á�
	Date &operator--(int);						//������--��������
	Date operator--();
	Date operator+	(int num)const;		//����һ����������
	Date operator-	(int num)const;		 	
	Date &operator+=(int num)	{ *this = *this + num; return *this; }				//��������,����+
	Date &operator-=	(int num)	{ *this = *this - num; return *this; }
	inline int DayofYear()	const;			//����ÿһ���Ǹ���ĵڼ��죬Ҳ����ԭ�⡣
	int Count(Date Today);					//��Plus ���㡣һ��һ����������ǳ���ֱ��... ...����Ч�ʻ�ܵ�
	int operator -(Date const &other)const ;	//��������֮��Ĳ���ֵ��
	friend std::ostream &operator<<(std::ostream &out, Date &This);
	void CalenderM()const;					//��ӡĳһ���µ�������
	void CalenderY();							//��ӡһ�������
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
		printf("%d��%d��%d��----���ڲ���ȷ��", year, month, day);
		system("pause");
		exit(1);
	}
}
 void Date::CheckLeap()		{ IsLeapYear = year % 400 == 0 || (year % 4 == 0 && year % 100 != 0); }
 int Date::GetMonth()const	{ return LengthOfMonth[!IsLeapYear][month]; }

inline int Date::DayofYear()const//����ÿһ���Ǹ���ĵڼ��죬Ҳ����ԭ�⡣
{
	return MonthOfYear[month] + day + (IsLeapYear&&month > 2);	//�ټ���������һ�졣
}
int Date::DayToFirst()const		//�㷨�ο�C++����
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
		if (week < 6)				week++; //���ڵ�
		else week = 0;
	}
	if (day < LengthOfMonth[!IsLeapYear][month])  day++; //������
	else
	{
		day = 1;
		if (month < 12)		month++; //������
		else
		{
			month = 1;
			year++;//��ݵ�
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
		day =LengthOfMonth[!IsLeapYear][month-1];	//����һ����;
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

int Date::Count(Date Today) //��Plus ���㡣һ��һ������Ŀǰֻ�����������ˡ�
{
	int sum = 0;
	for (; *this > Today; ++Today, sum++);
	for (; *this < Today; --Today, sum++);
	return sum;
}
int Date::GetWeek1() //������--��++
{
	static Date STD; STD.week = 6;
	for (; *this> STD; ++STD);
	for (; *this < STD; --STD);
	week = STD.week;
	return week;
}

int Date::GetWeek()//������ -
{
	Date STD; 
	STD.week = 6;
	week = (STD.week + (*this - STD) % 7 + 7) % 7;
	return week;
}
std::ostream &operator<<(std::ostream &out, Date &This)
{
	if (This.week < 0)This.GetWeek();
	out << This.year << "��" << This.month << "��" << This.day << "��"<<" ����"<<WEEK[This.week];
	return out;
}

void Date::CalenderM()const
{
	Date TheFirst(year, month, 1);				//ÿ�µ�һ��
	TheFirst.GetWeek();
	//���������ǵ��������ʽ�������ˡ�
	printf("\n%d��%d��:\n������\t\tһ\t\t��\t\t��\t\t��\t\t��\t\t�� \n  ", year, month);
	for (int i = 0; i < TheFirst.week; i++)	printf("\t\t");
	for (; TheFirst.day< GetMonth(); ++TheFirst)
	{
		printf("\t\t%d", TheFirst.day);
		if (TheFirst.week == 6)printf("\n  ");
		Sleep(100);
	}
	printf("\t\t%d\n", TheFirst.day);
}
void Date::CalenderY()//��ӡһ�������
{
	for (Date date1(year, 1, 15); date1.month <= 12; date1.month++)	date1.CalenderM();
}

