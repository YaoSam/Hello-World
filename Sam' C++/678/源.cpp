#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
//#define scanf scanf_s
const int maxn = 1020;
const int INF = 999999999;
int n;
struct Point
{
	double x, y;
};
Point stone[maxn];
double xmap[maxn][maxn];
int vis[maxn];
double dist[maxn];
int T=0;
double dis(int i, int j)
{
	return sqrt((stone[i].x - stone[j].x)*(stone[i].x - stone[j].x) + (stone[i].y - stone[j].y)*(stone[i].y - stone[j].y));
}
int init()
{
	memset(xmap, 0, sizeof(xmap));
	memset(stone, 0, sizeof(stone));
	scanf("%d", &n);
	if (n == 0)return 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf%lf", &stone[i].x, &stone[i].y);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			xmap[i][j] = dis(i, j);
			xmap[i][i] = INF;
		}
	return 1;
}
int SPFA(int v0,int vt)
{
	memset(vis, 0, sizeof(vis));
	queue <int> Q;
	for (int i = 1; i <= n; i++)
	{
		dist[i] = INF;
	}
	vis[v0] = 1;
	Q.push(v0);
	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		vis[now] = 0;
		for (int i = 1; i <= n; i++)
		{
			if (i == now) continue;
			if (dist[i] > min(dist[now], xmap[now][i]))
			{
				dist[i] = min(dist[now], xmap[now][i]);
				if (vis[i] == 0)
				{
					vis[i] = 1;
					Q.push(i);
				}
			}
		}
	}
	printf("Scenario #%d\nFrog Distanc = %.3lf\n\n", T, dist[vt]);
	return 0;
}
int solve()
{
	SPFA(1,2);
	return 0;
}
int main()
{
	T = 0;
	while (init())
	{
		T++;
		solve();
	}
}