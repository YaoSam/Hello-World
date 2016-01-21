/*
*
*������	 ��������   ������		 ����+ +
*����  ���������������ߩ��������������ߩ� + +
*����  ��������������������       �� ��
*����  ������������������������ �� ++ + + +
*����  ����		   ��  ��������������  ��+
*����  �������������������������� +
*����  ����������������   �ߡ���  ��
*����  �������������������������� + +
*����  ���������������������� ������
*��������������������������������������������������
*���������������������������� + + + +
*������������������������������������Code is far away from bug with the animal protecting��������������
*���������������������������� + �����������ޱ���,������bug����
*����������������������������
*��������������������������������+������������������
*���������������������� �������������� + +
*�������������������� ���������������ǩ�
*�������������������� ������������������
*�����������������������������ש����� + + + +
*�����������������������ϩϡ����ϩ�
*�����������������������ߩ������ߩ�+ + + +
*/
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

#define DEBUG //����ȷ���Ƿ��ı������
#ifndef re(i,n)
#define re(i,n) for(unsigned int i=0;i<n;i++)
#endif // !re(i,n)
#ifndef Re(i,n)
#define Re(i,n)		for(unsigned int i=1;i<=n;i++) //ѭ��n��
#endif // !Re(i,n)

void debug(string warning)
{
	cerr << warning << endl;
	system("pause"); 
	exit(1);
}
int map[20][20];
int road[20][20];
int height,width;//
int beginx, beginy;
int endx, endy;
void input()
{
	cin >> height >> width;
	memset(map, 0, sizeof(map));
	memset(road, 0, sizeof(road));
	re(i, height)
		re(j, width)
		cin >> map[i][j];
}
bool done = 0;
int COUNT=0;
int x1[10] = { 1, -1, 0, 0 };
int x2[10] = { 0, 0, 1, -1 };
void dfs(int x, int y)
{
	if (done)return;
	if (!(x < width&&x >= 0 && y >= 0 && y <= height)&&map[x][y]==1)
	{
		road[x][y] = -1;
		return;
	}
	if (x == endx&&y == endy)
	{
		done = 1;
		re(i, height)
		{
			re(j, width)
				cout << road[i][j] << ' ';
			cout << endl;
		}
		return;
	}
	re(k,4)
		{
			int i = x1[k], j = x2[k];
			road[x + i][y+j] = COUNT++;
			dfs(x + i, y + j);
			road[x + i][y + j] = 0;
			COUNT--;
		}
}


int main()
{
	srand(time(NULL));
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	cin >> beginx >> beginy >> endx >> endy;

	input();
	dfs(beginy, beginx);
#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}