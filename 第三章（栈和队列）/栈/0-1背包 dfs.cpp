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

int weight[1000];
int n;
int flag[1000];
int ans = 0;
void input()
{
	cin >> n;
	re(i, n)
		cin >> weight[i];
}

void dfs(int times=0)
{
	if (times == n)
	{
		re(i, n)
		{
			cout << weight[i] << ": " << (flag[i]==1?"*":" ") << ' ';
			ans += (flag[i]==1) ? weight[i] : 0;
		}
		cout << endl;
		cout << "������Ϊ��" << ans << endl;
		ans = 0;
		return;
	}
	else
	{
		//����
		flag[times] = 0;
		dfs(times + 1);
		//��
		flag[times] = 1;
		dfs(times + 1);
		//��ԭ
		flag[times] = 0;
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
	input();
	dfs();

#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}


/*
Sample Input
5
12 113 45 65 234 123
*/