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

#define DEBUG //用来确定是否文本输出。
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
int const SIZE = 200;
int map[SIZE][SIZE];
int road[SIZE][SIZE];
int visit[SIZE][SIZE];
int height, width;//
int beginx, beginy;
int endx, endy;
void input()
{
	cin >> height >> width;
	re(i, height)
		re(j, width)
		cin >> map[i][j];

}
bool done = 0;
int MaxTime = 0;
int dfs(int x, int y,int times=0,int A=0,int B=0)
{
	//数组越界 或者 遇到墙壁
	//cout << y << ' ' << x<< endl;
	////cout << map[y][x] << endl;
	//re(i, height)
	//{
	//	re(j, width)
	//		cout << road[i][j] << ' ';
	//	cout << endl;
	//}
	if(x == endx&&y == endy)
	{
		return done = 1;
	}
	if (x < 0 || y < 0 || y >= height || x >= width || map[y][x]==1 || road[y][x] ==-1||visit[y][x])
	{
		return -1;
	}

	visit[y][x] = 1;
	if (!done)
	road[y][x]=dfs(x+1, y, times + 1,x,y);
	if (!done)
		road[y][x] = dfs(x - 1, y, times + 1, x, y);
	if (!done)
		road[y][x] = dfs(x, y + 1, times + 1, x, y);
	if (!done)
		road[y][x] = dfs(x, y - 1, times + 1, x, y);
	visit[y][x] = 0;
	return done;
}


int main()
{
	srand(time(NULL));
#ifdef DEBUG
	FILE *err; //没用的指针... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	cin >> beginx >> beginy >> endx >> endy;
	input();
	//road[beginy][beginx] = 0;
	dfs(beginx, beginy);
	re(i, height)
	{
		re(j, width)
			cout << road[i][j] << ' ';
		cout << endl;
	}
#ifndef DEBUG //加个断点。
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}