#define TEMP template<class T>
#include <iostream>
using namespace std;
#ifndef re
#define re(i,n) for(unsigned int i=0;i<n;i++)
#endif // !re(i,n)
#ifndef Re(i,n)
#define Re(i,n)		for(unsigned int i=1;i<=n;i++) //循环n次
#endif // !Re(i,n)

#define MAX 1000
TEMP
struct node
{
	unsigned int x, y;
	T data;
	node(unsigned int X=0,unsigned int Y=0, T object=0) :x(X), y(Y), data(object){}
	node<T>operator-(node<T> const & other)const
	{
		return node<T>(x, y, data - other.data);
	}
	node<T>operator+(node<T> const & other)const
	{
		return node<T>(x, y, data + other.data);
	}
	friend ostream& operator<<(ostream& out, node<T> const & other)
	{
		return out << "( " << other.x << ',' << other.y << " ) : " << other.data;
	}
};
TEMP 
void Swap(T &a, T &b)
{
	T temp = a; a = b; b = temp;
}

TEMP
class sparse
{
	node<T> matric[MAX];
	unsigned int colume, row, num;
public:
	sparse(){}
	bool cmp(int i, int j)const
	{
		return index(i) > index(j);
	}
	sparse(T **mat, unsigned int ROW, unsigned int COLUME) :row(ROW), colume(COLUME), num(0)
	{
		re(i, row)
			re(j, colume)
			if (mat[i][j] != T(0))
				matric[num++] = node<T>(j, i, mat[i][j]);
	}
	int index(unsigned int j)const
	{
		if (j >= num)
			throw"越界！";
		else return matric[j].y*colume + matric[j].x;
	}
	friend ostream& operator<<(ostream&out, sparse<T> const & other)
	{
		unsigned int i = 0, j = 0;
		re(i, other.row*other.colume)
		{
			if (j < other.num&&i == other.index(j))
				out << other.matric[j++].data << " ";
			else
				out << T(0) << ' ';
			if (i%other.colume == other.colume - 1)
				out << endl;
		}
		return out << endl;
	}
	friend sparse<T> operator+(sparse<T> const &a, sparse<T> const & b)
	{
		if (a.colume != b.colume || a.row != b.row)
			throw"size 不对！";
		sparse<T> ANS;
		ANS.row = a.row, ANS.colume = b.colume,ANS.num=0;
		int i = 0, j = 0;
		while (i < a.num&&j < b.num)
		{
			int m = a.index(i), n = b.index(j);
			if (m < n)
				ANS.matric[ANS.num++] = a.matric[i++];
			else if (m > n)
				ANS.matric[ANS.num++] = b.matric[j++];
			else if (a.matric[i].data + b.matric[j].data != T(0))
				ANS.matric[ANS.num++] = a.matric[i++] + b.matric[j++];
			else
				i++, j++;
		}
		while (i<a.num)
			ANS.matric[ANS.num++] = a.matric[i++];
		while (j< b.num)
			ANS.matric[ANS.num++] = b.matric[j++];
		return ANS;
	}
	void transpose()
	{
		re(i, num)
			Swap(matric[i].x, matric[i].y);
		Swap(row, colume);
		for (int i = num - 1; i > 0; i--)
			re(j,i)
			if (index(i)<index(j))
				Swap(matric[i], matric[j]);
	}
	void print()
	{
		re(i, num)
			cout << matric[i] << endl;
	}
};