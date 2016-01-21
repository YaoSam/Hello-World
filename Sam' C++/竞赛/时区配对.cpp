#include <iostream>
using namespace std;

int Cal(int a, int b)
{
	return 24 - (b - a) >b - a ? b - a : 24 - (b - a);
}
int main()
{
	int Time[30] = {0};
	int n,a;
	cin>>n;
	for (int i = 1; i <= n;i++)
	{
		cin >> a;
		Time[a+12]++;
	}
	for (int i = 1; i <= 24; i++)	Time[i] %= 2;		
	int sum1=0,sum2=0;
	int one=0, two=0;
	for (int i = 1; i <= 24; i++)
	{
		if (Time[i] == 1)
		{
			if (one == 0)one = i;
			else
			{
				sum1 += Cal(one, i);
				one ;
			}
		}

	}
	one =0;
	int first = 0,last=0;
	for (int i = 1; i <= 24; i++)
	{
		if (Time[i] == 1)
		{
			if (first == 0)first = i;
			else if (one == 0)one = i;
			else
			{
				sum2 += Cal(one,i);
				one= 0;
			}
			last = i;
		}
	}
	sum2 += Cal(first, last);
	int Sum = (sum1 > sum2 ? sum2 : sum1);
	cout << Sum << endl;
	return 0;
}