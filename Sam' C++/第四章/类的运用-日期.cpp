#include <iostream>
using namespace std;
#define DEBUG
#define scanf scanf_s
/*
STD :Standard Day
*/

//����ȷ��ÿ���µ�����,0��Ϊ31��Ϊ�˺�12�¶�Ӧ
const int DayOfMonth[2][20] = { { 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, { 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };
class Date
{
private:
	int year, month, day, week;
	int IsLeapYear()//�ж��Ƿ�Ϊ����
	{
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))return 1;
		else return 0;
	}
	int IsLeapYear(int Y)
	{
		if (Y % 400 == 0 || (Y % 4 == 0 && Y % 100 != 0))return 1;
		else return 0;
	}
	inline	int GetMonth()//���ص����������
	{
		//��һ��д�� IsLeapYear() ? DayOfMonth[0][month] : DayOfMonth[1][month];
		return DayOfMonth[!IsLeapYear()][month];
	}
	int IsDateRight()//�ж������Ƿ���ȷ
	{
		if (month == 0 || day == 0)return 0;
		if (month > 12 || day >GetMonth()) return 0;//������������������
		return 1;
	}
	inline	int GetNum()//���ڱȽϴ�С�����Ƿ���ȡ���ʵ�����������ʱ��ֱ�ӱȽϵġ���Ϊ�˳�����������ʹ�ɺ����ˡ�
	{
		return  year * 10000 + month * 100 + day;
	}
	void Plus()//���������һ
	{
		if (week < 6)				week++; //���ڵ�
		else week = 0;

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
	}
	void Subtract()//������Plus��������
	{
		if (week > 0)week--;
		else week = 6;
		if (day>1)day--;
		else
		{
			day = IsLeapYear() ? DayOfMonth[0][month - 1] : DayOfMonth[1][month - 1];//����һ����;
			if (month>1) month--;
			else
			{
				month = 12;
				year--;
			}
		}
		//PrintDate();
	}
	int GetWeek2()//������Count2.
	{
		Date STD(20141129); STD.week = 6;
		if (GetNum() > STD.GetNum())  week = (STD.week + Count2(STD) - 1) % 7;
		else week = 6 + (STD.week - Count2(STD) + 1) % 7;
		return week;
	}
	int GetWeek()//ȷ�����������ڼ������ƹ�����ȫ������Count��ʵ�֣���Ϊ���ڵĸı���ȫ��������Plus()��Subtract()��
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
		GetWeek2();//GetWeek2�����Ѿ������˱�׼���ڡ�ͳһ��STD������week
		if (!IsDateRight()) 
		{
			cout << "���ڲ���ȷ��"<<endl;
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
			cout << "���ڲ���ȷ��" << endl;
			system("pause");
			exit(0);
		}
	}
	void PrintDate()
	{
		cout<<GetNum()<<"����"<<week<<"\n";
	}
	int DayofYear()//����ÿһ���Ǹ���ĵڼ��죬Ҳ����ԭ�⡣
	{
		int Sum = 0;
		if (!IsDateRight()) return 0;//���й���������
		for (int i = 1; i < month; i++) //�����·ݵ�
			Sum += DayOfMonth[!IsLeapYear()][i]; //ע���и�����Ϊ����-_-'������
		return Sum + day;//�ټ�������
	}
	int Count(Date Today) //��Plus ���㡣һ��һ����������ǳ���ֱ��... ...����Ч�ʻ�ܵ�
	{
		int Sum = 0;
		for (; GetNum() > Today.GetNum(); Sum++) Today.Plus();
		for (; GetNum() < Today.GetNum(); Sum++) Today.Subtract();
#ifdef DEBUG
		cout<<"�������Ϊ"<<Sum<<'\n';
#endif
		return Sum;
	}
	int Count2(Date Past)//ֱ�������ڲ�,�㷨��Count����һ�㣬����Ч�ʸߺܶࡣ
	{
		if (Past.GetNum() < GetNum())
		{
			Date Today(year, month, day);//����ָ�����ꡣ
			return Past.Count2(Today);//��������˳��
		}
		int sum = 0;
		//����������ʵ�������������ա��¡����Ѿ���DayofYear�н����
		if (year > Past.year)
		{
			int Y = Past.year;
													sum += (Past.IsLeapYear()?366:365)-Past.DayofYear();//��һ��
			for (Y++; Y> year; Y++)		sum += (IsLeapYear(Y) ? 366 : 365);//�м��ÿһ���������
													sum += DayofYear();//���һ��ʣ�µ�������
		}
		else sum = DayofYear() - Past.DayofYear();//ֱ�ӷ����������ڲ
		return sum;
	}
	void CalenderM()//��ӡĳһ���µ�������Ҫ���븽�������ڵ����ڡ�
	{
		Date TheFirst = { year, month, 1 };	//�Ӹ��µĵ�һ������
		Date TheLast = { year, month, GetMonth() };
		//���������ǵ��������ʽ�������ˡ�
		printf("\n%d��%d��:\n������\t\tһ\t\t��\t\t��\t\t��\t\t��\t\t�� \n  ", year, month);
		for (int i = 0; i <TheFirst.week; i++)	printf("\t\t");
		for (; TheFirst.GetNum() <= TheLast.GetNum(); TheFirst.Plus())
		{
			printf("\t\t%d", TheFirst.day);
			if (TheFirst.week == 6)printf("\n  ");
		}
		printf("\n");
	}
	void CalenderY()//��ӡһ�������
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
	//printf("������������ڸ�ʽΪ��19950930 20141129");
	while (scanf_s("%d%d", &d1, &d2) == 2)
	{
		Date date1(d1);
		Date date2(d2);
		cout << "���ڲ�Ϊ" << date1.Count(date2) <<' '<<date2.Count2(date1)<<endl;
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
