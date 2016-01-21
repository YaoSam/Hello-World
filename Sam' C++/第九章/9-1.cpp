/*
*
*������	 ��������  ������         ����+ +
*����  ���������������ߩ��������������ߩ� + +
*����  ��������������������       �� ��
*����  ������������������������  �� ++ + + +
*����  ����		   ��  ��������������  ��+
*����  ������������������������ �� +
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
using namespace std;

#define DEBUG //����ȷ���Ƿ��ı������
#define Re(i,n)		for(int i=0;i<n;i++) //ѭ��n��
/*Sample Input*/
/*
5
1 2 6 24 120
*/
/*Sample Output
�����뱾������
������ÿ���˵ĳɼ���
ƽ���ɼ�Ϊ��30.6
*/
template<class T>
class MyArray
{
	T *Array;
	int size;
public:
	MyArray(int SIZE = 100); 
	~MyArray(){ delete[] Array; }
	MyArray(MyArray<T> const &other)	{ size = other.size; Array = new T[size]; memcpy(Array, other.Array, size*sizeof(T)); }
	MyArray<T> &operator=( const MyArray<T> &other);
	T &operator[]( int num);
	const T &operator[](int num)const;
	friend ostream &operator<<(ostream &out, MyArray<T> const &This);
	MyArray<T>& Reset(int newsize);
};

template<class T>
MyArray<T>::MyArray(int SIZE=100) : size(SIZE)	
{
	if (size <= 0)
	{ 
		cout << "����" << endl; 
		system("pause");
		exit(1); 
	}		
	Array = new T[size]; 
	if (Array == NULL)
	{
		cout << "�ڴ�����ʧ�ܡ�" << endl;
		system("pause");
		exit(2);
	}
}
template<class T>
MyArray<T> &MyArray<T>::operator=( const MyArray<T> &other)
{
	delete[] Array;		
	size = other.size;
	Array = new T[other.size]; 
	memcpy(Array, other.Array,other.size*sizeof(T));
}
template<class T>
T &MyArray<T>::operator[](int num)
{
	if (num < 0 || num >= size)
	{	 
		cout << "��Խ����~" << endl;
		system("pause"); 
		exit(1);
	}
	return Array[num];
}
template<class T>
const T &MyArray<T>::operator[](int num)const
{
	if (num < 0 || num >= size)
	{
		cout << "��Խ����~" << endl;
		system("pause");
		exit(1);
	}
	return Array[num];
}
template<class T>
MyArray<T>& MyArray<T>::Reset(int newsize)
{
	if (size == newsize)return *this;
	T tempArray = Array;
	Array = new[newsize] T;
	if(size>newsize)	memcpy(tempArray, Array, newsize*sizeof(T));
	else memcpy(tempArray, Array, size*sizeof(T));
	delete[] Array;
	Array = tempArray;
	reutnr *this;
}

int main()//���Ǵ������ú���~
{
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	int n;
	cout << "�����뱾������" << endl;
	cin >> n;
	double sum=0;
	MyArray<double>grade(n);
	cout << "������ÿ���˵ĳɼ���" << endl;
	Re(i, n)
		{
			cin >> grade[i];
			sum += grade[i];
		}
	cout << "ƽ���ɼ�Ϊ��" << sum / n << endl;

#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}