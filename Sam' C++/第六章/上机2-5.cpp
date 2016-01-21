#include <iostream>
#include <string>

using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)
#define RE(n)			for(int i=0;i<n;i++)

/*程序注释
5. 有5个学生，每个学生的数据包括学号、姓名、三门课成绩，从键盘输入5个学生的数据，要求计算并输出：
（1）每个学生三门课的总成绩
（2）三门课的每门课的平均成绩。
*/
/*Sample Input:
SamYao 14336238 100 99 98.9
BobYao 14336236 100.33 100 100.3
HalloWorld  12345678 60 70 80.3
*/
class stu{
	int id;
	string name;
	float score[3];
public:
	stu()
	{
		cout << "请输入学生的姓名，学号，还有3门科目的成绩："<<endl;
		cin >> name>>id;
		Re(i, 3)cin >> score[i];
	}
	float sum()
	{
		float Sum = 0;
		Re(i, 3)Sum += score[i];
		return Sum;
	}
};
int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	stu arr[3];
	Re(i, 3)cout << "总成绩为：" << arr[i].sum() << endl;
	Re(i, 3)cout << "平均成绩为" << arr[i].sum() / 3<<endl;
		
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}