#include <iostream>
#include <string>
using namespace std;

string up1 = "<UP>", up2 = "</UP>", down1 = "<DOWN>", down2 = "</DOWN>";

bool match(string str, int i, string target)
{
	for (int j = 1; j < target.length(); j++)//��Ϊǰ��ġ�<���Ѿ�ȷ������j�ĳ�ʼֵΪ0
		if (str[i + j] != target[j])
			return 0;
	return 1;
}

int search(string str,int status)			//status=	0����������1�����д��2����Сд��
{
	static int i = 0;							//��������������һ��ѭ�����Խ�i��Ϊ��̬��
	for (; i < str.length(); i++)
	{
		if (str[i]=='<')
		{
			if			(match(str, i, up1))			{ i += up1.length();			search(str, 1); }
			else if	(match(str, i, up2))			{ i += up2.length() - 1;		return 0; }	//��Ϊ�˳���ʱ�����½�����һ��ѭ����ʱ��ᱻ��һ������-1
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
	i = 0;		//��Ȼ��ĿֻҪ��һ�Ρ������Ǵ��ϰɡ����������ֻ���ǵ�һ�㺯�������³�ʼ��i
	return 0;
}


int main()
{

	string str;
	cin >> str;
	search(str, 0);
	return 0;
}