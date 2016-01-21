#include <iostream>
#include <string>
using namespace std;
#define DEBUG
/*没什么好说的*/
class ExamInfo{
private:
	string Name;
	enum{
		GRADE,
		PASS,
		PERCENTAGE
	}mode;		//采用何种计分方式
	union{
		char grade;
		bool pass;
		int percent;
	};
public:
	ExamInfo(string name, char grade):	Name(name), mode(GRADE), grade(grade){}
	ExamInfo(string name, bool pass):	Name(name), mode(PASS), pass(pass){}
	ExamInfo(string name, int percent):	Name(name), mode(PERCENTAGE), percent(percent){}
	void show()
	{
		/*for (int i = 0; Name[i] != '\0'; i++)
	     cout<<Name[i];
		 cout << ":";*/
		cout << Name <<":";
		switch (mode)
		{
		case GRADE:
			cout << grade<<endl;
			break;
		case PASS:
			cout << (pass ? "PASS" : "FAIL")<<endl;
			break;
		case PERCENTAGE:
			cout << percent<<endl;
			break;
		}
	}

};
int main()
{
#ifdef DEBUG
	FILE *err; //用来调用freopen_s，其实是没用的。
	freopen_s(&err, "in.txt", "r", stdin);
	freopen_s(&err, "out.txt", "w", stdout);
#endif

	ExamInfo course1("English", 'B');
	ExamInfo course2("Calculus", true);
	ExamInfo course3("C++ Programming", 85);
	course1.show();
	course2.show();
	course3.show();

#ifndef DEBUG
	printf("\n");
	system("pause");
#endif // !DEBUG
	return 0;
}