#include <iostream>
using namespace std;
#define DEBUG
/*没什么好说的*/

inline void swap(long int *a,long int *b)
{
	long int sto = *a;
	*a = *b;
	*b = sto;
}
int sort(long int temp[], int N)
{
	for (int i = 1; i <=N; i++)
		for (int j = i; j > 1; j--)
			if (temp[j] < temp[j - 1])
				swap(temp + j, temp + j - 1);
	return 0;
}
int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	int N,X,Y,Z;	
	long Now=0,Max=0;
	long int A[21000], B[31000];
	cin >> N >> X >> Y >> Z;
	for (int i = 1; i <= N; i++)	cin>>A[i]>>B[i];
//	for (int i = 1; i <= N; i++)cout << A[i] << ' ' << B[i]<<endl;
	sort(A,N),sort(B,N);
//	for (int i = 1; i <= N; i++)cout << A[i] << ' ' << B[i] << endl;
	for (int i = 1,j=1; i <= N;)
		{
//			cout <<endl<< A[i] << ' ' << B[j];
			if (A[i] == B[j])
			{
				i++, j++;
				Now += Z-X;
			}
			else if (A[i] < B[j])
			{
				Now += Y-X;
				i++;
			}
			else 
			{
				Now += Z-Y;
				j++;
			}
//			cout<<' '<<Now+N*X;
			Max=Max>=Now?Max:Now;
		}
	cout << Max+N*X<< endl;
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}