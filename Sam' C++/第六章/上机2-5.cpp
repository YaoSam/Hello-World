#include <iostream>
#include <string>

using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)
#define RE(n)			for(int i=0;i<n;i++)

/*����ע��
5. ��5��ѧ����ÿ��ѧ�������ݰ���ѧ�š����������ſγɼ����Ӽ�������5��ѧ�������ݣ�Ҫ����㲢�����
��1��ÿ��ѧ�����ſε��ܳɼ�
��2�����ſε�ÿ�ſε�ƽ���ɼ���
*/
/*Sample Input:
SamYao 14336238 100 99 98.9
BobYao 14336236 100.33 100 100.3
HalloWorld  12345678 60 70 80.3
*/
class stu{
	int id;
	string name;
	float score[3];
public:
	stu()
	{
		cout << "������ѧ����������ѧ�ţ�����3�ſ�Ŀ�ĳɼ���"<<endl;
		cin >> name>>id;
		Re(i, 3)cin >> score[i];
	}
	float sum()
	{
		float Sum = 0;
		Re(i, 3)Sum += score[i];
		return Sum;
	}
};
int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	stu arr[3];
	Re(i, 3)cout << "�ܳɼ�Ϊ��" << arr[i].sum() << endl;
	Re(i, 3)cout << "ƽ���ɼ�Ϊ" << arr[i].sum() / 3<<endl;
		
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}