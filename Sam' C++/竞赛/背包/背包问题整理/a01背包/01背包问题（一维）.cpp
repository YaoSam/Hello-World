#include <iostream>
using namespace std;
int main()
{
	int n,m,f[1001]={0};
	int w,p;
	int i,j;
	cin>>m>>n;
	for(i=1;i<=n;i++)
	{
		cin>>w>>p;
		for (j=m;j>=w;j--)
			if (f[j]<f[j-w]+p)
				f[j]=f[j-w]+p;
	}
	cout<<f[m]<<endl;
	system("pause");
}
