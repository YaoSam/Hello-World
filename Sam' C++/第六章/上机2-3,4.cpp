#include <iostream>
#include <string>

using namespace std;

//#define DEBUG
#define Re(i,n)		for(int i=0;i<n;i++)
#define RE(n)			for(int I=0;I<n;I++)

/*����ע��
3. ����һ���������飬�ڷ�5��ѧ�������ݣ�ѧ�š��ɼ�������ָ��ָ����Ԫ�أ������1��3��5��ѧ�������ݡ�
4.����һ���������飬�ڷ�5��ѧ�������ݣ�ѧ�š��ɼ���������һ������max����ָ������ָ����������������max�������ҳ�5��ѧ���гɼ�����ߣ��������ѧ�š�
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
	cout << "�ɼ������Ϊ��";
	p[j].show();
	return j;
}



int main()
{
#ifdef DEBUG
	FILE *err; //��������freopen_s����ʵ��û�õġ�
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