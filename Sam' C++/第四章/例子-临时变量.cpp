#include <iostream>
#include <cmath>
using namespace std;
#define DEBUG
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

class line{
private:
	point one, two;
	float len;
public:
	line(point a, point b):one(a),two(b){
		float X = one.DeltaX(two)*one.DeltaX(two);
		float Y = one.DeltaY(two)*one.DeltaY(two);
		len = sqrt(X + Y);
	}
	float ShowLen()
	{
		cout << "Len =" << len << endl;
		return len;
	}
};

/*ûʲô��˵��*/
int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	int a = 3, b = 4;
	line(point(), point(3, 4)).ShowLen();
	line(point(1,2), point(3, 4)).ShowLen();
	cout<<line(point(), point(a,b)).ShowLen()<<endl;
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}