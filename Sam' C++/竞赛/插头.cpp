#include <iostream>
using namespace std;
#define DEBUG
/*ûʲô��˵��*/
int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	int X[10], Y[10];
	int ok=1;
	for (int j = 1; j <= 2;j++)
	{
		for (int i = 1; i <= 5; i++)	cin >> X[i];
		for (int i = 1; i <= 5; i++)	cin>>Y[i];
		for(int i=1;i<=5;i++)
			if(X[i]==Y[i])
		{
			cout<<"N"<<endl;
			ok = 0;
			break;
		}
		if (ok == 1)cout << "Y" << endl;
		ok = 1;
	}

#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}