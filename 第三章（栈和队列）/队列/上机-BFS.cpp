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

struct point{
	int x;
	int last; //记录的是上一个点在队列中的坐标。
	point(int X=0,int Last=0) :x(X), last(Last){}
};

int CostTime[100][100]; //记录点到点的耗时
int AllTime[100][100];		//记录从Begin到该点的时间。如果为零则是没有到达。
int Num/*总点数*/,Begin/*起点*/, End/*终点*/;		
point quene[10000];

void bfs()
{
	int first=0, rear=0;
	point temp;
	quene[first++] = point(Begin, Begin);//第一个点就把自己作为上一个点吧。反正不影响。
	while (rear != first)
	{
		temp = quene[rear++];
		re(i, Num)										//枚举每一个点看是否有路。
			if (CostTime[temp.x][i] >= 0)		//判断是否有路
			{
				if (AllTime[Begin][i] == 0 || (AllTime[Begin][i] > (AllTime[Begin][temp.x] + CostTime[temp.x][i])))
				//判断速度。
				{
					//更新时间。并且加入队列。略像动态规划。
					AllTime[Begin][i] = AllTime[Begin][temp.x]+ CostTime[temp.x][i];
					quene[first++] = point(i, rear-1);// 因为之前rear做了个++，现在减回去
				}
			}
	}
	//输出
	if (AllTime[Begin][End] > 0)
	{
		cout <<"最短时间为："<< AllTime[Begin][End] << endl;
		while (quene[first].x != End)	first--;
		//向前查找到最后的End节点。因为这时的End时间才是最短的。
		temp = quene[first];
		//输出路径。反向查找。
		while (temp.last != Begin)
		{
			cout << temp.x << endl;
			temp = quene[temp.last];
		}
		cout << Begin << endl;
	}
	else
		cout << "无法到达" << endl;
	//队列归零。
	memset(AllTime, 0, sizeof(AllTime));
	memset(quene, 0, sizeof(quene));
}

int main()
{
	srand(time(NULL));
#ifdef DEBUG
	FILE *err; //没用的指针... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	//input
	memset(CostTime, -1, sizeof(CostTime));
	cin >> Num >> Begin >> End;
	int from, to, Cost;
	while (cin >> from >> to >> Cost)
		CostTime[from][to] = Cost;
	bfs();
#ifndef DEBUG //加个断点。
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}


/*Sample Input
5 3 2
0 1 6
0 2 4
0 4 3
1 2 4
3 0 15
3 1 5
3 2 10
3 4 7
4 2 2
^Z
*/