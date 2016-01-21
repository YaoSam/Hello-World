#include <iostream>
using namespace std;
struct node
{
 int w;
 int p;
 int sum;    
}ans[110];

int f[110]={0};

int main()
{
 int m,n;
 cin>>m>>n;
 for(int i=1;i<=n;i++)
  cin>>ans[i].w>>ans[i].p>>ans[i].sum;
 for(int i=1;i<=n;i++)
  for(int j=0;j<ans[i].sum;j++)
   for(int k=m;k>=ans[i].w;k--)
    if(f[k]<=f[k-ans[i].w]+ans[i].p)
     f[k]=f[k-ans[i].w]+ans[i].p;
 cout<<f[m]<<endl;
 system("pause");
}
