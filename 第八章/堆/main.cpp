/*
*
*　　　	 　　　　   ┏┓　		 ┏┓+ +
*　　  　　　　　┏┛┻━━━━━━┛┻┓ + +
*　　  　　　　　┃　　　　       ┃ 　
*　　  　　　　　┃　　　━　　 ┃ ++ + + +
*　　  　　		   ┃  ███━███  ┃+
*　　  　　　　　┃　　　　　　┃ +
*　　  　　　　　┃　　   ┻　　  ┃
*　　  　　　　　┃　　　　　　┃ + +
*　　  　　　　　┗━┓　　　 ┏━┛
*　　　　　　　　　┃　　　┃　　　　　　　　　　　
*　　　　　　　　　┃　　　┃ + + + +
*　　　　　　　　　┃　　　┃　　　　Code is far away from bug with the animal protecting　　　　　　　
*　　　　　　　　　┃　　　┃ + 　　　　神兽保佑,代码无bug　　
*　　　　　　　　　┃　　　┃
*　　　　　　　　　┃　　　┃　　+　　　　　　　　　
*　　　　　　　　　┃　 　　┗━━━┓ + +
*　　　　　　　　　┃ 　　　　　　　┣┓
*　　　　　　　　　┃ 　　　　　　　┏┛
*　　　　　　　　　┗┓┓┏━┳┓┏┛ + + + +
*　　　　　　　　　　┃┫┫　┃┫┫
*　　　　　　　　　　┗┻┛　┗┻┛+ + + +
*/
#include <iostream>
#include <string>
#include <time.h>
#include "Bag.h"
using namespace std;
///test to git
//#define DEBUG //用来确定是否文本输出。
#undef re
#define re(i,n) for(unsigned int i=0;i<n;i++)

int main()
{
	clock_t time1 = clock();
		srand(unsigned int(time(NULL)));
#ifdef DEBUG
		FILE *err; //没用的指针... ...
		freopen_s(&err, "in.txt", "r", stdin);
		freopen_s(&err, "out.txt", "w", stdout);
#endif
	try{
		unsigned int n = 0;
		double Limit = 0;
		//输入
		cout << "请输入物体数目："; cin >> n;
		cout << "请输入背包大小："; cin >> Limit;
		object *thing = new object[n + 1];
		cout << "请输入背包：" << endl;
		re(i, n)
			cin >> thing[i];
		//运算
		BagState bestSolution = Solve(n, Limit, thing);
		//输出
		//cout << "输入的背包：" << endl;
		//re(i, n)
		//	cout << thing[i];
		//Qsort(thing, 0, n - 1);
		//cout << "背包排序后：" << endl;
		//re(i, n)
		//	cout << thing[i];
		//cout << endl;
		cout << "The max sum_value is: " << endl << bestSolution.value() << endl;
		cout << "The optimum solution is :"<< endl<< bestSolution << endl;
		delete[] thing;
	}
	catch (char const * a){ cout << a << endl; }
	cout << "运行时间: " << clock() - time1 << endl;
#ifndef DEBUG //加个断点。
		printf("\n");
		system("pause");
#endif // !DEBUG	
	return 0;
}



/*
20
10
1 6 2
2 3 2
3 5.5 6
4 4 5
5 6 6.5
1 6 2
2 3 2
3 5.5 6
4 4 5
5 6 6.5
1 6 2
2 3 2
3 5.5 6
4 4 5
5 6 6.5
1 6 2
2 3 2
3 5.5 6
4 4 5
5 6 6.5
1 6 2
2 3 2
3 5.5 6
4 4 5
5 6 6.5
1 6 2
2 3 2
3 5.5 6
4 4 5
5 6 6.5
1 6 2
2 3 2
3 5.5 6
4 4 5
5 6 6.5


*/