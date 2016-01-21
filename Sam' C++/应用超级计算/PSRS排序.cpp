#include <iostream>
#include <mpi.h>
#include <algorithm>
#pragma comment (lib,"mpi.lib")
using namespace std;
#define DEBUG
#define Re(i,n) for(int i=0;i<n;i++)
#define MAX 1000
/*Sample Input
64
4 3 2 1 34 2 54 12 89 9 7 578 83 310 4 5 6 4 3544 43 458 957 67 75 3 2 4 45 5 6 7 7 45 3 2 3 4 543 3
123 32 43 545 656 5676 76 878 798 21 34 123 34 455 999 83 12 32
15 540 125 25 65 769 23 654 657 8867 435 638 246 235 2346 234 1230 100 101 120 191 192
193 1923 42 12309 */


int comp(int a, int b)
{
	return a < b;
}
int main(int argc, char* argv[])
{
	MPI_Init(&argc, &argv);
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	int Recnum[MAX] = { 0 };
	int num[MAX] = { 0 };
	int flag[MAX] = { 0 };
	int Recflag[MAX] = { 0 };
	int n;
	int sum_j;
	int debug = 0;
	if (rank == 0)
	{
#ifdef DEBUG
		FILE *err; //用来调用freopen_s，其实是没用的。
		freopen_s(&err, "C:\\Users\\Sam\\OneDrive\\C++\\Source\\Sam' C++\\Sam' C++\\in.txt", "r", stdin);
		freopen_s(&err, "C:\\Users\\Sam\\OneDrive\\C++\\Source\\Sam' C++\\Sam' C++\\out.txt", "w", stdout);
#endif
		cin >> n;
		Re(i, n)	cin >> num[i];
		cout << "原数列：";
		Re(i, n)	cout << num[i] << ' ';
		cout << endl;
	}
	cout << rank << ' ' << debug++ << endl;
	MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
	cout << rank << ' ' << debug++ << endl;
	MPI_Scatter(num, n / size, MPI_INT, Recnum, n / size, MPI_INT, 0, MPI_COMM_WORLD);
	cout << rank << ' ' << debug++ << endl;
	sort(Recnum, Recnum + n / size, comp);
	cout << rank << ' ' << debug++ << endl;
	Re(i, size)			//分别从Reccum收集size个数。
		MPI_Gather(Recnum + i*size, 1, MPI_INT, flag, 1, MPI_INT, 0, MPI_COMM_WORLD);
	cout << rank << ' ' << debug++ << endl;
	if (rank == 0)
	{
		sort(flag, flag + size*size, comp);
	}
	cout << rank << ' ' << debug++ << endl;
	Re(i, size)          //将flag分发
		MPI_Scatter(flag, 1, MPI_INT, Recflag, 1, MPI_INT, 0, MPI_COMM_WORLD);
	int j=0, lastj=0;
	cout << rank << ' ' << debug++ << endl;
	Re(i, size)
	{
		while (Recnum[j] < flag[i])j++; 
		int temp = j-lastj;
		MPI_Gather(Recnum, j - lastj, MPI_INT, num, j - lastj, MPI_INT, i, MPI_COMM_WORLD);
		cout << rank << ' ' << debug++ << endl;
		MPI_Reduce(&temp, &sum_j, 1, MPI_INT, MPI_SUM, i, MPI_COMM_WORLD);
		cout << rank << ' ' << debug++ << endl;
		lastj = j;
	}
	cout <<"汇总的排序数目："<< sum_j << endl;
	sort(num, num + sum_j, comp);
	cout << rank << ' ' << debug++ << endl;
	MPI_Gather(Recnum, sum_j, MPI_INT, num, sum_j, MPI_INT, 0, MPI_COMM_WORLD);
	cout << rank << ' ' << debug++ << endl;
	if (rank == 0)
		Re(i, n)
			cout << num[i] << ' ';
	MPI_Finalize();
	return 0;
}