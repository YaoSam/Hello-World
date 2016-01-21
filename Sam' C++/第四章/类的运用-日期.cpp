#include <iostream>
using namespace std;
#define DEBUG
#define scanf scanf_s
/*
STD :Standard Day
*/

//用来确定每个月的天数,0设为31是为了和12月对应
const int DayOfMonth[2][20] = { { 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, { 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };
class Date
{
private:
	int year, month, day, week;
	int IsLeapYear()//判断是否为闰年
	{
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))return 1;
		else return 0;
	}
	int IsLeapYear(int Y)
	{
		if (Y % 400 == 0 || (Y % 4 == 0 && Y % 100 != 0))return 1;
		else return 0;
	}
	inline	int GetMonth()//返回当月最大天数
	{
		//另一种写法 IsLeapYear() ? DayOfMonth[0][month] : DayOfMonth[1][month];
		return DayOfMonth[!IsLeapYear()][month];
	}
	int IsDateRight()//判断日期是否正确
	{
		if (month == 0 || day == 0)return 0;
		if (month > 12 || day >GetMonth()) return 0;//天数超过当月天数。
		return 1;
	}
	inline	int GetNum()//用于比较大小或者是否相等。其实可以在输入的时候直接比较的。但为了程序的完整。就打成函数了。
	{
		return  year * 10000 + month * 100 + day;
	}
	void Plus()//日期自身加一
	{
		if (week < 6)				week++; //星期的
		else week = 0;

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
	}
	void Subtract()//基本和Plus反过来。
	{
		if (week > 0)week--;
		else week = 6;
		if (day>1)day--;
		else
		{
			day = IsLeapYear() ? DayOfMonth[0][month - 1] : DayOfMonth[1][month - 1];//是上一个月;
			if (month>1) month--;
			else
			{
				month = 12;
				year--;
			}
		}
		//PrintDate();
	}
	int GetWeek2()//依赖于Count2.
	{
		Date STD(20141129); STD.week = 6;
		if (GetNum() > STD.GetNum())  week = (STD.week + Count2(STD) - 1) % 7;
		else week = 6 + (STD.week - Count2(STD) + 1) % 7;
		return week;
	}
	int GetWeek()//确定今天是星期几。类似过程完全可以用Count来实现，因为星期的改变完全集成在了Plus()和Subtract()中
	{
		Date STD(20141129); STD.week = 6;
		for (; GetNum()>STD.GetNum(); STD.Plus());
		for (; GetNum()<STD.GetNum(); STD.Subtract());
		week = STD.week;
#ifdef DEBUG
		cout << week << endl;
#endif
		return week;
	}
public:	
	Date(int date)
	{
		year = date / 10000;
		month = (date / 100) % 100;
		day = date % 100;
		GetWeek2();//GetWeek2里面已经包含了标准日期。统一用STD来计算week
		if (!IsDateRight()) 
		{
			cout << "日期不正确！"<<endl;
			system("pause");
			exit(0);
		}
	}
	Date(int Year, int Month, int Day)
	{
		year = Year;
		month = Month;
		day = Day;
		GetWeek2();
		if (!IsDateRight())
		{
			cout << "日期不正确！" << endl;
			system("pause");
			exit(0);
		}
	}
	void PrintDate()
	{
		cout<<GetNum()<<"星期"<<week<<"\n";
	}
	int DayofYear()//计算每一天是该年的第几天，也就是原题。
	{
		int Sum = 0;
		if (!IsDateRight()) return 0;//例行工作。。。
		for (int i = 1; i < month; i++) //先算月份的
			Sum += DayOfMonth[!IsLeapYear()][i]; //注意有个！因为反了-_-'。。。
		return Sum + day;//再加上日期
	}
	int Count(Date Today) //用Plus 来算。一步一步来。代码非常的直观... ...不过效率会很低
	{
		int Sum = 0;
		for (; GetNum() > Today.GetNum(); Sum++) Today.Plus();
		for (; GetNum() < Today.GetNum(); Sum++) Today.Subtract();
#ifdef DEBUG
		cout<<"相差天数为"<<Sum<<'\n';
#endif
		return Sum;
	}
	int Count2(Date Past)//直接求日期差,算法比Count复杂一点，但是效率高很多。
	{
		if (Past.GetNum() < GetNum())
		{
			Date Today(year, month, day);//用来指代今年。
			return Past.Count2(Today);//更正日期顺序
		}
		int sum = 0;
		//计算日期其实分三部，年月日。月、日已经在DayofYear中解决。
		if (year > Past.year)
		{
			int Y = Past.year;
													sum += (Past.IsLeapYear()?366:365)-Past.DayofYear();//第一年
			for (Y++; Y> year; Y++)		sum += (IsLeapYear(Y) ? 366 : 365);//中间的每一年的天数。
													sum += DayofYear();//最后一年剩下的天数。
		}
		else sum = DayofYear() - Past.DayofYear();//直接返回两个日期差。
		return sum;
	}
	void CalenderM()//打印某一个月的日历。要输入附带有星期的日期。
	{
		Date TheFirst = { year, month, 1 };	//从该月的第一天算起
		Date TheLast = { year, month, GetMonth() };
		//接下来就是调节输出格式的问题了。
		printf("\n%d年%d月:\n星期天\t\t一\t\t二\t\t三\t\t四\t\t五\t\t六 \n  ", year, month);
		for (int i = 0; i <TheFirst.week; i++)	printf("\t\t");
		for (; TheFirst.GetNum() <= TheLast.GetNum(); TheFirst.Plus())
		{
			printf("\t\t%d", TheFirst.day);
			if (TheFirst.week == 6)printf("\n  ");
		}
		printf("\n");
	}
	void CalenderY()//打印一年的日历
	{
		for (Date date1 = { year, 1, 15 }; date1.month <= 12; date1.month++) 
			date1.CalenderM();
	}
};

int main()
{
#ifdef DEBUG
	FILE *empty;
	freopen_s(&empty,"in.txt", "r", stdin);
	freopen_s(&empty,"out.txt", "w", stdout);
#endif
	int d1, d2;
	//printf("请输入今天日期格式为：19950930 20141129");
	while (scanf_s("%d%d", &d1, &d2) == 2)
	{
		Date date1(d1);
		Date date2(d2);
		cout << "日期差为" << date1.Count(date2) <<' '<<date2.Count2(date1)<<endl;
	};
	Date date1 = { 2015 ,01,01}; 
	date1.CalenderM();
	date1.CalenderY();
	return 0;
}

/*Sample Input*/
/*
20140930
19950930 20141112
20080808 20141129
20140101 20141129
20130101 20150202
20130101 20141129
20141010 20141129
19950930 20141129
20141129 20141129
^z

*/
