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

//#define DEBUG //����ȷ���Ƿ��ı������
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

struct point{
	int x;
	int last; //��¼������һ�����ڶ����е����ꡣ
	point(int X=0,int Last=0) :x(X), last(Last){}
};

int CostTime[100][100]; //��¼�㵽��ĺ�ʱ
int AllTime[100][100];		//��¼��Begin���õ��ʱ�䡣���Ϊ������û�е��
int Num/*�ܵ���*/,Begin/*���*/, End/*�յ�*/;		
point quene[10000];

void bfs()
{
	int first=0, rear=0;
	point temp;
	quene[first++] = point(Begin, Begin);//��һ����Ͱ��Լ���Ϊ��һ����ɡ�������Ӱ�졣
	while (rear != first)
	{
		temp = quene[rear++];
		re(i, Num)										//ö��ÿһ���㿴�Ƿ���·��
			if (CostTime[temp.x][i] >= 0)		//�ж��Ƿ���·
			{
				if (AllTime[Begin][i] == 0 || (AllTime[Begin][i] > (AllTime[Begin][temp.x] + CostTime[temp.x][i])))
				//�ж��ٶȡ�
				{
					//����ʱ�䡣���Ҽ�����С�����̬�滮��
					AllTime[Begin][i] = AllTime[Begin][temp.x]+ CostTime[temp.x][i];
					quene[first++] = point(i, rear-1);// ��Ϊ֮ǰrear���˸�++�����ڼ���ȥ
				}
			}
	}
	//���
	if (AllTime[Begin][End] > 0)
	{
		cout <<"���ʱ��Ϊ��"<< AllTime[Begin][End] << endl;
		while (quene[first].x != End)	first--;
		//��ǰ���ҵ�����End�ڵ㡣��Ϊ��ʱ��Endʱ�������̵ġ�
		temp = quene[first];
		//���·����������ҡ�
		while (temp.last != Begin)
		{
			cout << temp.x << endl;
			temp = quene[temp.last];
		}
		cout << Begin << endl;
	}
	else
		cout << "�޷�����" << endl;
	//���й��㡣
	memset(AllTime, 0, sizeof(AllTime));
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
	//input
	memset(CostTime, -1, sizeof(CostTime));
	cin >> Num >> Begin >> End;
	int from, to, Cost;
	while (cin >> from >> to >> Cost)
		CostTime[from][to] = Cost;
	bfs();
#ifndef DEBUG //�Ӹ��ϵ㡣
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