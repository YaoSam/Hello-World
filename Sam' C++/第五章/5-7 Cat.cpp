#include <iostream>
#include <string>
using namespace std;
#define DEBUG
#define Re(i,n)		for(int i=1;i<=n;i++)
#define RE(n)		for(int I=1;I<=n;I++)

/*����ע��*/
/*Sample Input:

*/
class Cat
{
private:
	static int numOfCats;
public:
	int getnumOfCats()
	{
		cout << numOfCats << endl;
		return numOfCats;
	}
	int add(int n)
	{
		numOfCats += n;
		return getnumOfCats();
	}
	int sub(int n)
	{
		numOfCats -= n;
		return getnumOfCats();
	}
};
int Cat::numOfCats = 10;
int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	Cat a,b,c;
	a.add(10);
	b.sub(3);
	c.getnumOfCats();
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}