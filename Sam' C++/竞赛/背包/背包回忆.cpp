#include <iostream>
using namespace std;
#define DEBUG
/*ûʲô��˵��*/

int Volume;
struct object
{
	int value, weight;
};
int F[100];
int Onebag(object one)
{
	for (int i = Volume; i >= one.weight; i--)
		if (F[i - one.weight] >= 0)
			if (F[i] < F[i - one.weight] + one.value)
				F[i] = F[i - one.weight] + one.value;
	return 0;
}



int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif


#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}