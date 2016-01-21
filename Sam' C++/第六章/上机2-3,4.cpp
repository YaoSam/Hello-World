#include <iostream>
#include <string>

using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)
#define RE(n)			for(int I=0;I<n;I++)

/*程序注释
3. 建立一个对象数组，内放5个学生的数据（学号、成绩），用指针指向首元素，输出第1，3，5个学生的数据。
4.建立一个对象数组，内放5个学生的数据（学号、成绩），设立一个函数max，用指向对象的指针作函数参数，在max函数中找出5个学生中成绩最高者，并输出其学号。
*/
/*Sample Input:

*/
class student
{

	int ID, score;
	friend int max(student p[]); 
public:
	student(int id=10086, int s=0) :ID(id), score(s){}
	inline void show()
	{
		cout << "id:" << ID << " score: " << score << endl;
	}
};
int max(student p[])
{
	int j =0;
	Re(i, 5)if (p[j].score < p[i].score)j = i;
	cout << "成绩最高者为：";
	p[j].show();
	return j;
}



int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif
	student arr[5] = {student(1,2),student(2,3),student(3,4),student(4,5),student(5,6)};
	student *p = arr;
	for (int i = 0; i < 5; i += 2)(p + i)->show();
	max(p);
#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}