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

//3. �������������ļ�f1.dat��f2.dat�����ʵ�����¹�����
//��1��	�Ӽ�������20���������ֱ��ŵ����������ļ��У�ÿ���ļ��з�10����������
//��2��	��f1.dat����10������Ȼ���ŵ�f2.dat�ļ�ԭ�����ݵĺ��棻
//��3��	��f2.dat�ж���20�������������ǰ���С�����˳���ŵ�f2.dat(������ԭ��������)��
//

//ð������
void mysort(int *num, int left, int right){
	int temp;
	for (int i = left; i < right; i++)
		for (int j = right; j > i;j--)
			if (num[j] < num[j - 1])
			{
				temp = num[j];
				num[j] = num[j - 1];
				num[j - 1] = temp;
			}
}

int main()//���Ǵ������ú���~
{
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	//(1)
	//�Ӽ�������20��������
	int *num=new int[100];
	cout << "������20������" << endl;
	Re(i, 20)cin >> num[i];
	//�ֱ��ŵ����������ļ��У�ÿ���ļ��з�10����������
	ofstream out;
	out.open("f1.dat");
	Re(i, 10)out << num[i] << endl;
	out.close();

	out.open("f2.dat");
	Re(i, 10)out << num[i + 10] << endl;
	out.close();
	delete[] num;

	//(2)
	num = new int[100];
	ifstream in;
	in.open("f1.dat");
	if (!in)debug("�޷����ļ�f1.dat");
	//	��f1.dat����10������
	Re(i, 10)in >> num[i];
	in.close();
	//Ȼ���ŵ�f2.dat�ļ�ԭ�����ݵĺ��棻
	out.open("f2.dat", ios_base::app);
	Re(i,10)out << num[i] << endl;
	out.close();
	delete[] num;
	//(3)
	num = new int[100];
	//��f2.dat�ж���20��������
	in.open("f2.dat");
	Re(i, 20)in >> num[i];
	in.close();
	//�����ǰ���С�����˳���ŵ�f2.dat(������ԭ��������)��
	mysort(num, 1, 20);
	out.open("f2.dat");
	Re(i, 20)out << num[i] << endl;
	out.close();
	delete[] num;
#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}