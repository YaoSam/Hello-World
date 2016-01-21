#include <iostream>
using namespace std;
#define DEBUG

int main()
{
#ifdef DEBUG
	FILE *err;
	freopen_s(&err,"in.txt", "r", stdin);
	freopen_s(&err,"out.txt", "w", stdout);
#endif
	for (int n = 100; n <= 200; n+=2)cout << n<<' ';
	cout << endl;
	int n = 100;
	while (n <= 200)
	{
		cout << n << ' ';
		n += 2;
	}
	cout << endl;
	n = 100;
	do
	{		
		cout << n << ' ';
		n += 2;
	} while (n <= 200);
	cout << endl;
	int aa = 1, bb = 2, cc = 3;
	cout <<(aa|bb-cc)<< (aa^bb&-cc)<<(aa&bb|cc)<<(aa|bb&cc)<<(bb&-cc);
	return 0;
}