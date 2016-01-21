#include<cstdlib>
#include <cstdio>
#include<cstring>
#include <iostream>
#include <string>
#include"engine.h"
#define  DEBUG
using namespace std;
const int BUFFER_SIZE = 102400;
char buffer[BUFFER_SIZE];

int main()
{
#ifdef DEBUG
	FILE *err; //没用的指针... ...
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	Engine* ep;
	if ((ep = engOpen("")) == NULL)
	{
		printf("Engine Fail");
	}
	printf("Init Success");
	engOutputBuffer(ep, buffer, BUFFER_SIZE);
	engSetVisible(ep, 1);
	engEvalString(ep, "clear");
#define SIZE 1000
	double x[SIZE] = { 0 };
	double y[SIZE] = { 0 };
	for (int i = 0; i < SIZE; i++)x[i] = i*0.1;
	mxArray *x1 = NULL;
	mxArray *y1 = NULL;
	//申请空间
	x1 = mxCreateDoubleMatrix(1, SIZE, mxREAL);
	y1 = mxCreateDoubleMatrix(1, SIZE, mxREAL);
	
	memcpy((void *)mxGetPr(x1), (void *)x, sizeof(x));
	engPutVariable(ep, "x", x1);


	engEvalString(ep, "y=sin(x);");
	engEvalString(ep, "plot(x,y);");
	engEvalString(ep, "y");
	
	y1 = engGetVariable(ep, "y");
	memcpy((void*)y, (void*)mxGetPr(y1), sizeof(y));
	
	for (int i = 0; i < SIZE; i++)
		cout << y[i] << endl;
	cout << buffer << endl;
	system("pause");
	engClose(ep);
}