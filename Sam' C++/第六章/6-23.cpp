#include <iostream>
#include <string>

using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)
#define RE(n)			for(int I=0;I<n;I++)

/*����ע��*/
/*Sample Input:
8
1 2 3 4 5 6 7 8
*/

int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	int n = 8, score; 
	float sum = 0;
	cout << "������ѧ������" << endl;
	cin >> n;
	cout << "������" << n << "λѧ���ĳɼ�" << endl;
	Re(i, n)cin >> score,sum+=score;
	cout << "ƽ����Ϊ��" << sum / n;
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}