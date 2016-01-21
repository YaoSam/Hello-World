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
using namespace std;
#define Re(i,n)		for(int i=1;i<=n;i++) //ѭ��n��
#define re(i,n)		for(int i=0;i<n;i++)	//��0��ʼ��
void debug(string warning)
{
	cerr << warning << endl;
	system("pause");
	exit(1);
}

int isDFSsolve = 0;

class dot
{
	int num[10];
	int mynum;				//���ϵ����֡�
	friend class sudoku;
	friend istream&operator>>(istream &yes, sudoku &other);
	friend ostream&operator<<(ostream &out, sudoku other);
public:
	dot()
	{
		memset(num, 0, sizeof(num));
		mynum = 0;
	}
	bool exclude(int n)			//�ų�
	{
		//if (n < 1 || n>9)debug("�ų�����Խ�磡");
		if (mynum == n)	//��ì�ܣ�
		{
			return false;
		}
		num[n]=1;
		return	true;
	}
	bool ifone()
	{
		if (mynum==0)	//��û�б�ȷ��ʱ
			Re(i,9)
				if (num[i] ==0)
				{
					if (mynum == 0)	//��û��������Ϊ�������
						mynum = i;		//������һ����Ϊ�����
					else						//����ʱmynum��Ϊ���ˡ���
					{
						mynum = 0;		//����������Ϊ������ˡ�
						return false;
					}
				}
		return true;
	}
};


class sudoku
{
	dot Map[9][9];
	bool isRemove[9][9];
public:
	friend istream&operator>>(istream &yes, sudoku &other);
	friend ostream&operator<<(ostream &out, sudoku other);
	bool remove(int i, int j, int n)
	{
		int x = 3 * (i / 3), y = 3 * (j / 3);
		re(k, 9)
		{
			//��������ִ�У����ǵ�С��ִ����֮���С�ڲŻ�ִ��
			if (((k != j) && (!Map[i][k].exclude(n)))
				|| ((k != i) && (!Map[k][j].exclude(n)))
				|| ((x + k % 3 != i&&y + k / 3 != j) && (!Map[x + k % 3][y + k / 3].exclude(n))))
			{
				cout << "ì��" << endl;
				return false;
			}
		}
		return true;
	}

	int solve()
	{
		memset(isRemove, 0, sizeof(isRemove));
		bool IfSolved = 0;	//������¼�Ƿ���δ���ų��ġ�
		int Count = 0; //����������ѭ����
		while (IfSolved == 0)
		{
			//cout << ++Count<< endl << *this << endl;
			if (Count++ >= 10)return 0;
			//Ԥ����˳���ų�һЩ�Ƚ������ų��ġ�
			IfSolved = 1;
			re(i, 9)
				re(j, 9)
				if (isRemove[i][j] == 0)		//��û�б������ų���
				{
					IfSolved = 0;
					if (Map[i][j].ifone()) //�����û���ų��������Ѿ���ȷ����
					{
						isRemove[i][j] = 1;
						if (!remove(i, j, Map[i][j].mynum))		return -1;
					}
				}
			//////////////////////////////////////////////////////////////////////////
			Re(k, 9)	//k��Ϊ����,����ɨ�跽ʽ��		
				re(i, 9)
			{
				//////////////////////////////////////////////////////////////////////////
				int tempj = -1;									//��¼k��λ��j��
				//jΪ���������ɨ
				re(j, 9)
				{
					if (Map[i][j].mynum == k)	break;	//����k�˳���
					else if (Map[i][j].mynum == 0 && Map[i][j].num[k] == 0)	//������λ������kû�б��ų���
					{
						if (tempj == -1)		//��һ�Σ���¼�¿�λ
							tempj = j;
						else						//�ڶ�������������k�Ŀ�λ������˳���
						{
							tempj = -1;
							break;
						}
					}
				}
				if (tempj != -1)
				{
					Map[i][tempj].mynum = k;
					if (!remove(i, tempj, k))return false;
					isRemove[i][tempj] = 1;
					//cout << '(' << i << ',' << tempj << ')' << ':' << k << endl;
				}
				//////////////////////////////////////////////////////////////////////////
				tempj = -1;
				//jΪ����������ɨ
				re(j, 9)
				{
					if (Map[j][i].mynum == k)	break;		//����k�˳���
					else if (Map[j][i].mynum == 0 && Map[j][i].num[k] == 0)	//������λ������kû�б��ų���
					{
						if (tempj == -1)		//��һ�Σ���¼�¿�λ
							tempj = j;
						else						//�ڶ�������������k�Ŀ�λ������˳���
						{
							tempj = -1;
							break;
						}
					}
				}
				if (tempj != -1)
				{
					Map[tempj][i].mynum = k;
					if (!remove(tempj, i, k))return false;
					isRemove[tempj][i] = 1;
					//cout << '(' << tempj << ',' << i << ')' << ':' << k << endl;
				}
				//////////////////////////////////////////////////////////////////////////
				tempj = -1;
				//��block����ɨ
				re(j, 9)
				{
					int x = 3 * (i % 3) + j % 3, y = 3 * (i / 3) + j / 3;
					if (Map[x][y].mynum == k)break;
					else if (Map[x][y].mynum == 0 && Map[x][y].num[k] == 0)
					{
						if (tempj = -1)
							tempj = -1;
						else
						{
							tempj = -1;
							break;
						}
					}
				}
				if (tempj != -1)
				{
					Map[3 * (i % 3) + tempj % 3][3 * (i / 3) + tempj / 3].mynum = k;
					if (!remove(3 * (i % 3) + tempj % 3, 3 * (i / 3) + tempj / 3, k))return false;
					isRemove[3 * (i % 3) + tempj % 3][3 * (i / 3) + tempj / 3] = 1;
					//cout << '(' << 3 * (i % 3) + tempj % 3 << ',' << 3 * (i / 3) + tempj / 3 << ')' <<':'<<k<< endl;
				}
			}
		}

		return true;
	}

int DFSsolve(int CountTime=0)
	{
		if (isDFSsolve)return 0; //Just in case;
		//sudoku one = *this;
		//memset(one.isRemove, 0, sizeof(one.isRemove));
		//re(i, 81) memset(one.Map[i / 9][i % 9].num, 0, sizeof(int) * 10);
		int ans = solve();
		if (ans == -1)//���м򵥽⡣
		{
			if (CountTime == 0)
			{
				cout << "�޷���⣡" << endl;
			}
			//cout << "this time I failed" << endl << *this << endl;
			return -1; //������
		}
		else if (ans == 1)
		{
			isDFSsolve = 1;
			return 1;
		}
		else 
		{
			//out����
			re(i, 9)
				re(j, 9)
				if (isRemove[i][j] == 0)
					Re(k, 9)
					if (Map[i][j].num[k] == 0)
					{
						sudoku tempOne = *this;		//��¼�´�ʱ״̬��
						Map[i][j].mynum = k;				//����һ������
						memset(isRemove, 0, sizeof(isRemove));
						re(z, 99)memset(Map[z / 9][z % 9].num, 0, sizeof(int) * 10);
						DFSsolve(1);							//������⡣
						if (isDFSsolve){ cout << "Let's count!" << endl; return 0; }
						//������ԾͲ����ˡ�
						*this = tempOne;					//�����ˣ����Ҳ��ɹ������ǳ����ˡ�
						Map[i][j].num[k] = 1;				//������λ�õĸ����֡�
					}
		}
		return 0;
	}
};
istream &operator>>(istream &in, sudoku &other)
{
	re(i,9)
		re(j, 9)
			in >> other.Map[i][j].mynum;
	//string number;
	//in >> number;
	//re(i, 9)
	//	re(j, 9)
	//	other.Map[i][j].mynum = number[i * 9 + j] - '0';
	return in;
}
ostream&operator<<(ostream &out, sudoku other)
{
	re(i, 9)		
	{
		re(j, 9)
		{
			out << other.Map[i][j].mynum << ' ';
			if ((j + 1) % 3 == 0)	out << ' ';
		}
		out << endl;
	if ((i+1) % 3 == 0)	out << endl;
	}
	return out;
}
