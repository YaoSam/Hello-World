#include <iostream>
#include<time.h>
#define re(i,n) for(int i=0;i<n;i++)
using namespace std;

int main()
{
	srand(time(NULL));
	int A[1000];
	re(i, 100)
	{
		A[i] = rand() % 1000;
		cout << A[i] << ' ';
	}
	cout << endl;
	int m = A[0], n = A[0];
	re(i, 100)
	{
		if (m < A[i]) m = A[i];
		if (n < A[i] && A[i] < m) n = A[i];
	}
	cout << m << ' ' << n << endl;
	system("pause");
	return 0;
}