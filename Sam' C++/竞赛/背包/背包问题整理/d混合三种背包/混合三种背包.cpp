#include <iostream> 
using namespace std;
int f[10001]={0}; 
int main()
{ 
  int n,m,i,j,k,w[10001],p[10001],s[10001]; 
  //s[i]Ϊ-1��ʾ�������� 
  cin>>m>>n; 
  for (i=1;i<=n;i++) 
   cin>>w[i]>>p[i]>>s[i]; 

  for(i=1;i<=n;i++) 
  {
   if(s[i]==1)             //01���� 
    for(j=m;j>=w[i];j--) 
     if(j-w[i]>=0)  
      if(f[j]<f[j-w[i]]+p[i])
      f[j]=f[j-w[i]]+p[i];
      
   if(s[i]<0)        //��ȫ���� 
    for(j=w[i];j<=m;j++) 
     if(j-w[i]>=0)  
      if(f[j]<f[j-w[i]]+p[i])
       f[j]=f[j-w[i]]+p[i];
      
   if(s[i]>1)        //���ر��� 
    for(j=0;j<s[i];j++)
     for(k=m;k>=w[i];k--)
      if(k-w[i]>=0)  
       if(f[k]<=f[k-w[i]]+p[i])
        f[k]=f[k-w[i]]+p[i];                
  } 
  cout<<f[m]<<endl; 
  
  system("pause");
  return 0; 
}



