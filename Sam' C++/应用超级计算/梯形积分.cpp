#include <iostream>
#include <math.h>
#include <mpi.h>
#include <time.h>
#pragma comment (lib,"mpi.lib")
#define Re(i,n) for(int i=1;i<n;i++)
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

int main(void)
{
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	double a, b;
	int n;
	double totalsum;
	double sum = 0;
	if (rank == 0)
	{
		cin >> a >> b >> n;
		totalsum = 0;
		Re(i, size) //分别向各个线程传送。
			{
				MPI_Send(&a, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD);
				MPI_Send(&b, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD);
				MPI_Send(&n, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
			}
		sum = cal(0, size, a, b, n);
		MPI_Reduce(&totalsum, &sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
		cout << totalsum << endl;
	}
	else
	{
		MPI_Recv(&a, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		MPI_Recv(&b, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		MPI_Recv(&n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		sum = cal(rank, size, a, b, n);
		MPI_Reduce(&totalsum, &sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	}
	MPI_Finalize();
	return 0;
}