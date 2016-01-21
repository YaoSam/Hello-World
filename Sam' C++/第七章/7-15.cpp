#include <iostream>
using namespace std;
struct Base1	{int x;};
struct Base2	{float y;};
struct Derived:Base1,Base2{};

//如何避免：别用空指针... ...还有强制类型转换？

int main()
{
	Derived *pd=new Derived;
	pd->x=1;
	pd->y=2.0f;
	void *pv=pd;
	Base2 *pb =/*(static_cast<Base2*>)*/(Base2*)(pd);
	//pv的真实类型是Derived，继承了Base1，Base2，所以从void强制转换成Base2必然会乱码。
	cout<<pd->y<<" "<<pb->y<<endl;
	//但是如果从Derived 转换成Base2，系统会自动调整指针，使其指向继承的部分。
	pb = pd;
	//Base2 *p1=pd;
	//Derived *p2;
	//p2 = (Derived *)p1;
	//cout << p2->y;
	cout << pd->y << " " << pb->y << endl;
	delete pd;
	system("pause");
	return 0;
}