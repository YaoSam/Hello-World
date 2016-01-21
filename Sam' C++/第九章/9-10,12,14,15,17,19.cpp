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
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

#define DEBUG //用来确定是否文本输出。
#define Re(i,n)		for(int i=0;i<n;i++) //循环n次
void debug(string warning)
{
	cout << warning << endl;
	system("pause");
	exit(1);
}
template<class T>
void out(T a[], int n)	//输出
{
	Re(x, n)									
		cout << a[x] << ' ';
	cout << endl;
}

template<class T>		void Swap(T &x, T &y) 
{
	T temp = x;
	x = y;
	y = temp;
}
//9-10
template<class T>		void insertSort(T a[],int n) 
{
	T temp;
	int j;
	Re(i,n)
	{
		j = i;
		temp = a[i];
		while (j>0&&temp<a[j-1])		//后移
			a[j--] = a[j-1];
		a[j] = temp;							//插入
		cout << temp << ": ";
		out(a, n);
	}
}
//9-12
template <class T>	void selectSort(T a[], int n) 
{
	Re(i, n - 1)
	{
		int leastIndex = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[leastIndex])
				leastIndex = j;
		Swap(a[i], a[leastIndex]);
		out(a, n);
	}
}
//9-14
template <class T>	void bubbleSort(T a[], int n) 
{
	int i = n - 1;
	while (i > 0)
	{
		int lastExchangeIndex = 0;
		Re(j, i)
			if (a[j + 1] < a[j])
				Swap(a[lastExchangeIndex = j], a[j + 1]);
		i = lastExchangeIndex;
		out(a, n);
	}
}
//9-15
template <class T>	void bubbleSort2(T a[], int n)
{
	int i = n - 1;
	while (i > 0)
	{
		int lastExchangeIndex = 0;
		Re(j, i)
			if (a[j + 1] > a[j]) //改变了比较的方法。
				Swap(a[lastExchangeIndex = j], a[j + 1]);
		i = lastExchangeIndex;
		out(a, n);
	}
}
//9-17
template <class T>	void find(T one, T a[],int n) 
{
	Re(i, n)
		if (a[i]==one)
		{
			cout <<"找到"<<one<<"，位置为："<< i << endl;
			return;
		}
	cout << "并没有找到" <<one<<endl;
}
//9-19
template <class T>	int halffind(T one, T a[], int left,int right)
{
	int mid = (left + right)/2;
	if (left <= right)
	{
		if (a[mid] == one)		return mid;
		else if (a[mid] > one) return halffind(one, a, left, mid - 1);
		else							return halffind(one, a, mid + 1, right);
	}
	return -1;
}



int main()//我是呆萌哒妹函数~
{
#ifdef DEBUG
	FILE *err; //没用的指针... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	int data1[20] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
	int data2[20] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
	int data3[20] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
	int data4[20] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
	int data5[20] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };

	cerr << "你好！" << endl;
	Sleep(1000);
	insertSort(data1, 20);
	cout << endl;
	selectSort(data2, 20);
	cout << endl;
	bubbleSort(data3, 20);
	cout << endl;
	bubbleSort2(data4, 20);
	cout << endl;
	int i;
	cout << "请输入你要查找的数字" << endl;
	while (cin>>i)
	{
		find(i,data5,20);		
		cout<<"折半查找的结果为："<<halffind(i,data3,0,20)<<endl;
	}
	cout << setw(10);
	Re(i, 10)
		cout<<i<<'\n';

#ifndef DEBUG //加个断点。
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}