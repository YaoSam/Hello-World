/**
*　　　　　　　　┏┓　　　┏┓+ +
*　　　　　		　┏┛┻━━━┛┻┓ + +
*　　　　　		　┃　　　　　	┃ 　
*　　　　　		　┃　　　━　　┃ ++ + + +
*　　　　　		 ████━████	┃+
*　　　　　		　┃　　　　　	┃ +
*　　　　　		　┃　　　┻　　┃
*　　　　　		　┃　　　　　　┃ + +
*　　　　　		　┗━┓　　　┏━┛
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
#include "poly.h"
using namespace std;
//#define DEBUG

int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	//Fx M1(-7, 10, -2, -2, 1), M2(-10, 13, -3, -2, 1);
	//Bezout(M1, M2);
	//Fx v1(7, -5, -1, 1), v2(-5, 4, 1, -1);
	//Fx r1(1, 1, 1), r2(-3, 0, 2);
	//Fx ANS = r1*v2*M2 + r2*v1*M1;
	//cout << ANS << endl;
	//cout << endl;
	//ANS = China(M1,r1,M2, r2);
	//cout << ANS%M1<<endl;
	//Fx one(197, -440, 266, 75, -130, 27, 13, -5);
	//cout << one%M1 << endl;
	//cout << one%M2 << endl;
	
	Fx f1(1, -2, 1), f2(-8, 4 - 2, 1), r1(0, 2), r2(0, 3);
	Fx Ans=China(f1, r1, f2, r2);
	Ans = Ans * Fx(Q(16,25));
	cout << Ans << endl;
	cout << Ans%f1 << endl;
	cout << Ans%f2 << endl;
	//cout << endl;
	//Fx f1(1, 0, 0, -4, 1), f2(1, 0, -3, 1);
	//cout << gcd(f1, f2) << endl;

	//Fx f3(-1, 0, 0, 1), f4(-1, 0, 0, 1, -1, 0, 0, 1);
	//cout << gcd(f3, f4) << endl;
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}