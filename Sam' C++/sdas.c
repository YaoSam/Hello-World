#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define STUDENT_NUM 10
#define COURSE_NUM  5
void Scoresystem(double score[][5],double credit[],int Stdnumber,double GPA[],double StdDeviation[]);
int main()
{	double studentScore[10][5];
	double courseAcadamicCredit[5]={1,2,3,4,5};
	double studentGPA[10];
	double courseStdDeviation[5];
	
	int i,j;
	
	for (i=0;i<STUDENT_NUM;i++)
	{ for(j=0;j<COURSE_NUM;j++)
		{ studentScore[i][j] = rand()%100;}
	}
	for (i=0;i<STUDENT_NUM;i++)
	{ for(j=0;j<COURSE_NUM;j++)
		{ printf("%lf\t",studentScore[i][j]);}
	  printf("\n");
	}

	Scoresystem(studentScore,courseAcadamicCredit,10,studentGPA,courseStdDeviation);
	system("pause");
}
	//jidian   
void Scoresystem(double score[][5],double credit[],int Stdnumber,double GPA[],double StdDeviation[])
{ 
	    int i,j;
		double sum;
		double creditSum = 0;
		double m,t;
		for (i=0;i<COURSE_NUM;i++)
		{ creditSum = creditSum + credit[i];}

		for (i=0;i<STUDENT_NUM;i++)
		{ 
		  sum = 0;
		  for(j=0;j<COURSE_NUM;j++)
		  { sum = sum + score[i][j]*credit[j];}
		  GPA[i] = sum/creditSum;
		  printf("student No.%d's GPA is %lf\n",i,GPA[i]);
		}
		double average = 0;
		for(j=0;j<COURSE_NUM;j++)
		{ sum=0;
		  for(i=0;i<STUDENT_NUM;i++)
		  { sum=sum+score[i][j];}
		  average=sum/STUDENT_NUM*1.0;
		  t=0;
		  for(i=0;i<STUDENT_NUM;i++)
		  { t=(score[i][j]-average)*(score[i][j]-average)/(i*1.0);}
		  m=sqrt(t);
		  printf("Course No.%d's biaozhuncha is %lf\n",j,m);
		}
}