#include <iostream> 
using namespace std;
int f[10001]={0}; 
int main()
{ 
  int n,m,i,j,w[10001],p[10001]; 
  cin>>m>>n; 
  for (i=1;i<=n;i++) 
   cin>>w[i]>>p[i]; 
  for (i=1;i<=n;i++) 
   for (j=w[i];j<=m;j++) 
    if(f[j]<f[j-w[i]]+p[i])
     f[j]=f[j-w[i]]+p[i]; 
  cout<<f[m]<<endl; 
  system("pause");
  return 0; 
}
