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
#include <winstring.h>
#include <fstream>
#include <sstream>
#include <locale>
using namespace std;

//#define DEBUG //����ȷ���Ƿ��ı������
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

	int Count[10000] = { 0 };					//����������
	wstring str;										//�������ַ�����Ŀ��Ӧ��
	wchar_t temp; 
	wifstream in("11-10.txt");
	if (!in) debug("�޷����ĵ�");
	locale loc(".936");								//�����ʽ�����... ...FXXK... ...
	wcout.imbue(loc);
	in.imbue(loc);
	while ((temp = in.get()) != WEOF)		//���ַ��Ľ�����ƽʱ��һ��... ...FXXK����ʵ��ֵΪ65535 .
	{
		if (str.find(temp) == wstring::npos)
		{
			str += temp;
			Count[str.length()-1]++;
		}
		else Count[str.find(temp)]++;	
	}
	Re(i, str.length())
		wcout << str[i - 1] << ": " << Count[i - 1] << '\t';
	//Just have fun!!!
#ifndef DEBUG 
	printf("\n");
	system("pause");	//�Ӹ��ϵ㡣
#endif // !DEBUG
	return 0;
}