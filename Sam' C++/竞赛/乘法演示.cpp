#include <iostream>
using namespace std;
#define DEBUG
/*没什么好说的*/
int ten[10] = {1, 1, 10, 100, 1000,10000,100000};
char X[10], Y[10], map[10][10][3], ans[10];
int Digit(int a)//判断位数
{
	if (a < 10) return 1;
	else return Digit(a/10) + 1;
}
void turn(int x,char str[])
{
	for (int i = 1; i <=Digit(x); i++)
		str[i] ='0'+ (x / ten[Digit(x)-i]) % 10;
#ifdef DEBUG
	cout << str<<endl;
#endif
}
int digit(int x, int n)
{
	return (x / ten[n]) % 10;
}

void headline(int a)
{
	cout << "+--";
	for (int i = 1; i <= a; i++)cout << "----";
	cout << "-+"<<endl;
}
void midline(int a)
{
	cout << "| +";
	for (int i = 1; i <= a; i++)cout << "---+";
	cout << " |" <<endl;
}

void empty(int a,int n)
{
	cout << "| |";
	for (int i = 1; i <= a; i++)cout << " / |";
	cout << n;
	cout << "|" << endl;
}
int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	int x, y;
	cin >>x >> y;
	while(x!=0||y!=0)
	{
		int colume = Digit(x), raw = Digit(y);
		turn(x, X), turn(y, Y), turn(x*y, ans);
		for (int i = 1; i <= colume; i++)
			for (int j = 1; j <= raw; j++)
				turn((X[i]-'0')* (Y[j]-'0'), map[i][j]);
		headline(colume);
		midline(colume);
		empty(colume, 1);
		headline(colume);
		cin >> x >> y;
	}

#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}