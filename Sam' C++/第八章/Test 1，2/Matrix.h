#pragma once
/**
*������������������������������+ +
*����������		�������ߩ��������ߩ� + +
*����������		��������������	�� ��
*����������		������������������ ++ + + +
*����������		 ������������������	��+
*����������		��������������	�� +
*����������		�����������ߡ�����
*����������		������������������ + +
*����������		��������������������
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
#include "Q.h"
#include <omp.h>
using namespace std;
#define  RE(i,j,n) for(int i=j;i<=n;i++) //��jѭ����n

class Matrix		//��̬�����ڴ�ľ���
{
	Q **num;
	int row, colume;
private:
	//����a��b���С�
	void swap(int a, int b);
	//���������b-=a*k					
	void subtract(int a, int b, Q k);
	//Warning:�����Ч�ʻ�ܵ͡�
	Q *operator[](int i)									{ return num[i]; }
	const Q *operator[](int i)const				{ return num[i]; }
	//�ͷ��ڴ档size���㡣
	void clear();									
public:
	Matrix();
	~Matrix()	{ clear(); }
	Matrix(int *N, int r, int c);
	Matrix(Matrix const &other);
	Matrix &operator=(Matrix const &other);
	bool operator==(Matrix const &other)const	{ return row == other.row&&colume == other.colume; } //ֻ�ǱȽ�size
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
	num = new Q *[r + 1];		//����r��ָ��
	Re(i, r)
	{
		num[i] = new Q[c + 1];		//����r ���ռ䡣
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
		memcpy(num[i], other.num[i], sizeof(Q)*(colume + 1)); //�����������������ˡ�
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
//Ŀǰ�������int�͵�����
istream& operator>>(istream &in, Matrix &other)
{
	other.clear();
	in >> other.row >> other.colume;
	other.num = new Q*[other.row + 1];
	int temp;//��ʱ��Ϊint��
	Re(i, other.row)
	{
		other.num[i] = new Q[other.colume + 1];
		Re(j, other.colume) in >> temp, other.num[i][j] = temp;
	}
	return in;
}

Matrix &Matrix::operator+=(Matrix const &other)
{
	if (!(*this == other))debug("����size��һ�£��޷���ӡ�from +=");
	Re(i, row)
		Re(j, colume)
			num[i][j] += other.num[i][j];
	return *this;
}
//������ˡ���openMP�Ż���
Matrix operator*(Matrix const &A, Matrix const &B)
{
	if (A.colume != B.row)debug("����ߴ粻ƥ�䣬�޷���ˡ�");
	Q **tempnum = new Q *[A.row+1];
	Q ans;
#pragma omp parallel for
	Re(i, A.row)
	{
		tempnum[i] = new Q[B.colume + 1]; //���汾�������㡣
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
	if (a <= 0 || b <= 0 || a > row || b > colume)	debug("����Խ��");
	if (a == b)return;
	Q *temp = new Q[colume+1];
	memcpy(temp, num[a], sizeof(Q)*(colume+1));
	memcpy(num[a], num[b], sizeof(Q)*(colume + 1));
	memcpy(num[b], temp, sizeof(Q)*(colume+1));
	delete[] temp; //�Ұ����������
}
void Matrix::subtract(int a, int b, Q k) //b-=a*k
{
	if (a == b) debug("�벻Ҫ�Լ����Լ���in subtract().");
	if (k == 0)	return;		
	Re(i, colume)
		num[b][i] -= num[a][i] * k;
}
//���ѭ��... ...
Matrix Matrix::rref()const
{
	bool flag = 0;
	Matrix temp(*this);
	Re(i, temp.row-1) 
		RE(y, i, temp.colume)						//��������
		{
			RE(k, y, temp.row)
				if (!(temp[k][y] == 0))				//�ȴ��������Ҳ�Ϊ�����Ԫ
				{
					flag = 1;							//�ҵ���
					temp.swap(k, i);					//����������k�ڵ�i��,Ҳ����num[i][i]!=0
					RE(x, i + 1, row)
						if (!(temp[x][y] == 0))		//�ҵ���Ԫ�Ϊ����С�
						{
							Q tempk = temp[x][y] / temp[i][y];
							temp.subtract(i, x, tempk);
						}
					cout << temp << endl;
					break;
				}
			if (flag){ flag = 0; break; } //���û���ҵ������������һ���ҡ�
		}
	return temp;
}
//����rref������ˡ�
Q Matrix::det()const
{
	if (row != colume)debug("���Ƿ��󣬲��ܼ�������ʽ��");
	Matrix one = rref();
	Q ans = 1;
	Re(i, row)	ans *= one[i][i];
	return ans;
}