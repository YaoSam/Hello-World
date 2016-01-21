#pragma once
namespace CircleNs
{
	const float PI = 3.14159;
}
using namespace CircleNs;
class Circle
{
private:
	float radius;
public:
	Circle(float R = 0);
	float ShowArea();
	float ShowPerimeter();
};

