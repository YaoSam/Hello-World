#pragma once
#include "MaxHeap.cpp"	//ע����cpp��
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
	//�б��׼����ֵ�ܶ�(value/weight)
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
//�����ʽ����ƷID:�� ��ֵ��? ����: ?
std::ostream &operator<<(std::ostream& out, object const & other);
//�����ʽ��ID vlaue weight
std::istream &operator>>(std::istream& in, object &other);

class BagState
{
	//�ֱ��ǹ��Ƶļ�ֵ�Ͻ磬ʣ��ռ䣬��ǰ�����ļ�ֵ
	double MaxValue, Value, RestRoom;
	unsigned int level;	//��¼��ǰ����������
	btree<bool>* Mylocation;		//��¼�������е�λ��
	//����Ϊ��̬������
	static btree<bool> tree; 	//��ռ�������¼�Ƿ񴢴�ĳ������
	static object *things;	//��¼�������塣
	static unsigned int ObjectNum;	//��������Ŀ
	static double Limit;		//��������
	//��̬�����ĳ�ʼ��������ʼ���������ࣩ�ĺ�������Ʒ��Ŀ��������С��������������顣
	static void intialize(unsigned int number, double limit, const object *thing);
	//�������㡣�ͷ��ڴ�
	static void clear();
	//����ʣ���ֵ
	double CounRestValue()const;
	//�������塣�����µı�����flag=1����롣flag=0���Թ���
	BagState insert(bool flag)const;
public:
	//flagΪ���򲻼���ʣ���ֵ������ʡ����������Ϊ�����������ô���Ĭ�Ϲ��캯����
	BagState(bool flag=0);
	//���ص�ǰ������ֵ
	double value()const{ return Value; }
	//�ж��Ƿ��Ѿ�װ��
	double isFull()const{ return RestRoom<0; }
	//�����������ȶ��е����ȼ�����������ѣ��б��׼�����ֵ�Ͻ�(MaxValue)
	bool operator>(BagState const & other)const
	{
		return MaxValue > other.MaxValue; 
	}
	friend BagState Solve(unsigned int n, double limit, object* thing);
	//�������״̬
	friend std::ostream& operator<<(std::ostream& out, BagState const & other);
};

//�ؼ�������ͨ���ýӿ�������������⡣
BagState Solve(unsigned int n, double limit, object* thing);

