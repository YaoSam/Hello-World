#include <iostream>
#include <omp.h>
#include <time.h>
using namespace std;
void test(int i)
{
	int a = 0;
	for (int i = 0; i < 1000; i++)
		a++;
	cout << i << endl;
	
}
int main()
{
	clock_t t1 = clock();
#pragma omp parallel for
	for (int i = 0; i < 128; i++)
		test(i);
	clock_t t2 = clock();
	std::cout << "time: " << t2 - t1 << std::endl;
	system("pause");
}