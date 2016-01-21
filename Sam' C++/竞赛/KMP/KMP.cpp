/*
本KMP算法用于计算匹配个数；
*/
#include <iostream>
using namespace std;
#define scanf scanf_s

char s1[1000001], s2[1000001];//s1为被匹配串，s2为匹配串 
int n;
int Next[1000001];

int getlen(char s[])
{
	int len = 1;
	while (1)
	{
		if (s[len + 1] == '\0')break;
		len++;
	}
	return len;
}
int pre_P(char s[])
{
	int j = 0;
	int len = getlen(s);
	Next[1] = 0;
	for (int i = 2; i <= len; i++)
	{
		while (j>0 && s[i] != s[j + 1])j = Next[j];			//匹配失败。递归回溯。
		if (s[i] == s[j + 1])j++;										//成功。不成功j=0。下面P[i]一样为零。
		Next[i] = j;
	}
	return 0;
}
int KMP(char s1[],char s2[])
{
	int len1, len2, ans=0, j = 0;
	len1 = getlen(s1);
	len2 = getlen(s2);
	for (int i = 1; i <= len1; i++)
	{
		while (j>0 && s1[i] != s2[j + 1])j = Next[j];
		if (s1[i] == s2[j + 1])j++;
		if (j == len2)
		{ 
			ans++; 
			j = Next[j]; 
		}//记得把j=P[j]方便后面继续计数 
	}
	return ans;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int ans = 0;
		cin >> s1;
		cin >> s2;
		pre_P(s2);
		ans=KMP(s1, s2);
		printf("%d\n", ans);
	}
	system("pause");
	return 0;
}
