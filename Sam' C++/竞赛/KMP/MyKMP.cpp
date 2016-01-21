#include <iostream>
#include <string>
#include<time.h>
using namespace std;
#define MAX 1000
#define DEBUG
#define Re(i,n)		for(int i=0;i<=n;i++)
#define RE(n)		for(int I=0;I<=n;I++)

/*����ע��*/
/*
j=Next[j];��ζ��j�������ǰ��׺��λ�ã����ִ�ʱi+j������ԭ����λ���ϡ�
����Ҫ��i+j=i'+Next[j]
*/
/*Sample Input:

*/

int VMatch(string target, string text)
{
	int  j = 0, ans = 0;
	int len1 = target.length(), len2 = text.length();
	for (int i = 0; i < len2; i++)
	{
		while (j < len1&&text[i + j] == target[j])	j++;
		if (j == len1)	ans++;
		j = 0;
	}
	return ans;
}

int Next[MAX];

int GetNext(string target)//����һ��n�͵ı�����
{
	int i = 0, j = -1;
	Next[0] = -1;
	int len = target.length();	
	while (i < len)
	{
		if (j==-1||target[i] == target[j])//j==-1˵��û����ͬǰ��׺��Next[i]=0;
		{
			i++;
			j++;
			Next[i] = j;
		}
		else 
		j = Next[j]; //������ȣ���ݹ�Ѱ����ͬǰ��׺��֪���Ҳ���Ϊֹ
	}
	return 0;
}

int KMP(string target, string text)
{
	GetNext(target);
	int j = 0, ans = 0;
	int len1 = target.length();
	int len2 = text.length();
	for (int i = 0; i <= len2-len1; )
	{
		while (i+j<len2&&(j==-1||text[i+j] == target[j]))		j++;	
		if (j == len1)	ans++;
		i +=j-Next[j];
		j = Next[j];
	}
	return ans;
}
int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	string a, b;
	cin >> a >> b;
	RE(13) 
	{
		b += b;
		float time1, time2;
		time1 = (double) clock() / CLOCKS_PER_SEC;
		cout << VMatch(a,b)<<endl;
		time2 = (double)clock() / CLOCKS_PER_SEC;
		cout<<time2-time1<<endl;
		//GetNext(a);
		time1 = (double) clock() / CLOCKS_PER_SEC;
		KMP(a, b);
		time2 = (double)clock() / CLOCKS_PER_SEC;
		cout << time2 - time1 << endl;
	}
	//RE(20) cout << Next[I] << ' '; cout << endl;
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}