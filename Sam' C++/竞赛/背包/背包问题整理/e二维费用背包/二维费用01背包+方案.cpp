#include<iostream>
using namespace std;
int main()
{
 int f[100][100]={0};
 int w1[100],w2[100],p[100];
 int i,j,k,n,m1,m2;
 cin>>m1>>m2>>n;
 for(i=1;i<=n;i++)
  cin>>w1[i]>>w2[i]>>p[i];
  
 for(i=1;i<=n;i++)
 {
  for(j=m1;j>=w1[i];j--)
   for(k=m2;k>=w2[i];k--)
    if(f[j][k]<f[j-w1[i]][k-w2[i]]+p[i])
     f[j][k]=f[j-w1[i]][k-w2[i]]+p[i];
 }
 cout<<f[m1][m2]<<endl;
 
 for(int x=n;x>=1;x--)
 {
  if(f[m1-1][m2]==f[m1][m2])
   m1--;
  if(f[m1][m2-1]==f[m1][m2])
   m2--;
  
  if(f[m1-w1[x]][m2-w2[x]]==f[m1][m2]-p[x])
   {
    m1-=w1[x];
    m2-=w2[x];
    cout<<w1[x]<<" "<<w2[x]<<" "<<p[x]<<endl;
   }
 }
 system("pause");
}
