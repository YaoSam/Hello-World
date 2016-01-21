#include<iostream>
using namespace std;
int m,n;
int w[100],p[100],f[100]={0},s[100];
int ans[100]={0};
int main()
{
cin>>m>>n;
for(int k=1;k<=n;k++)
  cin>>w[k]>>p[k]>>s[k];

for(int q=1;q<=n;q++)
  for(int j=1;j<=s[q];j++)  
   for(int k=m;k>=w[q];k--)
    if(f[k-w[q]]+p[q]>f[k])
     f[k]=f[k-w[q]]+p[q];

cout<<f[m]<<endl;
for(int x=n;x>=1;x--)
 {
  if(f[m-1]==f[m])
   m--;
  while(s[x]>0)
  if(f[m-w[x]]==f[m]-p[x])
   {
    m-=w[x];
    s[x]--;
    ans[x]++;
   }
  else
   s[x]=0;
 }    
for(int i=1;i<=n;i++)
cout<<w[i]<<" "<<p[i]<<" "<<ans[i]<<endl;
system("Pause");
    
}
