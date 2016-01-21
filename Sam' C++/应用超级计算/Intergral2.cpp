#include <iostream>
#include <math.h>
#include <mpi.h>
#include <time.h>
#pragma comment (lib,"mpi.lib")
#define Re(i,n) for(int i=1;i<n;i++)
#define DEBUG
using namespace std;

double f(double x)
{
	return x*x;
}

double cal(int rank, int size, double a, double b, int n)
{
	double sum = 0;
	double left = a + ((b - a) / double(size))*double(rank);
	double delta = ((b - a) / double(n))*double(size);
	double right = left + (b - a) / double(size);
	for (int i = 1; left + double(i)*delta < right; i++)
		sum += f(left + double(i)*delta);
	return sum*delta;
}

double MPI_Intergral(double a, double b, int n,double func(double))
{
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Bcast(&a, 1, MPI_DOUBLE,0, MPI_COMM_WORLD);
	MPI_Bcast(&b, 1, MPI_DOUBLE,0, MPI_COMM_WORLD);
	MPI_Bcast(&n, 1, MPI_INT,0, MPI_COMM_WORLD);
	double sum = 0;
	sum = cal(rank, size, a, b, n);
	double totalsum=sum;
	MPI_Reduce(&sum, &totalsum,1, MPI_DOUBLE ,MPI_SUM,0, MPI_COMM_WORLD);
	if (rank == 0)
	{
		cout << totalsum << endl;
	}
	return 0;
}

int main(void)
{
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);	
	double a=0, b=0, n=0;
	if (rank == 0)
	{
#ifdef DEBUG
		FILE *err; //用来调用freopen_s，其实是没用的。
		freopen_s(&err, "C:\\Users\\Sam\\OneDrive\\C++\\Source\\Sam' C++\\Sam' C++\\in.txt", "r", stdin);
		freopen_s(&err, "C:\\Users\\Sam\\OneDrive\\C++\\Source\\Sam' C++\\Sam' C++\\out.txt", "w", stdout);
#endif
		cin >> a >> b >> n;
	}
	MPI_Intergral(a, b, n, f);
	MPI_Finalize();
	return 0;
}