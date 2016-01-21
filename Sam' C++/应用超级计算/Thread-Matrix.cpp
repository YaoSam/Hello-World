#include <thread>
#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;
#define Re(i,n) for(int i=1;i<=n;i++)
int m, n, r; 

int Matrix1[100][100];
int Matrix2[100][100];
int ANS[100][100];

int DotPro(int *vector1,int *vector2,int &ans)
{
	Re(i, n)
		ans= vector1[i] * vector2[i];
	return 0;
}/*
DWORD WINAPI Func(LPVOID num)
{
	int *p = (int *)num;
	DotPro(Matrix1[p[0]], Matrix2[p[1]], ANS[p[0]][p[1]]);
	return 0;
}*/
int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	cin>>m >> n >> r; 
	int num[10];
	Re(i, m)//m*n m行
		Re(j, n)
			cin >> Matrix1[i][j];
	Re(i, n) //n*r	n行
		Re(j, r)
			cin >> Matrix2[i][j];
	vector<thread> threads;
	Re(i,m)
		Re(j, r)
	{
		threads.push_back(thread(DotPro(Matrix1[i], Matrix2[j], ANS[i][j])));
	}
	for (auto& thread : threads)
	{
		thread.join();
	}

	Re(i, m)		
	{
		Re(j, r)
			cout << ANS[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
