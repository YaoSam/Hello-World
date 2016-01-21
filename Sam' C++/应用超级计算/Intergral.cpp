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

double cal(int rank,int size,double a, double b,int n)
{
	double sum=0;
	double left = a + ((b - a) / double(size))*double(rank);
	double delta =  ((b-a) / double(n))*double(size);
	double right = left + (b - a) / double(size);
	for (int i = 1; left+double(i)*delta<right; i++)
		sum += f(left + double(i)*delta);
	return sum*delta;
}

double MPI_Intergral(double a, double b, double *func(double))
{
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	int n;
	double sum = 0;
	if (rank == 0)
	{
#ifdef DEBUG
		FILE *err; //用来调用freopen_s，其实是没用的。
		freopen_s(&err, "C:\\Users\\Sam\\OneDrive\\C++\\Source\\Sam' C++\\Sam' C++\\in.txt", "r", stdin);
		freopen_s(&err, "C:\\Users\\Sam\\OneDrive\\C++\\Source\\Sam' C++\\Sam' C++\\out.txt", "w", stdout);
#endif
		double totalsum;
		totalsum = 0;
			Re(i, size) //分别向各个线程传送。
			{
				MPI_Send(&a, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD);
				MPI_Send(&b, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD);
				MPI_Send(&n, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
			}
			Re(i, size)
			{
				MPI_Recv(&sum, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				totalsum += sum;
			}
			totalsum += cal(0, size, a, b, n);
			cout << totalsum << endl;
	}
	else
	{
				MPI_Recv(&a, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				MPI_Recv(&b, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				MPI_Recv(&n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				sum = cal(rank, size, a, b, n);
				MPI_Send(&sum, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
	}

}

int main(void)
{
	MPI_Init(NULL, NULL);
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	double a, b;
	int n;
	int flag=1;
	double sum = 0;
	if (rank == 0)
	{
#ifdef DEBUG
			FILE *err; //用来调用freopen_s，其实是没用的。
			freopen_s(&err, "C:\\Users\\Sam\\OneDrive\\C++\\Source\\Sam' C++\\Sam' C++\\in.txt", "r", stdin);
			freopen_s(&err, "C:\\Users\\Sam\\OneDrive\\C++\\Source\\Sam' C++\\Sam' C++\\out.txt", "w", stdout);
#endif
		double totalsum;
		double time1, time2;
		time1 = (double)clock() / CLOCKS_PER_SEC;
		while(cin >> a >> b >> n)
		{		

			totalsum = 0;
			Re(i,size) //分别向各个线程传送。
			{
				MPI_Send(&flag, 1, MPI_INT, i, 0, MPI_COMM_WORLD); 
				MPI_Send(&a, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD);
				MPI_Send(&b, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD);
				MPI_Send(&n, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
			}
			Re(i,size)
			{
				MPI_Recv(&sum, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				totalsum += sum;	
			}
			totalsum += cal(0, size, a, b, n);
			cout << totalsum << endl;
		}
		time2 = (double)clock() / CLOCKS_PER_SEC;
		cout <<size<<" process's running time is : "<< time2 - time1 << endl;
		flag = 0;
		Re(i,size)
			MPI_Send(&flag, 1, MPI_INT, i, 0, MPI_COMM_WORLD);	
	}
	else
	{
		while (flag)
		{	
			MPI_Recv(&flag, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			while (flag)			
			{
				MPI_Recv(&a, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				MPI_Recv(&b, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				MPI_Recv(&n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				sum = cal(rank, size, a, b, n);
				MPI_Send(&sum, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
			}
		}
	}
	MPI_Finalize();
	return 0;
}