/*
 本KMP算法用于计算匹配个数； 
*/
#include <stdio.h>
#include <iostream>
#define scanf scanf_s
using namespace std;
int len1;
int len2;
char s1[1000001],s2[1000001];//s1为被匹配串，s2为匹配串 
int n;
int P[1000001];
int ans;
int getlen(char s[])
{
 int len=1;
 while(1)
  {
   if(s[len+1]=='\0')break;
   len++;
  }
 return len;
}
int pre_P(char s[],int len)
{
 int j=0;
 P[1]=0;
 for(int i=2;i<=len;i++)
  {
   while(j>0&&s[i]!=s[j+1])j=P[j];
   if(s[i]==s[j+1])j++;
   P[i]=j;
  }
  return 0;
}
int KMP(char s1[],int len1,char s2[],int len2)
{
 int j=0;
 for(int i=1;i<=len1;i++)
  {
   while(j>0&&s1[i]!=s2[j+1])j=P[j];
   if(s1[i]==s2[j+1])j++;
   if(j==len2){ans++;j=P[j];}//记得把j=P[j]方便后面继续计数 
  }
 return 0;
}
int main()
{
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  {
   ans=0;
   //scanf("%s%s",s2+1,s1+1);
   cin >> s2 + 1 >> s1 + 1;
   len1=getlen(s1);
   len2=getlen(s2);
   pre_P(s2,len2);
   KMP(s1,len1,s2,len2);
   printf("%d\n",ans);
  }
 system("pause");
 return 0;
}
