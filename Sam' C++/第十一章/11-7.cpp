#include <iostream>
using namespace std;
int main(){
	ios_base::fmtflags original_flags=cout.flags();					//��¼��ԭ��cout�ĸ�ʽ
	cout<<812<<'|';
	cout.setf(ios_base::left,ios_base::adjustfield);					//������ı�
	cout.width(10);																//����Ŀ����Ϊ10
	cout<<813<<815<<'\n';
	cout.unsetf(ios_base::adjustfield);									//��ո�ʽ��
	cout.precision(2);
	cout.setf(ios_base::uppercase|ios_base::scientific);			//��Ϊ��ѧ������
	cout<<831.0;
	cout.flags(original_flags);												//�ָ�ԭ��״̬��
	cout << endl;
	system("pause");
	return 0;
}