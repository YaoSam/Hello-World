#include <iostream>
using namespace std;
//#define DEBUG
/*ûʲô��˵��*/
class Cubic
{
private:
	float length, height, width, volume;
public:
	Cubic(float l, float h, float w)
	{
		length = l;
		height = h;
		width = w;
		volume = l*h*w;
	}
	Cubic()
	{
		cout << "���������볤����ĳ����: " << endl;
		cin >> length >> width >> height;
		volume = length*width*height;
	}
	void showVolume()
	{
		cout << "���Ϊ��" << volume<<endl;
	}
};
int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	Cubic one[3];
	for (int i = 0; i < 3; i++)one[i].showVolume();

#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}
/*
Sample input
1 2 3 4 5 6 7 8 9
*/