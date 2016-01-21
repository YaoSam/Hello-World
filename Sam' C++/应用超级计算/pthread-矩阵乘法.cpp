/*
�������СΪ500 500 500ʱ��
Sample Input:

500 500 500

Sample output:

Multiple Threadcost time= 0.650000
Main Threadcost time= 1.160000
Bingo!

*/

#include <iostream>
#include <pthread.h>
#include <assert.h>
using namespace std;
//#define DEBUG	//���������Ƿ��ı��������
#define re(i,n) for(int i=0;i<n;i++)

#define TIME		(float)clock()/CLOCKS_PER_SEC																//��ǰ����ʱ��
#define Test(str) for(float t = TIME, flag = 1; flag ; flag = 0 , t = TIME - t, printf("%scost time= %f\n", str ,t )) //������������ʱ�䡣

//���ò����windows��Ҫ�õ��ġ�
#pragma comment(lib,"x86/pthreadVC2.lib")

//�ҵĵ�����2��4�̣߳����̣߳���������Ϊ4.
#define Thread_Num 4
#define RANGE 10
int a, b, c;
double **Matrix1,**Matrix2,**thread_Ans,**main_Ans;

void *Matrix_Product(void *Param)
{
	int tid = (int)(Param);
	for (int i = tid; i < a*c; i += Thread_Num)
	{
		int x = i / c, y = i%c;
		re(j, b)
			thread_Ans[x][y] += Matrix1[x][j] * Matrix2[j][y];
	}
	return NULL;
}

void print(double **Mat, int one, int two)
{
	re(i, one)
	{
		re(j, two)
			cout << Mat[i][j] << ' ';
		cout << endl;
	}
}
int main()
{
#ifdef DEBUG
	FILE *err; //û�õ�ָ��... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	cin >> a >> b >> c;
	//����ռ�+¼������
	Matrix1 = new double *[a];
	Matrix2 = new double *[b];
	thread_Ans = new double *[a];
	main_Ans = new double *[a];

	srand(time(NULL));
	re(i, a)
	{
		Matrix1[i] = new double[b];
		thread_Ans[i] = new double[c];
		main_Ans[i] = new double[c];
		memset(main_Ans[i], 0, sizeof(double)*c);
		memset(thread_Ans[i], 0, sizeof(double)*c);
		re(j,b)	 Matrix1[i][j]=(float)rand()/RAND_MAX*RANGE;
	}
	re(i, b)
	{
		Matrix2[i] = new double[c];
		re(j, c)
			Matrix2[i][j] = (float)rand() / RAND_MAX*RANGE;
	}
	void *status;
	pthread_attr_t attr[Thread_Num];
	pthread_t pid[Thread_Num];
	//����֪������������ʲô��
	//pthread_attr_setscope(&attr, PTHREAD_SCOPE_PROCESS);
	//pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	//printf("=======================");
	Test("Multiple Thread ")
	{
		re(i, Thread_Num)
		{
			pthread_attr_init(attr + i);
			pthread_create(pid + i, attr + i, Matrix_Product, (void*)(i));
		}
		//�ȴ�ÿ���߳���ɡ�Ҳ������գ���ֹ�����߳̾�����Դ��
		re(i, Thread_Num) pthread_join(pid[i],&status);
	}
	//���̼߳�������
	Test("Main Thread ")
	re(i, a)
		re(j, c)
			re(k, b)
				main_Ans[i][j] += Matrix1[i][k] * Matrix2[k][j];
	//�ԱȽ��
	bool flag = 0;
	re(i, a)
		re(j, c)
		if (main_Ans[i][j] != thread_Ans[i][j])
		{
			flag = 1;
			cout << "NO!!!" << endl;
		}
	if (!flag)cout << "Bingo!" << endl;
	//�����������
	//print(Matrix1, a, b);
	//print(Matrix2, b, c);
	//print(thread_Ans, a, c);
	//print(main_Ans, a, c);
	re(i,Thread_Num)	pthread_attr_destroy(attr+i);
#ifndef DEBUG
	system("pause");
	printf("\n");
#endif
	return 0;
}