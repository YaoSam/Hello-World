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
#include <fstream>
using namespace std;

//#define DEBUG //����ȷ���Ƿ��ı������
#define Re(i,n)		for(int i=1;i<=n;i++) //ѭ��n��
void debug(string warning)
{
	cerr << warning << endl;
	system("pause");
	exit(1);
}

//4. ���ʵ�����¹��ܣ�
//��1��	��ְ������С�����˳��5��Ա�������ݣ��������롢���������䡢���ʣ�����������ļ��б��档
//��2��	�Ӽ�����������Ա�������ݣ�ְ���Ŵ������е�ְ���ţ������ӵ��ļ���ĩβ��
//��3��	����ļ���ȫ��ְ�������ݡ�
//��4��	�Ӽ�������һ�����룬���ļ��в������޴�ְ���ţ���������ʾ��ְ���ǵڼ���ְ�����Լ���ְ����ȫ�����ݡ���û�У���������޴��ˡ������Է�����β�ѯ�����������ҵ�ְ����Ϊ0���ͽ�����ѯ��


//��һ���е�ģ������
template <class T>
void myswap(T &a, T &b){
	T temp = a;
	a = b;
	b = temp;
	return;
}
template <class T>
void mysort(T *array, int left, int right)//ð��
{
	for (int i = left; i < right; i++)
		for (int j = right; j > i; j--)
			if (!(array[j] > array[j - 1]))
				myswap(array[j], array[j - 1]);
}

//���������롢���������䡢���ʣ�
struct employee{
	int num;
	string name;
	int age;
	int wage;
};
//���������õ�
bool operator>(employee const &a, employee const &b){ return a.num > b.num; }
//�������������
ostream &operator<<(ostream &out, const employee &other)
{
	return out << other.name << ' ' << other.num << ' ' << other.age << ' ' << other.wage << endl;
}
istream &operator>>(istream &in, employee &other)
{
	return in>> other.name>> other.num  >> other.age >> other.wage;
}


int main()//���Ǵ������ú���~
{
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	//(1)
	employee many[10] = { { 15, "Ҧ쿲�", 20, 1000 }, { 3, "Ҧ����", 20, 2000 }, { 2, "SamYao", 18, 1000 }, { 10, "BobYao", 20, 12312 }, {5,"������",30,1233} };
	//��С�����˳��
	mysort(many, 0, 4);
	//����������ļ��б��档
	ofstream out("employee.dat");
	Re(i, 5)out << many[i - 1];
	out.close();
	memset(many, 0, sizeof(many));

	//(2)
	cout << "����������Ա��������" << endl;
	//�Ӽ�����������Ա��������
	Re(i, 2)cin >> many[i];
	//���ӵ��ļ���ĩβ��
	out.open("employee.dat", ios_base::app);
	Re(i, 2)out << many[i];
	out.close();
	memset(many, 0, sizeof(many));

	//(3)
	ifstream in("employee.dat");
	//����ļ���ȫ��ְ�������ݡ�
	Re(i, 7)in >> many[i],cout<<many[i];
	in.close();
	
	//(4)
	int num;
	bool flag = 0;
	cout << "��������ҵ�Ա�����룺" << endl;
	while (cin >> num)
	{
		Re(i, 7)
			if (many[i].num == num)
			{
				cout << "�ҵ�Ա����" << many[i];
				flag = 1;
				break;
			}
		if(!flag)cout << "�޷��ҵ�Ա����" << endl;
		flag = 0;
	}

#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}