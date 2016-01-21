#include <iostream>
#include <string>
using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)
const float PI = 3.1415926;
/*����ע��*/
/*Sample Input:

*/
class Shape
{
public:
	float getArea()const
	{
		return 0;//����Ĳ�֪��һ��Shape�ܸ�ʲô... ...
	}
	friend ostream& operator<<(ostream &out, Shape const &other);
};
ostream&operator<<(ostream &out, Shape const &other)
{
	out << other.getArea();
	return out;
}



class Rectangle:public Shape
{
	float length, height;
public:
	Rectangle(float l, float h) :Shape(), length(l), height(h){}
	float getArea()const	{	return length*height;	}
	friend ostream& operator<<(ostream &out, Rectangle const &other);

};
ostream&operator<<(ostream &out, Rectangle const &other)
{
	out << other.getArea();
	return out;
}


class Circle:public Shape
{
	float R;
public:
	Circle(float r) :R(r){}
	float getArea()const	{	return R*R*PI;	}
	friend ostream& operator<<(ostream &out, Circle const &other);

};
ostream&operator<<(ostream &out,  Circle const &other)
{
	out << other.getArea();
	return out;
}

class Square:public Rectangle
{
public:
	Square(float length): Rectangle(length,length){}
};


int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	Rectangle Rec(1.5, 2.5);
	Circle Round(3);
	Square Squ(2.5);
	cout << "�����ε����Ϊ��" << Rec<< endl;
	cout << "Բ�ε����Ϊ��" << Round<< endl;
	cout << "�����ε����Ϊ��" << Squ<< endl; 
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}