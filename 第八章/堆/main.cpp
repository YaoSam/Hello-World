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
#include "Bag.h"
using namespace std;
///test to git
//#define DEBUG //����ȷ���Ƿ��ı������
#undef re
#define re(i,n) for(unsigned int i=0;i<n;i++)

int main()
{
	clock_t time1 = clock();
		srand(unsigned int(time(NULL)));
#ifdef DEBUG
		FILE *err; //û�õ�ָ��... ...
		freopen_s(&err, "in.txt", "r", stdin);
		freopen_s(&err, "out.txt", "w", stdout);
#endif
	try{
		unsigned int n = 0;
		double Limit = 0;
		//����
		cout << "������������Ŀ��"; cin >> n;
		cout << "�����뱳����С��"; cin >> Limit;
		object *thing = new object[n + 1];
		cout << "�����뱳����" << endl;
		re(i, n)
			cin >> thing[i];
		//����
		BagState bestSolution = Solve(n, Limit, thing);
		//���
		//cout << "����ı�����" << endl;
		//re(i, n)
		//	cout << thing[i];
		//Qsort(thing, 0, n - 1);
		//cout << "���������" << endl;
		//re(i, n)
		//	cout << thing[i];
		//cout << endl;
		cout << "The max sum_value is: " << endl << bestSolution.value() << endl;
		cout << "The optimum solution is :"<< endl<< bestSolution << endl;
		delete[] thing;
	}
	catch (char const * a){ cout << a << endl; }
	cout << "����ʱ��: " << clock() - time1 << endl;
#ifndef DEBUG //�Ӹ��ϵ㡣
		printf("\n");
		system("pause");
#endif // !DEBUG	
	return 0;
}



/*
20
10
1 6 2
2 3 2
3 5.5 6
4 4 5
5 6 6.5
1 6 2
2 3 2
3 5.5 6
4 4 5
5 6 6.5
1 6 2
2 3 2
3 5.5 6
4 4 5
5 6 6.5
1 6 2
2 3 2
3 5.5 6
4 4 5
5 6 6.5
1 6 2
2 3 2
3 5.5 6
4 4 5
5 6 6.5
1 6 2
2 3 2
3 5.5 6
4 4 5
5 6 6.5
1 6 2
2 3 2
3 5.5 6
4 4 5
5 6 6.5


*/