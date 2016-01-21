#include <iostream>
#include <string>

using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)
#define RE(n)			for(int I=0;I<n;I++)

/*程序注释*/
/*Sample Input:
8
1 2 3 4 5 6 7 8
*/

int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	int n = 8, score; 
	float sum = 0;
	cout << "请输入学生人数" << endl;
	cin >> n;
	cout << "请输入" << n << "位学生的成绩" << endl;
	Re(i, n)cin >> score,sum+=score;
	cout << "平均分为：" << sum / n;
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}