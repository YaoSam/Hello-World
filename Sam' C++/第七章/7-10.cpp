#include <iostream>
#include <string>
using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)

/*����ע��*/
/*Sample Output:
An Object is born
A Box is born
A Box is dead
An Object is dead
*/
class Object
{
	float weight;
public:
	Object(float w) :weight(w){ cout << "An Object is born"<<endl; }
	~Object(){ cout << "An Object is dead" << endl; }
};

class Box:public Object
{
	float heigth, width;
public:
	Box(float w, float h, float wi) :heigth(h), width(wi), Object(w){ cout << "A Box is born" << endl; }
	~Box(){ cout << "A Box is dead" << endl; }
};


int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	Box(1, 2, 3);

#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}