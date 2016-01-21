#include<iostream>
using namespace std;
struct node
{
int w,p,c;
}ans[11000];
int main()
{
 int n,m,total=1,f[1000]={0};
 cin>>m>>n;
 for(int i=1;i<=n;i++)
 {
  int w,p,c;
  cin>>w>>p>>c;
  ans[total].w=w;
  ans[total++].p=p; 
  for(int i=1;i<c;i++)
  {
   ans[total].w=w;
   ans[total++].p=p;
  }
 }

 for(int i=0;i<total;i++)
  for(int v=m;v>=ans[i].w;v--)
   if(f[v]<=f[v-ans[i].w]+ans[i].p)
    f[v]=f[v-ans[i].w]+ans[i].p;
 cout<<f[m]<<endl;
 system("pause");
}
