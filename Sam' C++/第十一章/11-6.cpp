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
#define Re(i,n)		for(int i=0;i<n;i++) //ѭ��n��
void debug(string warning)
{
	cerr << warning << endl;
	system("pause");
	exit(1);
}

struct dog{
	int age, weight;
};



int main()//���Ǵ������ú���~
{
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	dog dog1 = { 5, 10 };
	//�ı��������
	ofstream out;
	out.open("11-6.txt");
	out << dog1.age << ' ' << dog1.weight << endl;
	out.close();

	ifstream in;
	in.open("11-6.txt");
	if (!in)debug("�޷������ĵ�11-6.txt");
	dog dog2;
	in >> dog2.age >> dog2.weight;
	in.close();
	
	cout << "dog2��" << dog2.age << ' ' << dog2.weight << endl;
	//�����ƴ���
	out.open("11-6.txt", ios_base::binary);
	out.write(reinterpret_cast<char *>(&dog1), sizeof(dog));
	out.close();

	in.open("11-6.txt", ios_base::binary);
	if (!in)debug("�޷������ĵ�11-6.txt");
	dog2.age = 123;
	in.read(reinterpret_cast<char *>(&dog2), sizeof(dog));
	
	cout << "dog2��" << dog2.age << ' ' << dog2.weight << endl;


#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}