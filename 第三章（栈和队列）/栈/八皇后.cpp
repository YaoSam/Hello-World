/*
*
*　　　	 　　　　   ┏┓　		 ┏┓+ +
*　　  　　　　　┏┛┻━━━━━━┛┻┓ + +
*　　  　　　　　┃　　　　       ┃ 　
*　　  　　　　　┃　　　━　　 ┃ ++ + + +
*　　  　　		   ┃  ███━███  ┃+
*　　  　　　　　┃　　　　　　┃ +
*　　  　　　　　┃　　   ┻　　  ┃
*　　  　　　　　┃　　　　　　┃ + +
*　　  　　　　　┗━┓　　　 ┏━┛
*　　　　　　　　　┃　　　┃　　　　　　　　　　　
*　　　　　　　　　┃　　　┃ + + + +
*　　　　　　　　　┃　　　┃　　　　Code is far away from bug with the animal protecting　　　　　　　
*　　　　　　　　　┃　　　┃ + 　　　　神兽保佑,代码无bug　　
*　　　　　　　　　┃　　　┃
*　　　　　　　　　┃　　　┃　　+　　　　　　　　　
*　　　　　　　　　┃　 　　┗━━━┓ + +
*　　　　　　　　　┃ 　　　　　　　┣┓
*　　　　　　　　　┃ 　　　　　　　┏┛
*　　　　　　　　　┗┓┓┏━┳┓┏┛ + + + +
*　　　　　　　　　　┃┫┫　┃┫┫
*　　　　　　　　　　┗┻┛　┗┻┛+ + + +
*/
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

//#define DEBUG //用来确定是否文本输出。
#ifndef re(i,n)
#define re(i,n) for(unsigned int i=0;i<n;i++)
#endif // !re(i,n)
#ifndef Re(i,n)
#define Re(i,n)		for(unsigned int i=1;i<=n;i++) //循环n次
#endif // !Re(i,n)

void debug(string warning)
{
	cerr << warning << endl;
	system("pause");
	exit(1);
}

int map[15][15];
int flag[15][15];
int max = 0;
void MAP(int x, int y,bool Flag)
{
	flag[y][x] = Flag; //标记自己。
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (i||j)//不包括零向量。
				Re(k, max)
			{
				if (((x + k*i) > 0) && ((x + k*i) <= max) && ((y + k*j) > 0) && ((y + k*j) <= max))//判定是否越界。
					if(Flag)//用来判定取消标记还是标记
						map[y + k*j][x + k*i]++;
					else	
						map[y + k*j][x + k*i]--;
			}
}

int COUNT = 0;
void Queen(int y=1)
{
	if (y == max+1)
	{
		COUNT++;
		//Re(i, max)
		//{
		//	Re(j, max)
		//		cout << (flag[i][j]?'Q':'*') << ' ';
		//	cout << endl;
		//}
		//cout << endl;
		return;
	}
	Re(i,max)
	{
		if (!map[y][i])
		{
			MAP(i, y, 1);
			Queen(y + 1);
			MAP(i, y, 0);
		}
	}
}



int main()
{
	srand(time(NULL));
#ifdef DEBUG
	FILE *err; //没用的指针... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	clock_t t1 = clock();
	max = 12;
	Queen();
	cout<<clock()-t1<<endl;
	//cout << COUNT << endl;
#ifndef DEBUG //加个断点。
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}