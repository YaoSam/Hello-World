#include<iostream>
#include<stdlib.h>
using namespace std;

class Rectangle
{
	public:
	//int xL,int xW,int xH
		Rectangle(){}
	 Rectangle(Rectangle &r);
	void inRec();
	int volume();
	void outRec();
	private:
	int length,width,heigth,Vol;
};

Rectangle::Rectangle(Rectangle &r)
{
	length = r.length;
	width = r.width;
	heigth = r.heigth;
}
void Rectangle:: inRec(){
	cout << "请输入长，宽，高：" << endl;
	cin >> length >> width >> heigth;
}
int Rectangle:: volume(){
	Vol = length*width*heigth;
	return Vol;
}
void Rectangle::outRec(){
	cout<<"体积为"<< Vol<<endl;
}

int main()
{
	//int a1,a2,a3,b1,b2,b3,c1,c2,c3;
	Rectangle R1; 
	Rectangle R2;
	Rectangle R3;//(a1,a2,a3)(b1,b2,b3) (c1,c2,c3) 
	R1.inRec();
	R1.volume();
	R1.outRec();
	R2.inRec();
	R2.volume();
	R2.outRec();
	R3.inRec();
	R3.volume();
	R3.outRec();

	system("pause");
	return 0;
}
