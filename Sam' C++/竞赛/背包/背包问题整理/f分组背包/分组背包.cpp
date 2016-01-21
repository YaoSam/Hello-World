#include<iostream>
using namespace std;
int main()
{
 int m,n,kind,i,j,k,f[1000]={0};
 int z[100],w[100],p[100];
 cin>>m>>n>>kind;
 for(i=1;i<=n;i++)
  cin>>z[i]>>w[i]>>p[i];
  
 for(i=1;i<=kind;i++)
  for(j=m;j>=0;j--)
   for(k=1;k<=n;k++)
    if (z[k]==i)
     {
      if(j<w[k]) continue;
      f[j]=max(f[j], f[j-w[k]]+p[k]);
     }
    
 cout<<f[m]<<endl;
 system("pause");
}
