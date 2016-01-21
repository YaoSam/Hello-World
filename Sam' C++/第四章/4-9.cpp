#include <iostream>
using namespace std;
//#define DEBUG
/*��point�������������һ��������Rectangle*/
class point
{
private:
	int x, y;
public:
	point(int a = 0, int b = 0)
	{
		x = a, y = b;
	}
	int ShowPoint()
	{
		printf("(%d,%d)", x, y);
		return 1;
	}
	int DeltaX(point one)//ͨ��������������Ĳ����������
	{
		return x - one.x;
	}
	int DeltaY(point one)
	{
		return y - one.y;
	}
};
class Rectangle
{
private :
	point leftdown, rightup,area;
public:
	Rectangle(point LD, point RU)
	{
		leftdown = LD, rightup = RU;
	}
	Rectangle(int a, int b, int c, int d)//(a,b),(c,d)
	{
		point LD(a, b), RU(c, d);
		leftdown = LD, rightup = RU;
	}
	int ShowArea()
	{
		int delx = rightup.DeltaX(leftdown);
		int dely = rightup.DeltaY(leftdown);
		leftdown.ShowPoint(); rightup.ShowPoint();
		if (delx > 0 && dely > 0)
			cout << "���Ϊ��" << delx*dely << endl;
		else cout << "ERROR�����귽λ����" << endl;
		return 0;
	}
};
int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
		point A(1,2),B(3,4);
		Rectangle R(A,B);
		R.ShowArea();

#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}