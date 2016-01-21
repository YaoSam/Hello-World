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
#include <time.h>
using namespace std;

//#define DEBUG //用来确定是否文本输出。
#ifndef re(i,n)
#define re(i,n) for(unsigned int i=0;i<n;i++)
#endif // !re(i,n)
#ifndef Re(i,n)
#define Re(i,n)		for(int i=1;i<=n;i++) //循环n次
#endif // !Re(i,n)

void debug(string warning)
{
	cerr << warning << endl;
	system("pause");
	exit(1);
}



template <class T>
class OrderedList
{
	T *List;
	unsigned int length;
	unsigned int size;
public:
	OrderedList(T const from[]=NULL, unsigned int length=0) :length(length), size(2*length)
	{
		if (from&&length)
		{
			List = new T[size];
			memmove(List, from, length*sizeof(T));
			//得闲再用快排吧。
			T temp;
			re(i, length-1)
				re(j, length-i-1)
				if (List[j] > List[j+1])
				{
					temp = List[j];
					List[j] = List[j+1];
					List[j+1] = temp;
				}
		}
	}
	OrderedList(const OrderedList<T> & other) :size(other.size), length(other.length)
	{
		List = new T[size];
		memcpy(List, other.List, size*sizeof(T));
	}
	OrderedList<T>& operator=(const OrderedList<T> &other)
	{
		if (&other == this)	return *this;
		length = other.length,
		size = other.size,
		List = new T[other.size];
		memcpy(List, other.List, size*sizeof(T));
		return *this;
	}
	~OrderedList()
	{
		delete[] List;
	}
	T operator[](unsigned int i)const //读取操作 不能更改。因为是有序表……
	{
		return List[i]; 
	}
	void del(unsigned int i) //直接覆盖
	{
		length--;
		if (i >= length) return;
		if (length)
			memcpy(List + i, List + i + 1, (length - i - 1)*sizeof(T));
		else
			delete[] List;
	}
	void checkMem()		//检查大小
	{
		if (length >= (size - 1))
		{
			T *tempList = new T[size * 2];
			if (tempList)
			{
				size *= 2;
				memcpy(tempList, List, size*sizeof(T));
				delete[] List;
				List = tempList;
			}
			else throw("内存不足");
		}
	}
	void insert(T const &object)
	{
		checkMem();
		re(i,length)
			if (List[i] >= object)
			{
				memmove(List + i + 1, List + i, sizeof(T)*(length - i));
				List[i] = object;
				length++;
				return;
			}
		List[length++] = object;
	}
	friend ostream& operator<<(ostream& out, OrderedList<T> &other)
	{
		re(i, other.length)
			out << other.List[i] << " ";
		return out << endl;
	}
	friend OrderedList<T> operator+(OrderedList<T>const  &a, OrderedList<T>const  & b)
	{
		T *temp;
		temp = new T[a.size + b.size];
		unsigned int i = 0, j = 0;
		//先两组一边比较一边插入。
		while (i < a.length&&j < b.length)                                               
		{
			if (a[i] >= b[j])
			{
				temp[i + j] = b[j];
				j++;
			}
			else
			{
				temp[i + j] = a[i];
				i++;
			}
		}
		//反正其中有一个没到尽头
		while (i < a.length)
		{
			temp[i + j] = a[i];
			i++;
		}
		while (j < b.length)
		{
			temp[i + j] = b[j];
			j++;
		}
		//构造return 如果直接调用构造函数会再排序一次……浪费
		OrderedList<T> ans;
		ans.List = temp;
		ans.length = a.length + b.length;
		ans.size = a.size + b.size;
		return ans;
	}
};




int main()
{
	srand(time(NULL));
#ifdef DEBUG
	FILE *err; //没用的指针... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	int a[1000];
	re(i, 100)
	{
		a[i] = rand() % 100;
		cout << a[i] << ' ';
	}
	cout << endl;
	OrderedList<int> one(a, 10);
	OrderedList<int> two(a + 10, 30);
	cout << one << endl;
	cout << two << endl;
	OrderedList<int> three = one + two;
	cout << three << endl;

#ifndef DEBUG //加个断点。
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}