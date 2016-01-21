#include<iostream>
#include <memory.h>
using namespace std;
int main()
{
    int m,n,w[2001]={0},p[2001]={0},c[2001][201]={0};
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    cin>>w[i]>>p[i];
    
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        if(w[i]<=j)
          if(p[i]+c[i-1][j-w[i]]>c[i-1][j])
          c[i][j]=p[i]+c[i-1][j-w[i]];
          else
          c[i][j]=c[i-1][j];
        else
        c[i][j]=c[i-1][j];        
	cout<<c[n][m]<<endl;
    system("pause");
}
