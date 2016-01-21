#include <iostream>
using namespace std;
#define DEBUG
int map[15],visit[15];//
int Count = 0;

int array[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; 
int top = 0;
int queue[10] = { 0 };
inline void Print(int n)
{
	Count++;
	if(n!=2)
		for (int i = 1; i <= n; i++)
			cout << map[i];
	if (n == 2)
		cout << map[1] << '*' << map[2] << '=' << map[1] * map[2];
	cout << endl;
}
int dfs(int length, int left,int n)
{
	if (left == 0)Print(n);
	if(left!=0)
		for (int i = 1; i <= length; i++)
		if (visit[i] == 0)
		{
			visit[i] = 1;
			map[n - left+1] = i;
			dfs(length, left - 1, n);
			visit[i] = 0;
		}
	return 0;
}

void comb(int s, int m, int n)
{
	if (s > m)
	{ 
#ifdef DEBUG		
		cout << "end" << endl; 
#endif		
		return; 
	}

	if (top == n)
	{
		for (int i = 0; i < n; i++)cout << queue[i];
		cout << '\n';
		return;
	}
	queue[top++] = array[s];
	comb(s + 1, m, n);
	top--; 
#ifdef DEBUG
	cout <<"This are:"<< top<<' '<<s<<endl;
#endif
	comb(s + 1, m, n);
}

int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err,"in.txt", "r", stdin);
	freopen_s(&err,"out.txt", "w", stdout);
#endif
	comb(0,5,3);
	/*
	dfs(5, 3, 3);
	cout << Count<<endl;
	dfs(9, 2, 2);
	cout << Count;*/
#ifndef DEBUG
	system("pause");
#endif	
	return 0;
}