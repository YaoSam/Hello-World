/*
*
*������	 ��������   ������		 ����+ +
*����  ���������������ߩ��������������ߩ� + +
*����  ��������������������       �� ��
*����  ������������������������ �� ++ + + +
*����  ����		   ��  ��������������  ��+
*����  �������������������������� +
*����  ����������������   �ߡ���  ��
*����  �������������������������� + +
*����  ���������������������� ������
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
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

//#define DEBUG //����ȷ���Ƿ��ı������
#ifndef re(i,n)
#define re(i,n) for(int i=0;i<n;i++)
#endif // !re(i,n)
#ifndef Re(i,n)
#define Re(i,n)		for(int i=1;i<=n;i++) //ѭ��n��
#endif // !Re(i,n)


void debug(string warning)
{
	cerr << warning << endl;
	system("pause");
	exit(1);
}
#define MAX 1000
template <class T>
class Seqlist
{
private:
	T list[MAX];
	int length;
public:
	Seqlist(T a[] = NULL, int n = -1): length(n)
	{
		if(a&&n>=0)
			memcpy(list, a, sizeof(T)*n);
	}
	void print()
	{
		re(i, length)
			cout << list[i] << " ";
		cout << endl;
	}
	void insert(T const &num, int location)
	{
		length++;
		if (length >= MAX)
			throw("���");
		memmove(list + location+1, list + location, sizeof(T)*(length - location + 1));
		list[location] = num;
	}
	int search(T const &num)
	{
		re(i, length)
			if (list[i] == num)
				return i;
		return -1; //�Ҳ�����
	}
	T &operator[](int i)
	{
		if (i >= length || i < 0)
			throw"Խ��";
		return list[i];
	}
	T operator[](int i)const 
	{
		if (i >= length || i < 0)
			throw"Խ��";
		return list[i];
	}
	int Length()const
	{
		return length;
	}
	~Seqlist(){}
};
template <class T>
void Swap(T &a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
int pi, xi;
void move(Seqlist<int> &aList)
{
	int left = 1, right = aList.Length()-1;
	while (left < right)
	{
		while (aList[left] <= aList[0]&&left<right)		left++;
		while (aList[right] >= aList[0]&&left<right)	right--;
		if (left < right)
			Swap(aList[left++], aList[right--]);
	}
	Swap(aList[left-1], aList[0]);
}

int search(Seqlist<int> const &aList, int num)
{
	int length = aList.Length();
	re(i, length)
		if (aList[i] == num)
			return (pi=i)+1;
	return length;
}

int search2(Seqlist<int>const &aList, int num)
{
	if (num == aList[0])
		return (pi = 0)+1;
	if (num>aList[0])
		return search(aList, num);
	int length = aList.Length();
	re(i,length)
		if (aList[length - i] == num)
		{
			pi = length - i;
			return i+1; 
		}
}


int main()
{
	srand(time(NULL));
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	int a[1000];
	re(i, 100)
		a[i] = rand() % 40+1;
	re(i, 100)
		cout << a[i] << " ";
	cout << endl;
	Seqlist<int> one(a, 15);
	one.print();
	one.insert(12, 2);
	one.print();
	move(one);
	one.print();
	int i=0;
	while (cin >> i)
		cout << search(one,i) << endl;
#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}