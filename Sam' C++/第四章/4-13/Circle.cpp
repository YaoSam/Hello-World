#include "Circle.h"
#include <iostream>
using namespace std;
Circle::Circle(float R)
{
	radius = R;
}
float Circle::ShowArea()
{
	cout << "Area is:" << radius*radius*PI<<endl;
	return radius*radius*PI;
}
float Circle::ShowPerimeter()
{
	cout << "Perimeter is:" << radius * 2 * PI<<endl;
	return radius * 2 * PI;
}
