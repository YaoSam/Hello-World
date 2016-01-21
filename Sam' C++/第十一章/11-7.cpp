#include <iostream>
using namespace std;
int main(){
	ios_base::fmtflags original_flags=cout.flags();					//记录下原来cout的格式
	cout<<812<<'|';
	cout.setf(ios_base::left,ios_base::adjustfield);					//左对齐文本
	cout.width(10);																//对其的宽度设为10
	cout<<813<<815<<'\n';
	cout.unsetf(ios_base::adjustfield);									//清空格式。
	cout.precision(2);
	cout.setf(ios_base::uppercase|ios_base::scientific);			//设为科学计数法
	cout<<831.0;
	cout.flags(original_flags);												//恢复原来状态。
	cout << endl;
	system("pause");
	return 0;
}