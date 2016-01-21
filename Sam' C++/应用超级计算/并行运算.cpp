
#include <mpi.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <conio.h>
#include <iostream>
using namespace std;
#pragma comment (lib, "mpi.lib")
void input(int myrank,int commsz,double *a,double *b,int *n)
{
	int dest;
	if(myrank==0)
	  {
		  printf_s("请输入a,b,n:");
		  scanf_s("%lf%lf%d",a,b,n);
		  for(dest=1;dest<commsz;dest++)
			{
				MPI_Send(a,1,MPI_DOUBLE,dest,0,MPI_COMM_WORLD);
				MPI_Send(b,1,MPI_DOUBLE,dest,0,MPI_COMM_WORLD);
				MPI_Send(n,1,MPI_INT,dest,0,MPI_COMM_WORLD);
			}
	  }
	else
	 {
		MPI_Recv(a,1,MPI_DOUBLE,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		MPI_Recv(b,1,MPI_DOUBLE,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		MPI_Recv(n,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
	 }
	return ;
}

void output(int myrank,int commsz,int n,double inv)
{
	if(myrank!=0)
		{
			MPI_Send(&inv,1,MPI_DOUBLE,0,0,MPI_COMM_WORLD);
		}
	else
		{
			double totalinv=inv;
			int dest;
			for(dest=1;dest<commsz;dest++)
				{
					MPI_Recv(&inv,1,MPI_DOUBLE,dest,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
					totalinv+=inv;
				}
			printf("分成%d分的情况下面积约等于%.6lf\n",n,totalinv);
			//system("pause");
		}
}

inline double f(double x)
{
	return x*x*x;
}

double trap(double a,double b,int n,double h)
{
	double appr=(f(a)+f(b))/2;
	for(int i=1;i<n;i++)
		{
			double x=a+i*h;
			appr+=f(x);
		}
	appr*=h;
	return appr;
}

double calc(int myrank,int commsz,double a,double b,int n)
{
	double h=(b-a)/n;
	double localn=n/commsz;
	double locala=a+myrank*localn*h;
	double localb=locala+localn*h;
	return trap(locala,localb,localn,h);
}

int main(int argc, char* argv[])
{
	MPI_Init(&argc, &argv);
	int myrank,mysize;
	MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
	MPI_Comm_size(MPI_COMM_WORLD,&mysize);
	double a,b;
	int n;
	input(myrank,mysize,&a,&b,&n);
	double inv=calc(myrank,mysize,a,b,n);
	output(myrank,mysize,n,inv);
	MPI_Finalize();
	
	return 0;
}