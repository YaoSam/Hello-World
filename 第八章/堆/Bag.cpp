#pragma once
#include "Bag.h"
#undef  re
#define re(i,n) for(unsigned int i=0;i<n;i++)

std::ostream &operator<<(std::ostream& out, object const & other)
{
	re(i,other.num)
		out << "ID��" << other.ID << " " 
		<< "��ֵ��" << other.value/(other.num) << " " 
		<< "����: " << other.weight/(other.num)<<std::endl
		/*<< " ƽ����ֵ�� " << other.value / other.weight*/;
	return out;
}
std::istream &operator>>(std::istream& in, object &other)
{
	return in >> other.ID >> other.value >> other.weight;
}
/************************************************************************/
/* ������BagState����                                                                     */
/************************************************************************/
object* BagState::things = NULL;
unsigned int BagState::ObjectNum = 0;
double BagState::Limit = 0;
btree<bool> BagState::tree;

void BagState::intialize(unsigned int number, double limit, const object *thing)
{
	things = new object[number + 1];
	memcpy(things, thing, sizeof(object)*number);
	//���˿��š�Ҳ����������Ķ��š���ࡣ���ſ���ֱ�ӵ��ö����Ż���
	Qsort(things, 0, number - 1);
	//heapSort(things, number);
	//���ºϲ�����
	object temp; bool flag = 0; 
	unsigned int i = 0, j = 0, k = 0;
	int  n = 0;
	ObjectNum = 0;
	while (j<number)
	{
		//������ͬ����,i��¼��㣬j��¼�յ�
		for (i = j, temp = things[j]; j < number; j++)
			if (things[j].value!= temp.value || things[j].weight != temp.weight)
				break;
		//�ϲ�n����ͬ���塣
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
	//�ֱ����ʣ���ֵ��ʣ��ռ�
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
	BagState ans=*this;//this������һ������
	if (flag&&level < ObjectNum)
	{
		// �����в�������,����״̬
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
		throw "������δ��ʼ����";
	if (flag)
		MaxValue = CounRestValue();
}

std::ostream& operator<<(std::ostream& out, BagState const & other)
{
	btree<bool> *temp = other.Mylocation;
	re(i, BagState::ObjectNum)
	{
		//�������ϻ���ͨ���Ӽ�������⡣
		if (temp->data)
			out << BagState::things[BagState::ObjectNum - i - 1];
		temp = temp->father;
	}
	return out;
}

BagState Solve(unsigned int n, double limit, object *thing)
{
	//������ʼ��
	BagState::clear();
	BagState::intialize(n, limit, thing);
	BagState Bag(1), tempBag;
	MaxHeap<BagState> State_Heap;
	double CurrentMaxValue = 0;
	//����
	State_Heap.push(Bag);
	while (Bag.level < BagState::ObjectNum)
	{
		//ȡ�����Žڵ�
		Bag = State_Heap.pop();
		CurrentMaxValue = CurrentMaxValue < Bag.Value ? Bag.Value : CurrentMaxValue;
		//��չ�������������
		if (!(tempBag=Bag.insert(1)).isFull()) //����Խ���򲻲��롣
			State_Heap.push(tempBag);
		if ((tempBag=Bag.insert(0)).MaxValue >= CurrentMaxValue) //���ٶѵĴ�С��Ӱ��ǳ�С
			State_Heap.push(tempBag);
	}
	return Bag;
}
