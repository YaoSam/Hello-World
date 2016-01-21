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
int const SIZE = 200;
int map[SIZE][SIZE];
int TIME[SIZE][SIZE];
unsigned int height, width;
unsigned int beginx, beginy;
unsigned int endx, endy;
void input()
{
	cin >> height >> width;
	re(i, height)
		re(j, width)
		cin >> map[i][j];
}
void output()
{
	re(i, height)
	{
		re(j, width)
			cout << TIME[i][j] << ' ';
		cout << endl;
	}
}

struct point{
	int x, y;
	point(int  a=0, int b=0) :x(a), y(b){}
};
point Begin(beginx, beginy);
point end(endx, endy);
point quene[10000];
point directoin[10] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

void bfs()
{
	//��ʼ��
	quene[1] = Begin;
	TIME[Begin.y][Begin.x] = 0;
	int rear = 1, front = 2;
	while (rear!=front)
	{
		point now = quene[rear++];
		re(i, 4)
		{
			point next(now.x + directoin[i].x, now.y + directoin[i].y);
			//�ж��Ƿ�Խ���ײǽ
			if ((next.x >= 0 && next.x < width&&next.y >= 0 && next.y < height) && map[next.y][next.x] != 1)
			{
				//�ж��ٶ�
				if (TIME[next.y][next.x] == 0 || TIME[next.y][next.x] > TIME[now.y][now.x] + 1)
				{
					//output();
					TIME[next.y][next.x] = TIME[now.y][now.x] + 1;
					//������С�
					quene[front++] = next;
				}
			}
		}
	}
	output();
	cout << TIME[endy][endx] << endl;
	memset(quene, 0, sizeof(quene));
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
	bfs();

#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}