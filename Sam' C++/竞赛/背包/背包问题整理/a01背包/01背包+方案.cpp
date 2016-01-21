#include<iostream>
using namespace std;
int main()
{
int m,n,w[100],p[100],f[100];
for(int k=0;k<=99;k++)
 f[k]=0;
cin>>m>>n;
for(int k=1;k<=n;k++)
 cin>>w[k]>>p[k];
for(int k=1;k<=n;k++)
{
 for(int q=m;q>=w[k];q--)
  if(f[q-w[k]]+p[k]>f[q])
    f[q]=f[q-w[k]]+p[k];
}
cout<<f[m]<<endl;

for(int x=n;x>=1;x--)
 {
  if(f[m-1]==f[m])
   m--;
  if(f[m-w[x]]==f[m]-p[x])
   {
    m-=w[x];
    cout<<w[x]<<" "<<p[x]<<endl;
   }
 }
system("Pause");    
}
