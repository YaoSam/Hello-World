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
#include <sstream>
using namespace std;

#define DEBUG //����ȷ���Ƿ��ı������
#define Re(i,n)		for(int i=1;i<=n;i++) //ѭ��n��
void debug(string warning)
{
	cerr << warning << endl;
	system("pause");
	exit(1);
}


int main()//���Ǵ������ú���~
{
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	string line,temp;
	ostringstream str(temp);
	ifstream in("11-9.txt");
	int i = 1;
	while(getline(in, line))
		str <<i++<<": "<< line << endl;
	in.close();
	
	ofstream output("11-9.txt");
	output<<str.str();
	output.close();
#ifndef DEBUG //�Ӹ��ϵ㡣
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}