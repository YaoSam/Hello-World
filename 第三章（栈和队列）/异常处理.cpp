#include <iostream>
#include <string>
using namespace std;
int divide(int x, int y){
	if (y == 0)
		throw "ÄãËûÂèµÄ£¡";
	return x / y;
}



int main(){
	try
	{
		cout << "8/0=" << divide(8, 0) << endl;
	}
	catch (int e)
	{
		cout << e << " is divided by 0" << endl;
	}
	catch (const char* a)
	{
		cout << a << endl;
	}
	cout << "This is ok." << endl;
	system("pause");
	return 0;
}