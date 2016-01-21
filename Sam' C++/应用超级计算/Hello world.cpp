#include <iostream>
#include <mpi.h>
#pragma comment (lib,"mpi.lib")
 using namespace std;
 const int MAX_STRING = 100;
 int main(void)
 { 
	 char greeting[MAX_STRING];
	 int comm_sz;	//Number of process
	 int my_rank;	//My process rank
	 MPI_Init(NULL, NULL);
	 MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	 MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	 if (my_rank != 0){
		 sprintf_s(greeting, "Greetring from process %d of %d!\n",my_rank,comm_sz);
		 MPI_Send(greeting, strlen(greeting) + 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
	 }
	 else {
		 printf("Greetings from process %d of %d!\n", my_rank, comm_sz);
		 for (int q = 1; q <comm_sz; q++)				//Receive from 1 to comm_sz;
		 {
			 MPI_Recv(greeting, MAX_STRING, MPI_CHAR, q, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			 printf("%s", greeting);
		 }
	 }
	 MPI_Finalize();
	 return 0;
 }