#pragma once
#include "MaxHeap.cpp"	//注意是cpp啊
#include "BinaryTree.cpp"
#undef  re
#define re(i,n) for(unsigned int i=0;i<n;i++)
#undef  TEMP
#define TEMP template <class T>

TEMP
void Qsort(T a[], int left, int right)
{
	T mid = a[(left + right) / 2];
	int l = left, r = right;
	do
	{
		while (a[l] > mid)l++;
		while (a[r] < mid)r--;
		if (l <= r)
			Swap(a[l++], a[r--]);
	} while (l <= r);
	if (r > left)		Qsort(a, left, r);
	if (l < right)	Qsort(a, l, right);
	return;
}

struct object
{
	int ID;
	unsigned int num;
	double weight,value;
	object(unsigned int id = 0, double W = 0, double V = 0, unsigned int n = 1) :
		ID(id), weight(W), value(V),num(n){}
	//判别标准：价值密度(value/weight)
	bool operator>(object const & other)const
	{
		if (value*other.weight == other.value*weight)return value > other.value;
		return value*other.weight > other.value*weight;
	}
	object operator*(unsigned int n)
	{
		return object(ID, weight*n, value*n, num*n);
	}
};
//输出格式：物品ID:？ 价值：? 重量: ?
std::ostream &operator<<(std::ostream& out, object const & other);
//输入格式：ID vlaue weight
std::istream &operator>>(std::istream& in, object &other);

class BagState
{
	//分别是估计的价值上界，剩余空间，当前背包的价值
	double MaxValue, Value, RestRoom;
	unsigned int level;	//记录当前遍历的物体
	btree<bool>* Mylocation;		//记录其在树中的位置
	//以下为静态变量。
	static btree<bool> tree; 	//解空间树，记录是否储存某个物体
	static object *things;	//记录所有物体。
	static unsigned int ObjectNum;	//物体总数目
	static double Limit;		//背包容量
	//静态变量的初始函数。初始化背包（类）的函数：物品数目，背包大小，储存物体的数组。
	static void intialize(unsigned int number, double limit, const object *thing);
	//背包归零。释放内存
	static void clear();
	//计算剩余价值
	double CounRestValue()const;
	//遍历物体。生成新的背包。flag=1则放入。flag=0则略过。
	BagState insert(bool flag)const;
public:
	//flag为零则不计算剩余价值。用来省计算量。因为批量申请会调用大量默认构造函数。
	BagState(bool flag=0);
	//返回当前背包价值
	double value()const{ return Value; }
	//判断是否已经装满
	double isFull()const{ return RestRoom<0; }
	//代表其在优先队列的优先级，用来存入堆，判别标准：其价值上界(MaxValue)
	bool operator>(BagState const & other)const
	{
		return MaxValue > other.MaxValue; 
	}
	friend BagState Solve(unsigned int n, double limit, object* thing);
	//输出背包状态
	friend std::ostream& operator<<(std::ostream& out, BagState const & other);
};

//关键。就是通过该接口来解决背包问题。
BagState Solve(unsigned int n, double limit, object* thing);

