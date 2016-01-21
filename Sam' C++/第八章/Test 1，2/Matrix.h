#pragma once
/**
*　　　　　　　　┏┓　　　┏┓+ +
*　　　　　		　┏┛┻━━━┛┻┓ + +
*　　　　　		　┃　　　　　	┃ 　
*　　　　　		　┃　　　━　　┃ ++ + + +
*　　　　　		 ████━████	┃+
*　　　　　		　┃　　　　　	┃ +
*　　　　　		　┃　　　┻　　┃
*　　　　　		　┃　　　　　　┃ + +
*　　　　　		　┗━┓　　　┏━┛
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
#include "Q.h"
#include <omp.h>
using namespace std;
#define  RE(i,j,n) for(int i=j;i<=n;i++) //从j循环到n

class Matrix		//动态分配内存的矩阵。
{
	Q **num;
	int row, colume;
private:
	//交换a，b两行。
	void swap(int a, int b);
	//两行相减。b-=a*k					
	void subtract(int a, int b, Q k);
	//Warning:这里的效率会很低。
	Q *operator[](int i)									{ return num[i]; }
	const Q *operator[](int i)const				{ return num[i]; }
	//释放内存。size清零。
	void clear();									
public:
	Matrix();
	~Matrix()	{ clear(); }
	Matrix(int *N, int r, int c);
	Matrix(Matrix const &other);
	Matrix &operator=(Matrix const &other);
	bool operator==(Matrix const &other)const	{ return row == other.row&&colume == other.colume; } //只是比较size
	friend ostream& operator<<(ostream &out, Matrix const &other);
	friend istream& operator>>(istream &in, Matrix &other);
	friend istream& operator>>(istream &in, Matrix &other);
	Matrix &operator+=(Matrix const &other);
	friend Matrix operator+(Matrix const &A, Matrix const &B)	{ return Matrix(A)+= B; }
	friend Matrix operator*(Matrix const &A, Matrix const &B);
	Matrix rref()const;
	Q det()const;
};

Matrix::Matrix() :row(1), colume(1)
{
	num = new Q *[row + 1];		
	num[1] = new Q[colume + 1];	
}
Matrix::Matrix(int *NUM, int r, int c) :row(r), colume(c)
{
	num = new Q *[r + 1];		//申请r个指针
	Re(i, r)
	{
		num[i] = new Q[c + 1];		//申请r 个空间。
		Re(j, c)num[i][j] = NUM[i*c + j];
	}
}
Matrix::Matrix(Matrix const &other) :row(other.row), colume(other.colume)
{
	num = new Q *[row + 1];
	Re(i, row)
	{
		num[i] = new Q[colume + 1];
		memcpy(num[i], other.num[i], sizeof(Q)*(colume + 1)); 
	}
}
void Matrix::clear()
{
	Re(i, row) delete[] num[i];
	delete num;
	row = colume = 0;
}
Matrix &Matrix::operator=(Matrix const &other)
{
	if (this == &other)return *this; 
	clear();
	num = new Q *[row + 1];
	Re(i, row)
	{
		num[i] = new Q[colume + 1];
		memcpy(num[i], other.num[i], sizeof(Q)*(colume + 1)); //批量复制是这样的了。
	}
	return *this;
}
ostream& operator<<(ostream &out, Matrix const &other)
{
	Re(i, other.row)
	{
		Re(j, other.colume)
			out << other.num[i][j]<<"  ";
		out << endl;
	}
	return out;
}
//目前输入的是int型的数据
istream& operator>>(istream &in, Matrix &other)
{
	other.clear();
	in >> other.row >> other.colume;
	other.num = new Q*[other.row + 1];
	int temp;//暂时定为int吧
	Re(i, other.row)
	{
		other.num[i] = new Q[other.colume + 1];
		Re(j, other.colume) in >> temp, other.num[i][j] = temp;
	}
	return in;
}

Matrix &Matrix::operator+=(Matrix const &other)
{
	if (!(*this == other))debug("矩阵size不一致！无法相加。from +=");
	Re(i, row)
		Re(j, colume)
			num[i][j] += other.num[i][j];
	return *this;
}
//矩阵相乘。有openMP优化。
Matrix operator*(Matrix const &A, Matrix const &B)
{
	if (A.colume != B.row)debug("矩阵尺寸不匹配，无法相乘。");
	Q **tempnum = new Q *[A.row+1];
	Q ans;
#pragma omp parallel for
	Re(i, A.row)
	{
		tempnum[i] = new Q[B.colume + 1]; //里面本来就是零。
		Re(j, B.colume)
			Re(x, A.colume)
				tempnum[i][j] += A.num[i][x] * B.num[x][j]; 
	}
	Matrix ANS;
	ANS.clear();
	ANS.num = tempnum, ANS.row = A.row, ANS.colume = B.colume;
	return ANS;
}


void Matrix::swap(int a, int b)		
{
	if (a <= 0 || b <= 0 || a > row || b > colume)	debug("交换越界");
	if (a == b)return;
	Q *temp = new Q[colume+1];
	memcpy(temp, num[a], sizeof(Q)*(colume+1));
	memcpy(num[a], num[b], sizeof(Q)*(colume + 1));
	memcpy(num[b], temp, sizeof(Q)*(colume+1));
	delete[] temp; //我爱代码分析。
}
void Matrix::subtract(int a, int b, Q k) //b-=a*k
{
	if (a == b) debug("请不要自己减自己。in subtract().");
	if (k == 0)	return;		
	Re(i, colume)
		num[b][i] -= num[a][i] * k;
}
//五个循环... ...
Matrix Matrix::rref()const
{
	bool flag = 0;
	Matrix temp(*this);
	Re(i, temp.row-1) 
		RE(y, i, temp.colume)						//从左往右
		{
			RE(k, y, temp.row)
				if (!(temp[k][y] == 0))				//先从上往下找不为零的主元
				{
					flag = 1;							//找到了
					temp.swap(k, i);					//交换，现在k在第i行,也就是num[i][i]!=0
					RE(x, i + 1, row)
						if (!(temp[x][y] == 0))		//找到主元项不为零的行。
						{
							Q tempk = temp[x][y] / temp[i][y];
							temp.subtract(i, x, tempk);
						}
					cout << temp << endl;
					break;
				}
			if (flag){ flag = 0; break; } //如果没有找到。则继续在下一列找。
		}
	return temp;
}
//先求rref，再相乘。
Q Matrix::det()const
{
	if (row != colume)debug("不是方阵，不能计算行列式。");
	Matrix one = rref();
	Q ans = 1;
	Re(i, row)	ans *= one[i][i];
	return ans;
}