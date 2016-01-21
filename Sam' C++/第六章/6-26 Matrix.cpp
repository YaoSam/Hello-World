#include <iostream>
#include <string>

using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=1;i<=n;i++)

/*����ע��*/
/*Sample Input:
5 3
1 2 3 4 5
6 7 8 9 0
9 8 7 6 5
*/
int transpose(int ***num, int r, int c)
{
	int **temp;	
	temp = new int *[c+ 1];
	Re(i, c)
	{
		temp[i] = new int[r + 1];
		Re(j, r) temp[i][j] = (*num)[j][i];
	}
	delete[] *num;
	*num=temp;
	return 0;
}

void print(int **num, int r, int c)
{
	Re(i, r)	
	{
		Re(j, c)
			cout <<'\t'<< num[i][j];
		cout << endl;
	}
}
int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif

	int row, colume;
#ifndef DEBUG
	cout << "���������Ĵ�С" << endl;
#endif
	cin >> row >> colume;
#ifndef DEBUG
	cout << "���������" << endl;
#endif
	int **num;
	num = new int *[row + 1];
	Re(i, row)num[i] = new int[colume+1];
	Re(i, row)
		Re(j, colume)
		//num[i][j] = i - j;
		cin >> num[i][j];
	cout<<"ת��ǰ"<<endl;
	print(num, row, colume);
	transpose(&num, row, colume);
	cout << "ת�ú�" << endl;
	print(num, colume, row);
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}