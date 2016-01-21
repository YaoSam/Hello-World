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
using namespace std;
#define Re(i,n)		for(int i=1;i<=n;i++) //循环n次
#define re(i,n)		for(int i=0;i<n;i++)	//从0开始。
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
	int mynum;				//填上的数字。
	friend class sudoku;
	friend istream&operator>>(istream &yes, sudoku &other);
	friend ostream&operator<<(ostream &out, sudoku other);
public:
	dot()
	{
		memset(num, 0, sizeof(num));
		mynum = 0;
	}
	bool exclude(int n)			//排除
	{
		//if (n < 1 || n>9)debug("排除数字越界！");
		if (mynum == n)	//有矛盾！
		{
			return false;
		}
		num[n]=1;
		return	true;
	}
	bool ifone()
	{
		if (mynum==0)	//还没有被确定时
			Re(i,9)
				if (num[i] ==0)
				{
					if (mynum == 0)	//还没有遇见不为零的数。
						mynum = i;		//遇到第一个不为零的数
					else						//（此时mynum不为零了。）
					{
						mynum = 0;		//遇到两个不为零的数了。
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
			//三个都会执行，担忧第小节执行了之后第小节才会执行
			if (((k != j) && (!Map[i][k].exclude(n)))
				|| ((k != i) && (!Map[k][j].exclude(n)))
				|| ((x + k % 3 != i&&y + k / 3 != j) && (!Map[x + k % 3][y + k / 3].exclude(n))))
			{
				cout << "矛盾" << endl;
				return false;
			}
		}
		return true;
	}

	int solve()
	{
		memset(isRemove, 0, sizeof(isRemove));
		bool IfSolved = 0;	//用来记录是否还有未被排除的。
		int Count = 0; //用来跳出死循环。
		while (IfSolved == 0)
		{
			//cout << ++Count<< endl << *this << endl;
			if (Count++ >= 10)return 0;
			//预处理，顺便排除一些比较容易排除的。
			IfSolved = 1;
			re(i, 9)
				re(j, 9)
				if (isRemove[i][j] == 0)		//并没有被用来排除过
				{
					IfSolved = 0;
					if (Map[i][j].ifone()) //如果并没有排除过并且已经被确定。
					{
						isRemove[i][j] = 1;
						if (!remove(i, j, Map[i][j].mynum))		return -1;
					}
				}
			//////////////////////////////////////////////////////////////////////////
			Re(k, 9)	//k做为数字,三种扫描方式。		
				re(i, 9)
			{
				//////////////////////////////////////////////////////////////////////////
				int tempj = -1;									//记录k的位置j。
				//j为行数，打横扫
				re(j, 9)
				{
					if (Map[i][j].mynum == k)	break;	//遇到k退出。
					else if (Map[i][j].mynum == 0 && Map[i][j].num[k] == 0)	//遇到空位，并且k没有被排除。
					{
						if (tempj == -1)		//第一次，记录下空位
							tempj = j;
						else						//第二次遇到可以填k的空位，清空退出。
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
				//j为列数，打竖扫
				re(j, 9)
				{
					if (Map[j][i].mynum == k)	break;		//遇到k退出。
					else if (Map[j][i].mynum == 0 && Map[j][i].num[k] == 0)	//遇到空位，并且k没有被排除。
					{
						if (tempj == -1)		//第一次，记录下空位
							tempj = j;
						else						//第二次遇到可以填k的空位，清空退出。
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
				//在block里面扫
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
		if (ans == -1)//进行简单解。
		{
			if (CountTime == 0)
			{
				cout << "无法求解！" << endl;
			}
			//cout << "this time I failed" << endl << *this << endl;
			return -1; //出错了
		}
		else if (ans == 1)
		{
			isDFSsolve = 1;
			return 1;
		}
		else 
		{
			//out部分
			re(i, 9)
				re(j, 9)
				if (isRemove[i][j] == 0)
					Re(k, 9)
					if (Map[i][j].num[k] == 0)
					{
						sudoku tempOne = *this;		//记录下此时状态。
						Map[i][j].mynum = k;				//乱填一个数。
						memset(isRemove, 0, sizeof(isRemove));
						re(z, 99)memset(Map[z / 9][z % 9].num, 0, sizeof(int) * 10);
						DFSsolve(1);							//进行求解。
						if (isDFSsolve){ cout << "Let's count!" << endl; return 0; }
						//如果可以就不玩了。
						*this = tempOne;					//出来了，并且不成功，就是出错了。
						Map[i][j].num[k] = 1;				//放弃该位置的该数字。
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
