#include <iostream>
using namespace std;
struct Base1	{int x;};
struct Base2	{float y;};
struct Derived:Base1,Base2{};

//��α��⣺���ÿ�ָ��... ...����ǿ������ת����

int main()
{
	Derived *pd=new Derived;
	pd->x=1;
	pd->y=2.0f;
	void *pv=pd;
	Base2 *pb =/*(static_cast<Base2*>)*/(Base2*)(pd);
	//pv����ʵ������Derived���̳���Base1��Base2�����Դ�voidǿ��ת����Base2��Ȼ�����롣
	cout<<pd->y<<" "<<pb->y<<endl;
	//���������Derived ת����Base2��ϵͳ���Զ�����ָ�룬ʹ��ָ��̳еĲ��֡�
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