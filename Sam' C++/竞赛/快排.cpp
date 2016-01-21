#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)
#define RE(n)			for(int I=0;I<n;I++)

/*����ע��*/
/*Sample Input:

*/
int a[1000];
int i = 15;
void swap(int &AAA, int &b)
{
	int sto = AAA;
	AAA = b;
	b = sto;
}

int COUNT = 0;
void quicksort(int *num, int left,int right)
{
	int mid = num[(left + right) / 2];
	int i = left, j = right;
	while (i<=j)
	{
		while (num[i] <mid)i++;
		while (num[j] > mid)j--;
		if (i <= j)swap(num[i++], num[j--]);
	}
	if (left <j )			quicksort(num, left, j);
	if (right >i)			quicksort(num, i, right);
	return;
}
int cmp(const void *AA, const void *b)
{
	return *(int *)AA - *(int *)b;
}
int cmp1(int AA, int BB)
{
	return AA < BB;
}
int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	Re(j, i)cin >> a[j];
	//quicksort(a, 0, i-1);
	//qsort(a,i,sizeof(a[0]),cmp);
	sort(a,a+i,cmp1);
	Re(j, i)	cout << a[j] << endl;
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}