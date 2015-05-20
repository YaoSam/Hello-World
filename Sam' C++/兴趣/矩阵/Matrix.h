#pragma once
#include <iostream>
#include <string>
#include "C:\Users\Sam\OneDrive\C++\Source\Sam' C++\Sam' C++\兴趣\多项式\Q.h"
using namespace std;
#define  RE(i,j,n) for(int i=j;i<=n;i++)
#define  Re(i,n) for(int i=1;i<=n;i++)
void debug(string warning)
{
	cout << warning << endl;
	system("pause");
	exit(1);
}

class Mn
{
	Q **num;
	int row, colume;
	void swap(int a,int b);
	void subtract(int a, int b, Q k);
	Q *operator[](int i)		{ return num[i]; }//Warning:这里的效率会很低。
	const Q *operator[](int i)const 	{ return num[i]; }
public:
	Mn();
	~Mn();
	Mn(int *N, int r, int c);
	Mn(Mn const &other);
	Mn &operator=(Mn const &other);
	friend ostream& operator<<(ostream &out, Mn const &other);
	friend istream& operator>>(istream &in, Mn &other);
	Mn rref()const;
	Q det()const;
};

Mn::Mn() :row(1), colume(1)
{
	num = new Q *[row + 1];			//指针
	num[1] = new Q[colume + 1];	
}

Mn::Mn(int *NUM, int r, int c) :row(r), colume(c)
{
	num = new Q *[r + 1];		//申请r个指针
	Re(i, r)
	{
		num[i] = new Q[c + 1];		//申请r 个空间。
		Re(j, c)num[i][j] = NUM[i*c + j];
	}
}
Mn::Mn(Mn const &other) :row(other.row), colume(other.colume)
{
	num = new Q *[row + 1];
	Re(i, row)
	{
		num[i] = new Q[colume + 2];
		Re(j, colume)num[i][j] = other.num[i][j];
	}
}
Mn &Mn::operator=(Mn const &other)
{
	if (this == &other)return *this;
	Re(i, colume) delete[] num[i];
	delete[] num;
	num = new Q *[row + 1];
	Re(i, row)
	{
		num[i] = new Q[colume + 1];
		Re(j, colume)num[i][j] = other.num[i][j];
	}
	return *this;
}
ostream& operator<<(ostream &out, Mn const &other)
{
	Re(i, other.row)
	{
		Re(j, other.colume)
			out << other.num[i][j]<<'\t';
		out << endl;
	}
	return out;
}

void Mn::swap(int a, int b)		//交换a，b两行
{
	if (a <= 0 || b <= 0 || a > row || b > colume)	debug("交换越界");
	if (a == b)return;
	Q *temp = new Q[colume+1];
	memcpy(temp, num[a], sizeof(Q)*(colume+1));
	memcpy(num[a], num[b], sizeof(Q)*(colume + 1));
	memcpy(num[b], temp, sizeof(Q)*(colume+1));
	delete temp;
}
void Mn::subtract(int a, int b, Q k) //b-=a*k
{
	if (a == b) debug("不能自己减自己。in subtract().");
	if (k == 0)	return;		
	Re(i, colume)
		num[b][i] -= num[a][i] * k;
}

Mn::~Mn()
{
	Re(i, row) delete[] num[i];
	delete[] num;
}

Mn Mn::rref()const
{
	bool flag = 0;
	Mn temp(*this);
	Re(i, temp.row-1) 
		RE(y, i, temp.colume)					//从左往右
		{
			RE(k, y, temp.row)
				if (!(temp[k][y] == 0))			//先从上往下找不为零的主元
				{
					flag = 1;							//找到了
					temp.swap(k, i);					//交换，现在k在第i行,也就是num[i][i]!=0
					RE(x, i + 1, row)
						if (!(temp[x][y] == 0))		//找到主元项不为零的行。
						{
							Q tempk = temp[x][y] / temp[i][y];
							temp.subtract(i, x, tempk);
						}
					break;
				}
			if (flag){ flag = 0; break; }
		}
	return temp;
}

Q Mn::det()const
{
	if (row != colume)debug("不是方阵，不能计算行列式。");
	Mn one = rref();
	Q ans = 1;
	Re(i, row)	ans *= one[i][i];
	return ans;
}