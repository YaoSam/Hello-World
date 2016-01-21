/*
Sample Input:
0 123
123 190
0 1233
1 120
500 1000
1 10
10 20
20 40
40 80
80 160
Sample Output:
Multiple Thread cost time= 1.116000
Main Thread cost time= 0.616000
Bingo!
Multiple Thread cost time= 1.470000
Main Thread cost time= 0.771000
Bingo!
Multiple Thread cost time= 0.075000
Main Thread cost time= 0.045000
Bingo!
Multiple Thread cost time= 1.549000
Main Thread cost time= 0.760000
Bingo!
Multiple Thread cost time= 0.125000
Main Thread cost time= 0.075000
Bingo!
Multiple Thread cost time= 0.588000
Main Thread cost time= 0.313000
Bingo!
Multiple Thread cost time= 0.010000
Main Thread cost time= 0.010000
Bingo!
Multiple Thread cost time= 0.010000
Main Thread cost time= 0.005000
Bingo!
Multiple Thread cost time= 0.025000
Main Thread cost time= 0.010000
Bingo!
Multiple Thread cost time= 0.050000
Main Thread cost time= 0.020000
Bingo!
Multiple Thread cost time= 0.095000
Main Thread cost time= 0.050000
Bingo!
*/
#include <iostream>
#include <pthread.h>
#include <assert.h>
#include <math.h>
using namespace std;
//#define DEBUG	//用来控制是否文本输入输出
#define re(i,n) for(int i=0;i<n;i++)

#define TIME		(float)clock()/CLOCKS_PER_SEC																//当前运行时间
#define Test(str) for(float t = TIME, flag = 1; flag ; flag = 0 , t = TIME - t, printf("%scost time= %f\n", str ,t )) //用来测试运行时间。

//这句貌似是windows下要用到的。
#pragma comment(lib,"x86/pthreadVC2.lib")

//我的电脑是2核4线程（超线程）。所以设为4.
#define Thread_Num 4
#define Delta 0.00001

//函数,听说这样效率高一点？
#define function(x) x*x

//积分上下限。
int Left, Right;
double sum[Thread_Num];
void *Intergral(void *Param)
{
	int tid = (int)(Param);
	for (double x = tid*Delta + Left; x < Right; x += Thread_Num*Delta)
		sum[tid] += function(x);
	return NULL;
}

int main()
{
#ifdef DEBUG
	FILE *err; //没用的指针... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	void *status;
	pthread_attr_t attr[Thread_Num];
	pthread_t pid[Thread_Num];
	re(i,Thread_Num)	pthread_attr_init(attr + i);
		//输入积分上下限
	while(cin >> Left >> Right)
	{
		double threadans = 0, mainans = 0;
		Test("Multiple Thread ")
		{
			re(i, Thread_Num)
				pthread_create(pid + i, attr + i, Intergral, (void*)(i));
			re(i, Thread_Num) 
			{
				pthread_join(pid[i], &status);
				threadans += sum[i];
			}
			memset(sum, 0, sizeof(sum));
			threadans *= Delta;
		}
		Test("Main Thread ")
		{
			for (double i = Left; i < Right; i += Delta)
				mainans += function(i);
			mainans *= Delta;
		}
		//对比结果
		cout << ((mainans/threadans<1.0001&&mainans/threadans>0.9999) ? "Bingo!" : "No" )<< endl;
		//cout << "Thread ans = " << threadans << endl
		//	<< "Main ans = " << mainans << endl;
	}
	re(i, Thread_Num)	pthread_attr_destroy(attr + i);
#ifndef DEBUG
	system("pause");
	printf("\n");
#endif
	return 0;
}