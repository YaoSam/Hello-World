#include <iostream>
using namespace std;
#define DEBUG
char Str[1000010];
int num[27][1000010], p[30] = {0};
int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	int N, n, K; 
	char targer;
	cin>>N>>Str>>n;

	int len;
	for (len = 0; Str[len] != '\0'; len++)
	{
		for (int i = 0; i < 26; i++)
		{ 
			if (i != Str[len] - 'A')
			{ 
				num[i][len] += num[i][len - 1];
			}
			else 	
			{
				num[i][len] += num[i][len - 1] + 1;
			}
		}
	}

	for (int i = 0; i < 26; cout << endl, i++)
		for (int j = 0; j < len; j++)
			cout << num[i][j];
/*			for(int i=1;	i<=n;i++)
	{
		cin >> K >> targer;

	}
*/

#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}