#pragma once
#include "Bag.h"
#undef  re
#define re(i,n) for(unsigned int i=0;i<n;i++)

std::ostream &operator<<(std::ostream& out, object const & other)
{
	re(i,other.num)
		out << "ID：" << other.ID << " " 
		<< "价值：" << other.value/(other.num) << " " 
		<< "重量: " << other.weight/(other.num)<<std::endl
		/*<< " 平均价值： " << other.value / other.weight*/;
	return out;
}
std::istream &operator>>(std::istream& in, object &other)
{
	return in >> other.ID >> other.value >> other.weight;
}
/************************************************************************/
/* 下面是BagState部分                                                                     */
/************************************************************************/
object* BagState::things = NULL;
unsigned int BagState::ObjectNum = 0;
double BagState::Limit = 0;
btree<bool> BagState::tree;

void BagState::intialize(unsigned int number, double limit, const object *thing)
{
	things = new object[number + 1];
	memcpy(things, thing, sizeof(object)*number);
	//用了快排。也可以用下面的堆排。差不多。堆排可以直接调用堆来优化。
	Qsort(things, 0, number - 1);
	//heapSort(things, number);
	//以下合并物体
	object temp; bool flag = 0; 
	unsigned int i = 0, j = 0, k = 0;
	int  n = 0;
	ObjectNum = 0;
	while (j<number)
	{
		//查找相同物体,i记录起点，j记录终点
		for (i = j, temp = things[j]; j < number; j++)
			if (things[j].value!= temp.value || things[j].weight != temp.weight)
				break;
		//合并n个相同物体。
		for (k = 0, n = j - i; (1 << k) <= n;  n -= (1 << k),k++)
			things[ObjectNum++] = (things[i] * (1 << k));
		if (n > 0)things[ObjectNum++] = things[i] * n;
	}
	Limit = limit;
	return;
}

void BagState::clear()
{
	if(things)	delete[] things;
	tree = btree<bool>();
	things = NULL;
	ObjectNum = 0;
	Limit = 0;
}

double BagState::CounRestValue()const
{
	if (level >= ObjectNum)	return Value;
	//分别代表剩余价值，剩余空间
	double restValue = 0, room = RestRoom;
	unsigned int i = level;
	while (i < ObjectNum&&room >= things[i].weight)
	{
		restValue += things[i].value;
		room -= things[i].weight;
		i++;
	}
	if (i == ObjectNum) return restValue;
	return restValue + things[i].value / things[i].weight*room;
}
BagState BagState::insert(bool flag)const
{
	BagState ans=*this;//this就是上一个物体
	if (flag&&level < ObjectNum)
	{
		// 向树中插入物体,更新状态
		ans.Mylocation = new btree<bool>(1, Mylocation);
		Mylocation->left = ans.Mylocation;
		ans.Value += things[level].value;
		ans.RestRoom -= things[level].weight;
	}
	else 
	{
		ans.Mylocation = new btree<bool>(0, Mylocation);
		Mylocation->right = ans.Mylocation; 
	}
	ans.level++;
	ans.MaxValue = Value+CounRestValue();
	return ans;
}

BagState::BagState(bool flag) :
Value(0),
RestRoom(Limit),
level(0),
MaxValue(0),
Mylocation(&tree)
{
	if (things == NULL)
		throw "背包尚未初始化！";
	if (flag)
		MaxValue = CounRestValue();
}

std::ostream& operator<<(std::ostream& out, BagState const & other)
{
	btree<bool> *temp = other.Mylocation;
	re(i, BagState::ObjectNum)
	{
		//不断向上回溯通过子集树输出解。
		if (temp->data)
			out << BagState::things[BagState::ObjectNum - i - 1];
		temp = temp->father;
	}
	return out;
}

BagState Solve(unsigned int n, double limit, object *thing)
{
	//背包初始化
	BagState::clear();
	BagState::intialize(n, limit, thing);
	BagState Bag(1), tempBag;
	MaxHeap<BagState> State_Heap;
	double CurrentMaxValue = 0;
	//运算
	State_Heap.push(Bag);
	while (Bag.level < BagState::ObjectNum)
	{
		//取出最优节点
		Bag = State_Heap.pop();
		CurrentMaxValue = CurrentMaxValue < Bag.Value ? Bag.Value : CurrentMaxValue;
		//拓展插入两种情况。
		if (!(tempBag=Bag.insert(1)).isFull()) //容量越界则不插入。
			State_Heap.push(tempBag);
		if ((tempBag=Bag.insert(0)).MaxValue >= CurrentMaxValue) //减少堆的大小，影响非常小
			State_Heap.push(tempBag);
	}
	return Bag;
}
