#include <iostream>
#include <string>
using namespace std;

string up1 = "<UP>", up2 = "</UP>", down1 = "<DOWN>", down2 = "</DOWN>";

bool match(string str, int i, string target)
{
	for (int j = 1; j < target.length(); j++)//因为前面的‘<’已经确定所以j的初始值为0
		if (str[i + j] != target[j])
			return 0;
	return 1;
}

int search(string str,int status)			//status=	0代表正常，1代表大写，2代表小写。
{
	static int i = 0;							//将整个函数当作一个循环所以将i设为静态。
	for (; i < str.length(); i++)
	{
		if (str[i]=='<')
		{
			if			(match(str, i, up1))			{ i += up1.length();			search(str, 1); }
			else if	(match(str, i, up2))			{ i += up2.length() - 1;		return 0; }	//因为退出的时候重新进入上一轮循环的时候会被加一，所以-1
			else if	(match(str, i, down1))		{ i += down1.length();		search(str, 2); }
			else 											{ i += down2.length() - 1;	return 0; }
		}
		else
		{
			if (status == 0)			cout << str[i];
			else if (status == 1)		putchar((str[i] >= 'a'&&str[i] <= 'z') ? str[i] + 'A' - 'a' : str[i]);
			else							putchar((str[i] >= 'A'&&str[i] <= 'Z') ? str[i] + 'a' - 'A' : str[i]);
		}
	}
	i = 0;		//虽然题目只要做一次。但还是打上吧。来到这里的只能是第一层函数。重新初始化i
	return 0;
}


int main()
{

	string str;
	cin >> str;
	search(str, 0);
	return 0;
}