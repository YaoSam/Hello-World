#include <iostream>
#include <mpi.h>
#pragma comment (lib,"mpi.lib")
using namespace std;
#define DEBUG
int main(int argc, char* argv[])
{
	MPI_Init(&argc, &argv);
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if (rank==1)
	{
#ifdef DEBUG
		FILE *err; //用来调用freopen_s，其实是没用的。
		freopen_s(&err, "C:\\Users\\Sam\\OneDrive\\C++\\Source\\Sam' C++\\Sam' C++\\in.txt", "r", stdin);
		freopen_s(&err, "C:\\Users\\Sam\\OneDrive\\C++\\Source\\Sam' C++\\Sam' C++\\out.txt", "w", stdout);
#endif


	} 
	else
	{



	}
	MPI_Finalize();
	return 0;
}