#pragma once
	const char Gender[2][5] = { "��", "Ů" }; //ͨ��һ��Bool��ȷ����Ů
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
