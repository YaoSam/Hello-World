#include <iostream>
using namespace std;
//#define DEBUG

int inverse(int n)
{
	cout << n % 10;
	if (n < 10)
	{
		cout << endl;
		return 0;
	}
	else inverse(n / 10);
}
int factor(int n)
{
	int half = n / 2, Count = 0;
	cout <<n<< "'s factors are :";
	for (int i = 2; i <= half; i++)
		if (n%i == 0)
		{
			cout << i << ' ';
			n /= i; 
			Count++;
			i = 1;
		}
	cout << endl;
	return Count;
}
int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	bool IsLeapYear;
	int year;
	cout << "Enter the year"<<endl;
	cin >> year;
	IsLeapYear = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	if (IsLeapYear)
		cout << year << " is leapyear!";
	else
		cout << year << " is not leapyear!";
	inverse(year);
	for (int i = 2; i <= 1000;i++)
	factor(i);

	return 0;
}