#pragma once
	const char Gender[2][5] = { "男", "女" }; //通过一个Bool来确定男女
	class Date
	{
	private:
		int year, month, day;
	public:
		Date();
		Date(int date);
		Date(Date &p);
		void ShowDate();
		~Date();
	};
class People
	{
	private:		
		bool sex; int num, ID[20]; Date birthday;
	public:
		People();
		People(int Num, bool Sex, char id[], int date);
		void ShowPeople();
		People(People &p);
		~People();
	};
